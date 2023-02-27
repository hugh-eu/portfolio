<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>

<head>
	<meta charset="UTF-8">
	<title>Detector</title>
	<link href="<c:url value='/resources/css/common.css' />" rel="stylesheet" type="text/css">
	<link href="<c:url value='/resources/css/sign_up.css' />" rel="stylesheet" type="text/css">
</head>

<body>

	<header>
		<div id="wrap_header">
			<div class="text_header">
				Detector
			</div>
		</div>
	</header>
	
	<nav>
		<div id="wrap_nav">
			<div class="menu_nav">
				<a href="<%=request.getContextPath()%>/streaming">| Streaming |</a>&nbsp;&nbsp;
				<a href="<%=request.getContextPath()%>/detectedList">| Detected List |</a>&nbsp;&nbsp;
				<a href="<%=request.getContextPath()%>/adminPage">| Admin Page |</a>
			</div>
		</div>
	</nav>
	
	<article>
		<div id="wrap_article">
        	<div class="signUpText">
                회원가입양식
            </div>
			<div class="signUpForm">
				<form action="<%=request.getContextPath()%>/signUpConfirm" method="post" name="signUpForm">
                    <input type="text" name="u_id" placeholder="아이디"><br>
                    <input type="text" name="u_pw" placeholder="비밀번호"><br>
                    <input type="submit" value="제출">
                </form>
        	</div>
		</div>
	
	</article>
	
	<footer>
		<div id="wrap_footer">
			<div class="copyright">
				Copyright(c) Hugh All rights reserved.
			</div>
		</div>
	</footer>
	
</body>

</html>