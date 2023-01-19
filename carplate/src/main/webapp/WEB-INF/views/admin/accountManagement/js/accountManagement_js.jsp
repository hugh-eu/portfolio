<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>

<script type="text/javascript">

$(function() {
	
	ajax_getUserList();
	paging_event();
	add_manage_events();
	$('#header_wrap a.accountManagement').parent().addClass('selected');
})

function ajax_getUserList() {
	console.log('ajax_getUserList()');
	
	let msg = {
		'pageNum'	: getPageNum(),
		'amount'	: getAmount()	
	};
	
	$.ajax({
		url: '<c:url value="/admin/getUserList" />',
		type: 'post',
		data : JSON.stringify(msg),
		contentType : 'application/json; charset=utf-8;', 
		dataType: 'json',
		success: function(data) {
			console.log('ajax_getUserList() success');
			console.log(data);
			
			let userVos = data.userVos;
			let pageMakerVo = data.pageMakerVo;
			
			$('#section_wrap .user_list table tbody').remove();
			
			for (let i = 0; i < userVos.length; i++) {
				
				let userVo = userVos[i];
				
				let u_no = userVo.u_no;
				let u_id = userVo.u_id;
				let u_pw = userVo.u_pw;
				let u_name = userVo.u_name;
				let u_mail = userVo.u_mail;
				let u_phone = userVo.u_phone;
				let u_reg_date = userVo.u_reg_date;
				let u_mod_date = userVo.u_mod_date;
				let a_no = userVo.a_no;
				
				let t = document.querySelector('#user_list_item');
				let clone = document.importNode(t.content, true);
				let clone_tbody = clone.querySelector('tbody');
				$(clone_tbody).attr('id', u_no);
				$('div.user_list table').append(clone);
				
				/* UI */
				$('#' + u_no + ' td.u_no').text(u_no);
				$('#' + u_no + ' td.u_id').text(u_id);
				$('#' + u_no + ' td.u_id').append('<br><a class="delete_account_btn">삭제</a>');
				$('#' + u_no + ' input[name="u_name"]').val(u_name);
				$('#' + u_no + ' input[name="u_mail"]').val(u_mail);
				$('#' + u_no + ' input[name="u_phone"]').val(u_phone);
				$('#' + u_no + ' td.u_reg_date').text(u_reg_date);
				$('#' + u_no + ' td.u_mod_date').text(u_mod_date);
				$('#' + u_no + ' select[name="a_no"]').val(a_no).prop('selected', true);
				
				/* DATA */
				$('#' + u_no + ' a.delete_account_btn').data('u_no', u_no);
				$('#' + u_no + ' a.delete_account_btn').data('u_id', u_id);
				$('#' + u_no + ' a.change_pw_btn').data('u_no', u_no);
				$('#' + u_no + ' a.change_name_btn').data('u_no', u_no);
				$('#' + u_no + ' a.change_name_btn').data('cur_u_name', u_name);
				$('#' + u_no + ' a.change_email_btn').data('u_no', u_no);
				$('#' + u_no + ' a.change_email_btn').data('cur_u_mail', u_mail);
				$('#' + u_no + ' a.change_phone_btn').data('u_no', u_no);
				$('#' + u_no + ' a.change_phone_btn').data('cur_u_phone', u_phone);
				$('#' + u_no + ' select[name="a_no"]').data('u_no', u_no);
				$('#' + u_no + ' select[name="a_no"]').data('cur_a_no', a_no);
			}
			
			/* page UI */
			$('#section_wrap div.page_wrap > div.page_number').children().remove();
			
			/* 이전 페이지 */
			if (pageMakerVo.prev) {
				$('#section_wrap div.page_wrap > div.page_number').append('<a data-pagenum="' + (pageMakerVo.startPage - 1) + '">PREV</a>');
			}
			
			/* 처음 페이지 */
			if (getPageNum() > 10) {
				$('#section_wrap div.page_wrap > div.page_number').append('<a data-pagenum="1">1</a><span> ...... </span>');
			}
			
			/* 페이징 넘버링 */
			for (var p = parseInt(pageMakerVo.startPage); p <= parseInt(pageMakerVo.endPage); p++) {
				$('#section_wrap div.page_wrap > div.page_number').append('<a data-pagenum="' + p + '">' + p + '</a>');
			}

			$('#section_wrap div.page_wrap > div.page_number a[data-pagenum=' + getPageNum() + ']').addClass('selectedPageNum');
			
			/* 다음 페이지 */
			if (pageMakerVo.next) {
				$('#section_wrap div.page_wrap > div.page_number').append('<a data-pagenum="' + (pageMakerVo.endPage + 1) + '">NEXT</a>');
			}
			
			/* 전체 페이지 */
			$('#section_wrap div.page_wrap > div.page_goto > span.page_total_num').html(addComma(pageMakerVo.totalPage.toString()));
		},
		error: function(data) {
			console.log('ajax_getUserList() fail');
		}
	});
	
}

