<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>

<script type="text/javascript">

$(function() {

	$('#header_wrap a.home').parent().addClass('selected');
	set_regist_wrap_height();
	login_events();
})

function login_events() {
	
    $(window).resize(function() {
        
    	set_regist_wrap_height();
    });
}

function set_regist_wrap_height() {
	
	$('#regist_form_wrap').css('height', $(window).height());
}

function login_confirm() {
	console.log('login_confirm()');
	
	let id  = $('#section_wrap form[name="login_form"] input[name="input_id"]').val();
	let pw  = $('#section_wrap form[name="login_form"] input[name="input_pw"]').val();
	
	if (id == '') {
		alert('아이디를 입력해주세요');
		
	} else if (pw == '') {
		alert('아이디를 입력해주세요');
		
	} else {
		ajax_login_confirm(id, pw);
	}
}

function ajax_login_confirm(id, pw) {
	console.log('ajax_login_confirm()');
	
	let msg = {
			'u_id': id,
			'u_pw': pw
	}
		
	$.ajax({
		url: '<c:url value="/user/login_confirm"/>',
		type : 'post',
		data : msg,
		dataType : 'json',
		success: function(data) {
			console.log('ajax_login_confirm() success')
			
			if (data.result == 'success') {
				
				location.href='<c:url value="/"/>';
				
			} else if (data.result == 'not_exists') {
				
				alert('존재하지 않는 계정입니다.')
				
			} else {
				
				alert('비밀번호를 다시 입력해주세요.')
			}
			
		},
		error: function(data) {
			
			console.log('ajax_login_confirm() error')
		}
	});
}

function regist_form_on() {
	console.log('regist_form_on()');
	
	$('#regist_form_wrap').css('display', 'block');
}

function regist_form_off() {
	console.log('regist_form_off()');
	
	$('#regist_form_wrap').css('display', 'none');
}

function regist_confirm() {
	console.log('regist_confirm()');
	
	let id  = $('#regist_form_wrap form[name="regist_form"] input[name="input_id"]').val();
	let pw  = $('#regist_form_wrap form[name="regist_form"] input[name="input_pw"]').val();
	let name  = $('#regist_form_wrap form[name="regist_form"] input[name="input_name"]').val();
	let mail  = $('#regist_form_wrap form[name="regist_form"] input[name="input_mail"]').val();
	let phone  = $('#regist_form_wrap form[name="regist_form"] input[name="input_phone"]').val();
	
	if (id == '') {
		alert('아이디를 입력해주세요.');
		
	} else if (pw == '') {
		alert('패스워드를 입력해주세요.');
		
	} else if (name == '') {
		alert('이름을 입력해주세요.');
	
	} else if (mail == '') {
		alert('메일주소를 입력해주세요.');
	
	} else if (phone == '') {
		alert('연락처를 입력해주세요.');
		
	} else {
		ajax_regist_confirm(id, pw, name, mail, phone);
	}
}

function ajax_regist_confirm(id, pw, name, mail, phone) {
	console.log('ajax_regist_confirm()');
	
	let msg = {
		'u_id': id,
		'u_pw': pw,
		'u_name': name,
		'u_mail': mail,
		'u_phone': phone
	};
	
	console.log(msg)
		
	$.ajax({
		url: '<c:url value="/user/regist_confirm"/>',
		type : 'post',
		data : msg,
		dataType : 'json',
		success: function(data) {
			console.log('ajax_regist_confirm() success')
			
			if (data.result == 'success') {
				
				alert('정상적으로 등록되었습니다. 관리자 승인 후 이용 가능합니다.');
				
			} else if (data.result == 'already_exists') {
				
				alert('이미 등록된 계정입니다.')
				
			} else {
				
				alert('등록에 실패하였습니다. 다시 시도해주세요')
			}
			
		},
		error: function(data) {
			console.log('ajax_regist_confirm() error')
			
		}
	});
}
</script>
