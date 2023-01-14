<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>

<script type="text/javascript">

$(function() {
	
	ajax_getlicensePlateList();
	paging_event();
	add_licensePlate_events();
	$('#header_wrap a.licensePlate').parent().addClass('selected');
})

function sendForm() {
	console.log('sendForm()');
	
	let s_name = $('input[name="s_name"]').val();
	let s_info = $('input[name="s_info"]').val();
	
	if (s_name == '') {
		alert('등록할 번호판을 입력해주세요');
	} else if (s_info == '') {
		alert('등록할 번호판을 입력해주세요');
	} else {
		ajax_license_plate_regist(s_name, s_info);
	}
}

function ajax_license_plate_regist(s_name, s_info) {
	console.log('ajax_license_plate_regist()')
	
	let msg = {
		's_name': s_name,
		's_info': s_info
	}
	
	$.ajax({
		url: '<c:url value="/licensePlate/licensePlateRegistConfirm"/>',
		type: 'post',
		data: msg,
		dataType: 'json',
		success: function(data) {
			console.log('ajax_license_plate_regist() success');
			
			if (data.result == 'success') {
				
				alert('정상적으로 등록되었습니다.');
				$("input[type=text], input[type=password], input[type=email]").val("");
				ajax_getlicensePlateList();
				
			} else if (data.result == 'not_logined') {
				
				alert('로그인 후에 이용 가능합니다.');
				
			} else {
				
				alert('등록에 실패하였습니다.')
			}
		},
		error: function(data) {
			console.log('ajax_license_plate_regist() error');
			
		}
	});
}


function ajax_getlicensePlateList() {
	console.log('ajax_getlicensePlateList()');
	
	let msg = {
			'pageNum'			: getPageNum(),
			'amount'			: getAmount(),
			'u_no'				: $('input[name="u_no"]').val(),
			'order'				: $('select[name="set_order"]').val(),
			'licensePlateName'  : $('input[name="search_bar"]').val().trim()
	};
	
	$.ajax({
		url: '<c:url value="/licensePlate/getlicensePlateList" />',
		type: 'post',
		data : JSON.stringify(msg),
		contentType : 'application/json; charset=utf-8;', 
		dataType: 'json',
		success: function(data) {
			console.log('ajax_getlicensePlateList() success');
			console.log(data);
			
			let licensePlateVos = data.licensePlateVos;
			let pageMakerVo = data.pageMakerVo;
			
			$('#section_wrap .div_license_plate_list table tbody').remove();
			
			if (licensePlateVos != null) {
			
				for (let i = 0; i < licensePlateVos.length; i++) {
					
					let licensePlateVo = licensePlateVos[i];
					
					let s_no = licensePlateVo.s_no;
					let u_no = licensePlateVo.u_no;
					let s_name = licensePlateVo.s_name;
					let s_info = licensePlateVo.s_info;
					let s_reg_date = licensePlateVo.s_reg_date;
					let s_mod_date = licensePlateVo.s_mod_date;
					
					let t = document.querySelector('#licensePlate_item_list');
					let clone = document.importNode(t.content, true);
					let clone_tbody = clone.querySelector('tbody');
					$(clone_tbody).attr('id', s_no);
					$('.div_license_plate_list table').append(clone);
					
					/* UI */
					$('#' + s_no + ' td.s_no').text(s_no);
					$('#' + s_no + ' input[name="s_name"]').val(s_name);
					$('#' + s_no + ' td.s_name').append('<a class="delete_licensePlate_btn">삭제</a>');
					$('#' + s_no + ' input[name="s_info"]').val(s_info);
					$('#' + s_no + ' td.s_reg_date').text(s_reg_date);
					$('#' + s_no + ' td.s_mod_date').text(s_mod_date);
					
					/* DATA */
					$('#' + s_no + ' a.delete_licensePlate_btn').data('s_no', s_no);
					$('#' + s_no + ' a.delete_licensePlate_btn').data('s_name', s_name);
					$('#' + s_no + ' a.change_info_btn').data('s_no', s_no);
					$('#' + s_no + ' a.change_info_btn').data('cur_s_info', s_info);
				}
			
			}
			
			/* page UI */
			$('div.page_wrap > div.page_number').children().remove();
			
			/* 이전 페이지 */
			if (pageMakerVo.prev) {
				$('div.page_wrap > div.page_number').append('<a data-pagenum="' + (pageMakerVo.startPage - 1) + '">PREV</a>');
			}
			
			/* 처음 페이지 */
			if (getPageNum() > 10) {
				$('div.page_wrap > div.page_number').append('<a data-pagenum="1">1</a><span> ...... </span>');
			}
			
			/* 페이징 넘버링 */
			for (var p = parseInt(pageMakerVo.startPage); p <= parseInt(pageMakerVo.endPage); p++) {
				$('div.page_wrap > div.page_number').append('<a data-pagenum="' + p + '">' + p + '</a>');
			}

			$('div.page_wrap > div.page_number a[data-pagenum=' + getPageNum() + ']').addClass('selectedPageNum');
			
			/* 다음 페이지 */
			if (pageMakerVo.next) {
				$('div.page_wrap > div.page_number').append('<a data-pagenum="' + (pageMakerVo.endPage + 1) + '">NEXT</a>');
			}
			
			/* 전체 페이지 */
			$('div.page_wrap > div.page_goto > span.page_total_num').html(addComma(pageMakerVo.totalPage.toString()));
		},
		error: function(data) {
			console.log('ajax_getlicensePlateList() fail');
		}
	});
}

