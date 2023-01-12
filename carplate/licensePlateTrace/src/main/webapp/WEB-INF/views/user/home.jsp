<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE html>
<html>
<head>
	<jsp:include page="../common/title.jsp" />
	
	<link href="<c:url value='/resources/common/css/common.css' />"rel="stylesheet" type="text/css" />
	<link href="<c:url value='/resources/user/css/home.css' />" rel="stylesheet" type="text/css" />
	
	<jsp:include page="../common/jquery_url.jsp" />
	<jsp:include page="./js/home_js.jsp" />
</head>


<body>

	<jsp:include page="../common/header.jsp" />
	
	<section>
		<div id="section_wrap">
			메인 페이지
		</div>
	</section>

	<jsp:include page="../common/footer.jsp" />

</body>
</html>