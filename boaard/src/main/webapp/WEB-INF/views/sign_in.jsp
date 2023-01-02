<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<link rel="icon" href="<c:url value='/resources/static/favicon.ico' />" type="image/x-icon" />
	<link href="<c:url value='/resources/css/common.css' />" rel="stylesheet" type="text/css">
	<link href="<c:url value='/resources/css/sign_in_up.css' />" rel="stylesheet" type="text/css">
	<jsp:include page="./include/title.jsp" />
	<jsp:include page="./include/common_js.jsp" />
	<jsp:include page="./include/sign_in_js.jsp" />
</head>
<body>
	
	<jsp:include page="./include/header.jsp" />
	
	<article>

		<div id="wrap_article">
			<div class="signIn">
				<div class="signInForm">
					<form action="<c:url value='/confirmSignIn' />" method="post" id="formSignIn">
						<input type="text" name="u_id" placeholder="ID" id="idSignIn"><br>
						<input type="password" name="u_pw" placeholder="Password" id="pwSignIn"><br>
						<input type="button" class="signInBtn" value="Sign In" id="btnSignIn">
					</form>
				</div>
				<div class="controlSignIn">
					<input type="button" class="signUpBtn" value="Sign Up" id="btnSignUp">
				</div>
			</div>
		</div>
	
	</article>
	
	<jsp:include page="./include/footer.jsp" />
	
</body>
</html>