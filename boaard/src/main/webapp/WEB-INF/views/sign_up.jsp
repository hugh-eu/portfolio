<<<<<<< HEAD
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
	<jsp:include page="./include/sign_up_js.jsp" />
</head>
<body>
	
	<jsp:include page="./include/header.jsp" />
	
	<article>
	
		<div id="wrap_article">
			<div class="signUp">
				<div class="signUpForm">
					<form action="<c:url value='/confirmSignUp' />" method="post" id="formSignUp">
						<input type="text" name="u_id" placeholder="ID" id="idSignUp"><br>
						<input type="password" name="u_pw" placeholder="Password" id="pwSignUp"><br>
						<input type="email" name="u_email" placeholder="Emali" id="emailSignUp"><br>
						<input type="button" class="signUpSubmit" value="Submit" id="submitSignUp">
					</form>
				</div>
				<div class="controllSignUp">
					<input type="button" class="signUpCancel" value="Cancel" id="cancelSignUp">
				</div>
			</div>
		</div>
	
	</article>
	
	<jsp:include page="./include/footer.jsp" />
	
</body>
=======
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
	<jsp:include page="./include/sign_up_js.jsp" />
</head>
<body>
	
	<jsp:include page="./include/header.jsp" />
	
	<article>
	
		<div id="wrap_article">
			<div class="signUp">
				<div class="signUpForm">
					<form action="<c:url value='/confirmSignUp' />" method="post" id="formSignUp">
						<input type="text" name="u_id" placeholder="ID" id="idSignUp"><br>
						<input type="password" name="u_pw" placeholder="Password" id="pwSignUp"><br>
						<input type="email" name="u_email" placeholder="Emali" id="emailSignUp"><br>
						<input type="button" class="signUpSubmit" value="Submit" id="submitSignUp">
					</form>
				</div>
				<div class="controllSignUp">
					<input type="button" class="signUpCancel" value="Cancel" id="cancelSignUp">
				</div>
			</div>
		</div>
	
	</article>
	
	<jsp:include page="./include/footer.jsp" />
	
</body>
>>>>>>> 5aa76ea3a0591d427a636e8d726911934985e0b2
</html>