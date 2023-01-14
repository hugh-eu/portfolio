<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>

<link href="<c:url value='/resources/admin/css/modify_form.css' />" rel="stylesheet" type="text/css" />
<jsp:include page="../../common/jquery_url.jsp" />
<jsp:include page="./js/modify_form_js.jsp" />

<div id="modify_form_wrap">
	<div class="modify_form">
	
		<div class="logo">
			비밀번호 수정
		</div>
		
		<form id="modify_form" name="modify_form">
			<div class="modify_form_text">
				<input type="hidden" name="u_no">
				비밀번호 <input type="password" class="pw" name="pw" placeholder="수정할 패스워드를 입력하세요."><br>
				비밀번호 확인 <input type="password" class="pw_confirm" name="pw_confirm" placeholder="패스워드를 다시한번 입력해주세요."><br>
			</div>
			<div class="modify_form_btn">
				<input type="button" class="modify_btn" name="modify" value="수정">
				<input type="reset" value="reset">
			</div>
		</form>
		
		<div class="close_div">
			<button class="close">닫기</button>
		</div>
		
	</div>
</div>
