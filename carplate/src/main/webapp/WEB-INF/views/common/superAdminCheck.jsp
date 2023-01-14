<%@page import="com.group1.licensePlateTrace.vo.UserVo"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>

<%
UserVo userVo = (UserVo)session.getAttribute("userVo");
%>

<%
if (userVo == null) {
%>
	<script type="text/javascript">
	alert("로그인 후 이용 가능합니다.");
	location.href="<c:url value='/'/>"
	</script>
<%	
} else {
	
	if (userVo.getA_no() != 1) {
%>
		<script type="text/javascript">
		alert("권한이 없습니다.");
		location.href="<c:url value='/'/>"
		</script>
<%	
		}
}
%>
