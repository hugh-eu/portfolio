<<<<<<< HEAD
<%@page import="com.hugh.detector.vo.DetectorVo"%>
<%@page import="java.util.List"%>
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
	<link href="<c:url value='/resources/css/admin_page.css' />" rel="stylesheet" type="text/css">
</head>

<body>

	<%
	DetectorVo detectorVo = (DetectorVo)session.getAttribute("id");
	if (session.getAttribute("id") != null) {
		if (!detectorVo.getU_id().equals("admin")) {
	%>
		<script type="text/javascript">
		  	alert("권한 없음.");
		</script>
	<%
			response.sendRedirect(request.getContextPath() + "/streaming");
		}
	} else {
	%>
		<script type="text/javascript">
		  	alert("권한 없음.");
		</script>
	<%
		response.sendRedirect(request.getContextPath() + "/login");
	}
	%>

	<jsp:include page="./include/header_menu.jsp" />
	
	<jsp:include page="./include/nav.jsp" />
	
	<article>
		<div id="wrap_article">
			<div class="list">
				<table class="users" border="1">
	                <tr>
	                    <td>번호</td>
	                    <td>ID</td>
	                    <td>권한</td>
	                    <td>등록일</td>
	                    <td>수정일</td>
	                    <td>권한변경</td>
	                </tr>
	                <%
	                List<DetectorVo> detectorVos = (List<DetectorVo>)request.getAttribute("detectorVos");
	                for (DetectorVo vo : detectorVos) {
	                %>
	                <tr>
	                    <td><%=vo.getU_no()%></td>
	                    <td><%=vo.getU_id()%></td>
	                    <td><%=vo.getU_auth()%></td>
	                    <td><%=vo.getU_reg_date()%></td>
	                    <td><%=vo.getU_mod_date()%></td>
	                <%
	                	if (!vo.getU_id().equals("admin")) {
	                %>
	                	<td><a href="<%=request.getContextPath()%>/changeAuth?u_no=<%=vo.getU_no()%>&u_auth=<%=vo.getU_auth()%>">변경</a></td>
	                <%
	                	} else {
	                %>
	                	<td></td>
	                <%		
	                	}
	                %>
	                </tr>
	                <%
	                }
	                %>
	            </table>
			</div>
		</div>
	
	</article>
	
	<jsp:include page="./include/footer.jsp" />
	
</body>

=======
<<<<<<< HEAD
<%@page import="com.hugh.detector.vo.DetectorVo"%>
<%@page import="java.util.List"%>
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
	<link href="<c:url value='/resources/css/admin_page.css' />" rel="stylesheet" type="text/css">
</head>

<body>

	<%
	DetectorVo detectorVo = (DetectorVo)session.getAttribute("id");
	if (session.getAttribute("id") != null) {
		if (!detectorVo.getU_id().equals("admin")) {
	%>
		<script type="text/javascript">
		  	alert("권한 없음.");
		</script>
	<%
			response.sendRedirect(request.getContextPath() + "/streaming");
		}
	} else {
	%>
		<script type="text/javascript">
		  	alert("권한 없음.");
		</script>
	<%
		response.sendRedirect(request.getContextPath() + "/login");
	}
	%>

	<jsp:include page="./include/header_menu.jsp" />
	
	<jsp:include page="./include/nav.jsp" />
	
	<article>
		<div id="wrap_article">
			<div class="list">
				<table class="users" border="1">
	                <tr>
	                    <td>번호</td>
	                    <td>ID</td>
	                    <td>권한</td>
	                    <td>등록일</td>
	                    <td>수정일</td>
	                    <td>권한변경</td>
	                </tr>
	                <%
	                List<DetectorVo> detectorVos = (List<DetectorVo>)request.getAttribute("detectorVos");
	                for (DetectorVo vo : detectorVos) {
	                %>
	                <tr>
	                    <td><%=vo.getU_no()%></td>
	                    <td><%=vo.getU_id()%></td>
	                    <td><%=vo.getU_auth()%></td>
	                    <td><%=vo.getU_reg_date()%></td>
	                    <td><%=vo.getU_mod_date()%></td>
	                <%
	                	if (!vo.getU_id().equals("admin")) {
	                %>
	                	<td><a href="<%=request.getContextPath()%>/changeAuth?u_no=<%=vo.getU_no()%>&u_auth=<%=vo.getU_auth()%>">변경</a></td>
	                <%
	                	} else {
	                %>
	                	<td></td>
	                <%		
	                	}
	                %>
	                </tr>
	                <%
	                }
	                %>
	            </table>
			</div>
		</div>
	
	</article>
	
	<jsp:include page="./include/footer.jsp" />
	
</body>

=======
<%@page import="com.hugh.detector.vo.DetectorVo"%>
<%@page import="java.util.List"%>
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
	<link href="<c:url value='/resources/css/admin_page.css' />" rel="stylesheet" type="text/css">
</head>

<body>

	<%
	DetectorVo detectorVo = (DetectorVo)session.getAttribute("id");
	if (session.getAttribute("id") != null) {
		if (!detectorVo.getU_id().equals("admin")) {
	%>
		<script type="text/javascript">
		  	alert("권한 없음.");
		</script>
	<%
			response.sendRedirect(request.getContextPath() + "/streaming");
		}
	} else {
	%>
		<script type="text/javascript">
		  	alert("권한 없음.");
		</script>
	<%
		response.sendRedirect(request.getContextPath() + "/login");
	}
	%>

	<jsp:include page="./include/header_menu.jsp" />
	
	<jsp:include page="./include/nav.jsp" />
	
	<article>
		<div id="wrap_article">
			<div class="list">
				<table class="users" border="1">
	                <tr>
	                    <td>번호</td>
	                    <td>ID</td>
	                    <td>권한</td>
	                    <td>등록일</td>
	                    <td>수정일</td>
	                    <td>권한변경</td>
	                </tr>
	                <%
	                List<DetectorVo> detectorVos = (List<DetectorVo>)request.getAttribute("detectorVos");
	                for (DetectorVo vo : detectorVos) {
	                %>
	                <tr>
	                    <td><%=vo.getU_no()%></td>
	                    <td><%=vo.getU_id()%></td>
	                    <td><%=vo.getU_auth()%></td>
	                    <td><%=vo.getU_reg_date()%></td>
	                    <td><%=vo.getU_mod_date()%></td>
	                <%
	                	if (!vo.getU_id().equals("admin")) {
	                %>
	                	<td><a href="<%=request.getContextPath()%>/changeAuth?u_no=<%=vo.getU_no()%>&u_auth=<%=vo.getU_auth()%>">변경</a></td>
	                <%
	                	} else {
	                %>
	                	<td></td>
	                <%		
	                	}
	                %>
	                </tr>
	                <%
	                }
	                %>
	            </table>
			</div>
		</div>
	
	</article>
	
	<jsp:include page="./include/footer.jsp" />
	
</body>

>>>>>>> dfafe29c0482dd92cdc454a767f9bed240e80ae9
>>>>>>> 5aa76ea3a0591d427a636e8d726911934985e0b2
</html>