function ajax_getUserList_by_name(u_name) {
	console.log('ajax_getUserList()');
	
	let msg = {
		'pageNum'	: getPageNum(),
		'amount'	: getAmount(),
		'u_name'	: u_name
	};
	
	$.ajax({
		url: '<c:url value="/admin/getUserListByName" />',
		type: 'post',
		data : JSON.stringify(msg),
		contentType : 'application/json; charset=utf-8;', 
		dataType: 'json',
		success: function(data) {
			console.log('ajax_getUserList() success');
			console.log(data);
			
			let userVos = data.userVos;
			let pageMakerVo = data.pageMakerVo;
			
			if (userVos != null) {
			
				$('#section_wrap .user_list table tbody').remove();
				
				for (let i = 0; i < userVos.length; i++) {
					
					let userVo = userVos[i];
					
					let u_no = userVo.u_no;
					let u_id = userVo.u_id;
					let u_pw = userVo.u_pw;
					let u_name = userVo.u_name;
					let u_mail = userVo.u_mail;
					let u_phone = userVo.u_phone;
					let u_reg_date = userVo.u_reg_date;
					let u_mod_date = userVo.u_mod_date;
					let a_no = userVo.a_no;
					let a_auth_info = userVo.a_auth_info;
					let a_reg_date = userVo.a_reg_date;
					let a_mod_date = userVo.a_mod_date;
					
					let t = document.querySelector('#user_list_item');
					let clone = document.importNode(t.content, true);
					let clone_tbody = clone.querySelector('tbody');
					$(clone_tbody).attr('id', u_no);
					$('div.user_list table').append(clone);
					
					/* UI */
					$('#' + u_no + ' td.u_no').text(u_no);
					$('#' + u_no + ' td.u_id').text(u_id);
					$('#' + u_no + ' td.u_id').append('<br><a class="delete_account_btn">삭제</a>');
					$('#' + u_no + ' input[name="u_name"]').val(u_name);
					$('#' + u_no + ' input[name="u_mail"]').val(u_mail);
					$('#' + u_no + ' input[name="u_phone"]').val(u_phone);
					$('#' + u_no + ' td.u_reg_date').text(u_reg_date);
					$('#' + u_no + ' td.u_mod_date').text(u_mod_date);
					$('#' + u_no + ' select[name="a_no"]').val(a_no).prop('selected', true);
					$('#' + u_no + ' td.a_auth_info').text(a_auth_info);
					$('#' + u_no + ' td.a_reg_date').text(a_reg_date);
					$('#' + u_no + ' td.a_mod_date').text(a_mod_date);
					
					/* DATA */
					$('#' + u_no + ' a.delete_account_btn').data('u_no', u_no);
					$('#' + u_no + ' a.delete_account_btn').data('u_id', u_id);
					$('#' + u_no + ' a.change_pw_btn').data('u_no', u_no);
					$('#' + u_no + ' a.change_name_btn').data('u_no', u_no);
					$('#' + u_no + ' a.change_name_btn').data('cur_u_name', u_name);
					$('#' + u_no + ' a.change_email_btn').data('u_no', u_no);
					$('#' + u_no + ' a.change_email_btn').data('cur_u_mail', u_mail);
					$('#' + u_no + ' a.change_phone_btn').data('u_no', u_no);
					$('#' + u_no + ' a.change_phone_btn').data('cur_u_phone', u_phone);
					$('#' + u_no + ' select[name="a_no"]').data('u_no', u_no);
					$('#' + u_no + ' select[name="a_no"]').data('cur_a_no', a_no);
				}
				
				/* page UI */
				$('#section_wrap div.page_wrap > div.page_number').children().remove();
				
				/* 이전 페이지 */
				if (pageMakerVo.prev) {
					$('#section_wrap div.page_wrap > div.page_number').append('<a data-pagenum="' + (pageMakerVo.startPage - 1) + '">PREV</a>');
				}
				
				/* 처음 페이지 */
				if (getPageNum() > 10) {
					$('#section_wrap div.page_wrap > div.page_number').append('<a data-pagenum="1">1</a><span> ...... </span>');
				}
				
				/* 페이징 넘버링 */
				for (var p = parseInt(pageMakerVo.startPage); p <= parseInt(pageMakerVo.endPage); p++) {
					$('#section_wrap div.page_wrap > div.page_number').append('<a data-pagenum="' + p + '">' + p + '</a>');
				}
	
				$('#section_wrap div.page_wrap > div.page_number a[data-pagenum=' + getPageNum() + ']').addClass('selectedPageNum');
				
				/* 다음 페이지 */
				if (pageMakerVo.next) {
					$('#section_wrap div.page_wrap > div.page_number').append('<a data-pagenum="' + (pageMakerVo.endPage + 1) + '">NEXT</a>');
				}
				
				/* 전체 페이지 */
				$('#section_wrap div.page_wrap > div.page_goto > span.page_total_num').html(addComma(pageMakerVo.totalPage.toString()));
			} else {
				alert("입력한 이름과 일치하는 정보가 없습니다.")
				
				$("#section_wrap .accountManagement_wrap input[name=user_search_by_name]").val("");
				$("#section_wrap .accountManagement_wrap input[name=user_search_by_name]").focus();
				
			}
		},
		error: function(data) {
			console.log('ajax_getUserList() fail');
		}
	});
	
}

