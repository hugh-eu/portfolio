<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>

<script type="text/javascript">

$(function() {
	
	add_modify_form_event();
	setModifyFormtHeight();
})

function add_modify_form_event() {
	console.log('add_modify_form_event()');
	
	/*닫기버튼 클릭*/
	$(document).on('click', '#modify_form_wrap .close', function() {
		console.log('close clicked');
		
		$('#modify_form')[0].reset();
		$('#modify_form_wrap').css('display', 'none');
	})
	
	/*수정 확인*/
	$(document).on('click', '#modify_form_wrap .modify_btn', function() {
		console.log('modify_btn clicked')
		
		let u_no = $('#modify_form input[name="u_no"]').val();
		var pw = $('#modify_form_wrap .pw').val();
		var pw_confirm = $('#modify_form_wrap .pw_confirm').val();
		
		if (pw == '') {
			
			alert('패스워드를 입력해주세요.');
			
		} else if (pw_confirm == '') {
			
			alert('패스워드 확인을 입력해주세요.');
			
		} else if (pw != pw_confirm) {
			
			alert('패스워드가 일치하지않습니다 다시 입력해주세요.');
			
		} else {
			
			modify_confirm(u_no, pw);
		}
	})
}

function modify_confirm(u_no, pw) {
	console.log('modify_confirm()')
	
	var msg = {
		'u_no': u_no,
		'u_pw': pw
	}
	
	$.ajax({
		url: '<c:url value="/admin/modify_pw_confirm" />',
		method: 'POST',
		data: msg,
		dataType : 'json',
		success : function(data) {
			console.log('modify_confirm() success')
			
			if (data.result == 'success') {
				
				alert('정상적으로 수정되었습니다.');
				$('#modify_form_wrap').css('display', 'none');
				
			} else {
				
				alert('다시 시도해주세요.');
				
			}
		},
		error: function(error) {
			
			console.log('modify_confirm() error : ' + error);
		}
	})
}

function setModifyFormtHeight() {
	console.log('setModifyFormtHeight()')
	
	let doc_height = $(document).height();
	$('#modify_form_wrap').css('height', doc_height);
}
</script>