function paging_event() {
	console.log('paging_event()')
	
	/* 페이지 번호 클릭시 */
	$(document).on('click', 'div.page_wrap > div.page_number a', function() {
		console.log('page_number CLICK HANDLER')
		
		let pageNum = $(this).data('pagenum');
		setPageNum(pageNum);
		console.log('pageNum = ' + pageNum);
		
		ajax_getlicensePlateList();
	})
	
	/* 페이지 번호 입력시 */
	$(document).on('click', 'div.page_wrap > div.page_goto > a.goto_page_btn', function() {
		console.log('page_number BUTTON CLICK HANDLER')
		
		let targetPageNum = $('div.page_wrap > div.page_goto > input[name="page_target_num"]').val();
		let totalPageNum = $('div.page_wrap > div.page_goto > span.page_total_num').text();
		
		 if (targetPageNum == '' || targetPageNum == ' ' || targetPageNum == null) {
	         alert('이동하고자 하는 페이지 숫자를 입력하세요!!');
	         $('div.page_wrap > div.page_goto input[name="page_target_num"]').focus();
	         return;
	         
	      } else if (parseInt(targetPageNum) < 1) {
	         alert('1페이지 미만은 존재하지 않습니다!!');
	         $('div.page_wrap > div.page_goto input[name="page_target_num"]').val();
	         $('div.page_wrap > div.page_goto input[name="page_target_num"]').focus();
	         return;
	         
	      } else if (parseInt(targetPageNum) > parseInt(totalPageNum.replaceAll(',', ''))) {
	         alert(totalPageNum + '을(를) 초과 할수 없습니다!!');
	         $('div.page_wrap > div.page_goto input[name="page_target_num"]').val();
	         $('div.page_wrap > div.page_goto input[name="page_target_num"]').focus();
	         return;
	         
	      }
		
		setPageNum(targetPageNum);
		
		ajax_getlicensePlateList();
		
		$('div.page_wrap > div.page_goto input[name="page_target_num"]').val();
	})
}

function addComma(value) {
	
	if (value == null) return value;
	return value = value.replace(/\B(?=(\d{3})+(?!\d))/g, ",");
}

function add_licensePlate_events() {
	console.log('add_licensePlate_events()');
	
	/* 페이지당 불러올 번호판수 선택 */
	$(document).on('change', 'select[name="set_amount"]', function() {
		console.log('select[name="set_amount"] change');
		
		setAmount($(this).val());
		ajax_getlicensePlateList();
	})

	/* 차순 선택 */
	$(document).on('change', 'select[name="set_order"]', function() {
		console.log('select[name="set_order"] change');

		ajax_getlicensePlateList();
	})
	
	/* 번호판 삭제 클릭 */
	$(document).on('click', 'a.delete_licensePlate_btn', function() {
		console.log('delete_licensePlate_btn click');
		
		let s_no = $(this).data('s_no');
		let s_name = $(this).data('s_name');
		
		if (confirm(s_name + ' 해당 번호판 정보를 삭제 하시겠습니까?'))
			ajax_delete_licensePlate(s_no);
	})
	
	/* 번호판 내용 수정 클릭 */
	$(document).on('click', 'a.change_info_btn', function() {
		console.log('change_info_btn click');
		
		let s_no = $(this).data('s_no');
		let cur_s_info = $(this).data('cur_s_name');
		let mod_s_info = $(this).siblings('input[name="s_info"]').val();
		
		if (mod_s_info != '') {
			
			if (confirm('정말로 수정하시겠습니까?')) {

				ajax_modify_s_info(s_no, cur_s_info, mod_s_info);
				ajax_getlicensePlateList();
			}
		}
			
		else {
			
			alert('번호판 내용을 입력해주세요');
			$('#' + u_no + ' input[name="s_info"]').val(cur_s_info);
		}
	})
}

function ajax_delete_licensePlate(s_no) {
	console.log('ajax_delete_licensePlate()');
	
	var msg = {
		's_no'		: s_no
	};
	
	$.ajax({
		url: '<c:url value="/licensePlate/delete_licensePlate_confirm" />', 
		type: 'POST', 
		data: msg, 
		dataType: 'json',
		success: function(data) {
			console.log('ajax_delete_licensePlate() success');
			
			let result = data.result;
			if (result == 'success') {
				
				alert('정상적으로 삭제되었습니다.');
				ajax_getlicensePlateList();
				
			} else {
				alert('삭제에 실패하였습니다');
			}
			
		},
		error: function(data) {
			console.log('ajax_delete_licensePlate() fail');
		}
	});
}

function ajax_modify_s_info(no, cur_s_info, mod_s_info) {
	console.log('ajax_modify_s_info()');
	
	var msg = {
		's_no'		: no,
		's_info'	: mod_s_info
	};
	
	$.ajax({
		url: '<c:url value="/licensePlate/modify_licensePlate_confirm" />', 
		type: 'POST', 
		data: msg, 
		dataType: 'json',
		success: function(data) {
			console.log('ajax_modify_s_info() success');
			
			let result = data.result;
			if (result == 'success') {
				
				alert('번호판 내용이 정상적으로 수정되었습니다.');
				ajax_getlicensePlateList();
				
			} else {
				alert('번호판 내용 수정에 실패하였습니다.');
				$('#' + no + ' input[name="s_info"]').val(cur_s_info);
				
			}
			
		},
		error: function(data) {
			console.log('ajax_modify_s_info() fail');
			$('#' + no + ' input[name="s_info"]').val(cur_s_info);
		}
	});
}
</script>