function paging_event() {
	console.log('paging_event()')
	
	/* 페이지 번호 클릭시 */
	$(document).on('click', '#section_wrap div.page_wrap > div.page_number a', function() {
		console.log('page_number CLICK HANDLER')
		
		let pageNum = $(this).data('pagenum');
		setPageNum(pageNum);
		console.log('pageNum = ' + pageNum);
		
		getUserList();
	})
	
	/* 페이지 번호 입력시 */
	$(document).on('click', '#section_wrap div.page_wrap > div.page_goto > a.goto_page_btn', function() {
		console.log('page_number BUTTON CLICK HANDLER')
		
		let targetPageNum = $('#section_wrap div.page_wrap > div.page_goto > input[name="page_target_num"]').val();
		let totalPageNum = $('#section_wrap div.page_wrap > div.page_goto > span.page_total_num').text();
		
		 if (targetPageNum == '' || targetPageNum == ' ' || targetPageNum == null) {
	         alert('이동하고자 하는 페이지 숫자를 입력하세요!!');
	         $('#section_wrap div.page_wrap > div.page_goto input[name="page_target_num"]').focus();
	         return;
	         
	      } else if (parseInt(targetPageNum) < 1) {
	         alert('1페이지 미만은 존재하지 않습니다!!');
	         $('#section_wrap div.page_wrap > div.page_goto input[name="page_target_num"]').val();
	         $('#section_wrap div.page_wrap > div.page_goto input[name="page_target_num"]').focus();
	         return;
	         
	      } else if (parseInt(targetPageNum) > parseInt(totalPageNum.replaceAll(',', ''))) {
	         alert(totalPageNum + '을(를) 초과 할수 없습니다!!');
	         $('#section_wrap div.page_wrap > div.page_goto input[name="page_target_num"]').val();
	         $('#section_wrap div.page_wrap > div.page_goto input[name="page_target_num"]').focus();
	         return;
	         
	      }
		
		setPageNum(targetPageNum);
		
		getUserList();
		
		$('#section_wrap div.page_wrap > div.page_goto input[name="page_target_num"]').val();
	})
}

function addComma(value) {
	
	if (value == null) return value;
	return value = value.replace(/\B(?=(\d{3})+(?!\d))/g, ",");
}

