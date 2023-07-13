<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>

<head>
	<meta charset="UTF-8">
	<jsp:include page="./include/title.jsp" />
	<link href="<c:url value='/resources/css/common.css' />" rel="stylesheet" type="text/css">
	<link href="<c:url value='/resources/css/include/article.css' />" rel="stylesheet" type="text/css">
	<link href="<c:url value='/resources/css/login.css' />" rel="stylesheet" type="text/css">
</head>

<body>

	<jsp:include page="./include/header.jsp" />
	
	<jsp:include page="./include/nav.jsp" />
	
	<article>
		<div id="wrap_article">
			<div class="loginForm">
				<form action="<%=request.getContextPath()%>/loginConfirm" method="post" name="loginForm">
                    <input type="text" name="u_id" placeholder="아이디"><br>
                    <input type="text" name="u_pw" placeholder="비밀번호"><br>
                    <input type="submit" value="로그인">
                </form>
        	</div>
        	<div class="signUpMenu">
                <a href="<%=request.getContextPath()%>/signUp">회원가입</a>
            </div>
		</div>
	
	</article>
	
	<jsp:include page="./include/footer.jsp" />
	
</body>

</html>