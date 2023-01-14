<%@page import="com.group1.licensePlateTrace.vo.UserVo"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>

<link href="<c:url value='/resources/common/css/header.css' />" rel="stylesheet" type="text/css">

<jsp:include page="./js/header_js.jsp" />

<%
UserVo userVo = (UserVo)session.getAttribute("userVo");
%>

<header>
	<div id="header_wrap">
	
		<div class="logo">
			<a href="<c:url value="/" />">
				<img src="<c:url value="/resources/common/img/licensePlateTrace.jpg"/>">
				License Plate Trace
			</a>
		</div>
		
		<div class="login">
			<%
			if (userVo == null) {
			%>
			<a href="<c:url value="/user/loginForm" />">로그인</a>
			<%	
			} else {
			%>
			<a href="<c:url value="/user/logout_confirm" />">로그아웃</a>
			<%	
			}
			%>
		</div>
		
		<div class="list">		
			<ul>
				<a class="map" href="<c:url value="/map/map_comfirm" />">위치 정보 확인</a>
			</ul>	
			<ul>
				<a class="licensePlate" href="<c:url value="/licensePlate" />">번호판 등록</a>
			</ul>
			<ul>
				<a class="streaming" href="<c:url value="/streaming" />">실시간 스트리밍</a>
			</ul>
			<ul>
				<a class="accountManagement" href="<c:url value="/admin/accountManagement" />">계정관리</a>
			</ul>
		</div>
		
	</div>
</header>