function add_manage_events() {
	console.log('add_manage_events()');
	
	/* 페이지당 불러올 유저수 선택 */
	$(document).on('change', 'select[name="set_amount"]', function() {
		console.log('select[name="set_amount"] change');
		
		setAmount($(this).val());
		getUserList();
	})
	
	/* 계정 삭제 클릭 */
	$(document).on('click', 'a.delete_account_btn', function() {
		console.log('delete_account_btn click');
		
		let u_no = $(this).data('u_no');
		let u_id = $(this).data('u_id');
		
		if (confirm(u_id + ' 계정을 삭제 하시겠습니까?'))
			if (confirm('정말로 삭제하시겠습니까?'))
				ajax_delete_user(u_no);
	})
	
	/* 비밀번호 변경 클릭 */
	$(document).on('click', 'a.change_pw_btn', function() {
		console.log('change_pw_btn click');
		
		let u_no = $(this).data('u_no')
		$('#modify_form input[name="u_no"]').val(u_no);
		$('#modify_form_wrap').css('display', 'block');
	})
	
	/* 이름 변경 클릭 */
	$(document).on('click', 'a.change_name_btn', function() {
		console.log('change_name_btn click');
		
		let u_no = $(this).data('u_no');
		let cur_u_name = $(this).data('cur_u_name');
		let mod_u_name = $(this).siblings('input[name="u_name"]').val();
		
		if (mod_u_name != '') {
			
			if (confirm(mod_u_name + '으로 변경하시겠습니까?')) {

				ajax_modify_u_name(u_no, cur_u_name, mod_u_name);
				getUserList();

			} else {

				$('#' + u_no + ' input[name="u_name"]').val(cur_u_name);
			}
		}
			
		else {
			
			alert('이름을 입력해주세요')
			$('#' + u_no + ' input[name="u_name"]').val(cur_u_name);
			
		}
	})
	
	/* 이메일 변경 클릭 */
	$(document).on('click', 'a.change_email_btn', function() {
		console.log('change_email_btn click');
		
		let u_no = $(this).data('u_no');
		let cur_u_mail = $(this).data('cur_u_mail');
		let mod_u_mail = $(this).siblings('input[name="u_mail"]').val();
		
		if (mod_u_mail != '') {
			
			if (confirm(mod_u_mail + '으로 변경하시겠습니까?')) {

				ajax_modify_u_mail(u_no, cur_u_mail, mod_u_mail);
				getUserList();

			} else {

				$('#' + u_no + ' input[name="u_mail"]').val(cur_u_mail);
			}
		}
			
		else {
			
			alert('이메일를 입력해주세요')
			$('#' + u_no + ' input[name="u_mail"]').val(cur_u_mail);
			
		}
	})
	
	/* 전화번호 변경 클릭 */
	$(document).on('click', 'a.change_phone_btn', function() {
		console.log('change_phone_btn click');
		
		let u_no = $(this).data('u_no');
		let cur_u_phone = $(this).data('cur_u_phone');
		let mod_u_phone = $(this).siblings('input[name="u_phone"]').val();
		
		if (mod_u_phone != '') {
			
			if (confirm(mod_u_phone + '으로 변경하시겠습니까?')) {

				ajax_modify_u_phone(u_no, cur_u_phone, mod_u_phone);
				getUserList();

			} else {

				$('#' + u_no + ' input[name="u_phone"]').val(cur_u_phone);
			}
		}
			
		else {
			
			alert('전화번호를 입력해주세요')
			$('#' + u_no + ' input[name="u_phone"]').val(cur_u_phone);
		}
	})
	
	/* 권한 내용 선택 */
	$(document).on('change', 'select[name="a_no"]', function() {
		console.log('select[name="a_no"] change');
		
		let u_no = $(this).data('u_no');
		let cur_a_no = $(this).data('cur_a_no');
		let mod_a_no = $(this).val();
		
		let result = confirm('사용자 권한을 변경 하시겠습니까?');
		
		if (result)
			
			if (mod_a_no == 1) {
				
				alert('해당 권한으로는 변경할 수 없습니다.');
				$(this).val(cur_a_no).prop('selected', true);
			}
			else {
				
				ajax_modify_a_no(u_no, cur_a_no, mod_a_no);
				getUserList();
			}
		
		else {
			
			$(this).val(cur_a_no).prop('selected', true);
			
		}
	})
	
	/* 이름찾기 클릭 */
	$(document).on('click', 'input[name="search_bar_btn"]', function() {
		console.log('search_bar_btn click');
		
		getUserList();
	})
	
}

function getUserList() {
	console.log('getUserList()');
	
	let u_name = $('#section_wrap .search_bar input[name="user_search_by_name"]').val();
	
	console.log(u_name);
	
	if (u_name != '')
		
		ajax_getUserList_by_name(u_name);
	
	else {
		
		ajax_getUserList();
		
	}
}

