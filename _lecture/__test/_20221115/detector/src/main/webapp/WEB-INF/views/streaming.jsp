<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>

<head>
	<meta charset="UTF-8">
	<title>Detector</title>
	<link href="<c:url value='/resources/css/common.css' />" rel="stylesheet" type="text/css">
</head>

<body>

	<%
	if (session.getAttribute("id") == null) {
		response.sendRedirect(request.getContextPath() + "/login");
	}
	%>

	<header>
		<div id="wrap_header">
			<div class="text_header">
				Detector
			</div>
			<div class="menu_header">
				<a href="<%=request.getContextPath()%>/logout">logout</a>
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
			<div class="streaming">
				<img src="http://192.168.0.100:8081" width="640" height="480" />
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