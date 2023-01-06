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
</head>

<body>

	<%
	if (session.getAttribute("id") == null) {
		response.sendRedirect(request.getContextPath() + "/login");
	}
	%>

	<jsp:include page="./include/header_menu.jsp" />
	
	<jsp:include page="./include/nav.jsp" />
	
	<article>
		<div id="wrap_article">
			<div class="streaming">
				<img src="http://192.168.0.100:8081" width="640" height="480" />
        	</div>
		</div>
	
	</article>
	
	<jsp:include page="./include/footer.jsp" />
	
</body>

</html>