function ajax_delete_user(no) {
	console.log('ajax_delete_user()');
	
	var msg = {
		'u_no'		: no
	};
	
	$.ajax({
		url: '<c:url value="/admin/delete_user_confirm" />', 
		type: 'POST', 
		data: msg, 
		dataType: 'json',
		success: function(data) {
			console.log('AJAX SUCCESS - ajax_delete_user()');
			
			let u_name = $('input[name="user_search_by_name"]').val();
			let result = data.result;
			if (result == 'success') {
				
				alert('정상적으로 삭제되었습니다.');
				getUserList();
				
			} else {
				alert('삭제에 실패하였습니다');
			}
			
		},
		error: function(data) {
			console.log('AJAX FAIL - ajax_delete_user()');
		}
	});
}

function ajax_modify_u_name(no, cur_u_name, mod_u_name) {
	console.log('ajax_modify_u_name()');
	
	var msg = {
		'u_no'		: no,
		'u_name'	: mod_u_name
	};
	
	$.ajax({
		url: '<c:url value="/admin/modify_name_confirm" />', 
		type: 'POST', 
		data: msg, 
		dataType: 'json',
		success: function(data) {
			console.log('AJAX SUCCESS - ajax_updateM_mail()');
			
			let result = data.result;
			if (result == 'success') {
				
				alert('이름이 정상적으로 수정되었습니다.');
				getUserList();
				
			} else {
				alert('이름 수정에 실패하였습니다.');
				$('#' + no + ' input[name="u_name"]').val(cur_u_name);
				
			}
			
		},
		error: function(data) {
			console.log('AJAX FAIL - ajax_updateM_mail()');
			$('#' + no + ' input[name="u_name"]').val(cur_u_name);
		}
	});
}

function ajax_modify_u_mail(no, cur_u_mail, mod_u_mail) {
	console.log('ajax_modify_u_mail()');
	
	var msg = {
		'u_no'		: no,
		'u_mail'	: mod_u_mail
	};
	
	$.ajax({
		url: '<c:url value="/admin/modify_mail_confirm" />', 
		type: 'POST', 
		data: msg, 
		dataType: 'json',
		success: function(data) {
			console.log('AJAX SUCCESS - ajax_modify_u_mail()');
			
			let result = data.result;
			if (result == 'success') {
				
				alert('이메일이 정상적으로 수정되었습니다.');
				getUserList();
				
			} else {
				alert('이메일 수정에 실패하였습니다.');
				$('#' + no + ' input[name="u_mail"]').val(cur_u_mail);
				
			}
			
		},
		error: function(data) {
			console.log('AJAX FAIL - ajax_modify_u_mail()');
			$('#' + no + ' input[name="u_mail"]').val(cur_u_mail);
		}
	});
}

function ajax_modify_u_phone(no, cur_u_phone, mod_u_phone) {
	console.log('ajax_modify_u_phone()');
	
	var msg = {
		'u_no'		: no,
		'u_phone'	: mod_u_phone
	};
	
	$.ajax({
		url: '<c:url value="/admin/modify_phone_confirm" />', 
		type: 'POST', 
		data: msg, 
		dataType: 'json',
		success: function(data) {
			console.log('AJAX SUCCESS - ajax_modify_u_phone()');
			
			let result = data.result;
			if (result == 'success') {
				
				alert('전화번호가 정상적으로 수정되었습니다.');
				getUserList();
				
			} else {
				alert('전화번호 수정에 실패하였습니다.');
				$('#' + no + ' input[name="u_phone"]').val(cur_u_phone);
				
			}
			
		},
		error: function(data) {
			console.log('AJAX FAIL - ajax_modify_u_phone()');
			$('#' + no + ' input[name="u_phone"]').val(cur_u_phone);
		}
	});
}

function ajax_modify_a_no(no, cur_a_no, mod_a_no) {
	console.log('ajax_modify_u_phone()');
	
	var msg = {
		'u_no'		: no,
		'a_no'		: mod_a_no
	};
	
	$.ajax({
		url: '<c:url value="/admin/modify_auth_confirm" />', 
		type: 'POST', 
		data: msg, 
		dataType: 'json',
		success: function(data) {
			console.log('AJAX SUCCESS - ajax_modify_a_no()');
			
			let result = data.result;
			if (result == 'success') {
				
				alert('권한이 정상적으로 수정되었습니다.');
				getUserList();
				
			} else {
				alert('권한 수정에 실패하였습니다.');
				$(this).val(cur_a_no).prop('selected', true);
				
			}
			
		},
		error: function(data) {
			console.log('AJAX FAIL - ajax_modify_u_phone()');
			$(this).val(cur_a_no).prop('selected', true);
		}
	});
}

</script>
