<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<link href="<c:url value='/resources/css/include/nav.css' />" rel="stylesheet" type="text/css">

<nav>
	<div id="wrap_nav">
		<div class="menu_nav">
			<a href="<%=request.getContextPath()%>/streaming">| Streaming |</a>&nbsp;&nbsp;
			<a href="<%=request.getContextPath()%>/detectedList">| Detected List |</a>&nbsp;&nbsp;
			<a href="<%=request.getContextPath()%>/adminPage">| Admin Page |</a>
		</div>
	</div>
</nav>