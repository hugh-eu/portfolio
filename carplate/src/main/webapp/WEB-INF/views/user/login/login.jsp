<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>

<!DOCTYPE html>
<html>
<head>
	<jsp:include page="../../common/title.jsp" />
	
	<link href="<c:url value='/resources/common/css/common.css' />"rel="stylesheet" type="text/css" />
	<link href="<c:url value='/resources/user/css/login.css' />" rel="stylesheet" type="text/css" />
	
	<jsp:include page="../../common/jquery_url.jsp" />
	<jsp:include page="./js/login_js.jsp" />
</head>

<body>

	<jsp:include page="../../common/header.jsp" />

	<section>
		<div id="section_wrap">
			<div class="login">
			
				<div class="logo">
					<a href="<c:url value="/" />">
						<img src="<c:url value="/resources/common/img/licensePlateTrace.jpg"/>">
						License Plate Trace
					</a>
				</div>
				
				<div class="word">
					로그인
				</div>
			
				<div class="login_form_wrap">
					<form name="login_form" class="login_form">
					
						<div class="regist_form_text">
							<input type="text" name="input_id" placeholder="아이디를 입력해주세요.">
							<input type="password" name="input_pw" placeholder="패스워드를 입력해주세요." onkeydown="if(window.event.keyCode==13)login_confirm()">
						</div>
							
						<div class="regist_form_btn">
							<input type="button" name="login_btn" value="로그인" onclick="login_confirm();">
							<input type="button" name="regist_forn_on_btn" value="계정등록" onclick="regist_form_on();">
						</div>
						
					</form>
				</div>
				
			</div>
			
			<div id="regist_form_wrap">
				<div class="div_regist_form_wrap">
				
					<div class="logo">
						계정 등록
					</div>
					
					<div class="div_regist_form">
						<form name="regist_form" class="regist_form">
						
							<div class="regist_form_text">
								<input type="text" name="input_id" placeholder="아이디를 입력하세요.">
								<input type="password" name="input_pw" placeholder="패스워드를 입력하세요.">
								<input type="text" name="input_name" placeholder="이름을 입력하세요.">
								<input type="email" name="input_mail" placeholder="메일을 입력하세요.">
								<input type="text" name="input_phone" placeholder="연락처를 입력하세요." onkeydown="if(window.event.keyCode==13)regist_confirm()">
							</div>
							
							<div class="regist_form_btn">
								<input type="button" class="regist_btn" value="등록" onclick="regist_confirm();">
								<input type="reset" value="초기화">
							</div>
							
						</form>
					</div>
					
					<div class="div_close">
						<button class="close" onclick="regist_form_off();">닫기</button>
					</div>
					
				</div>
			</div>
			
		</div>
		
	<jsp:include page="../../common/footer.jsp" />
	</section>
	
	
</body>
</html>