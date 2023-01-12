<%@page import="com.group1.licensePlateTrace.vo.UserVo"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>

<!DOCTYPE html>
<html>
<head>
	<jsp:include page="../../common/authCheck.jsp" />
	<jsp:include page="../../common/title.jsp" />
	
	<link href="<c:url value='/resources/common/css/common.css' />"rel="stylesheet" type="text/css" />
	<link href="<c:url value='/resources/user/css/licensePlate.css' />" rel="stylesheet" type="text/css" />
	
	<jsp:include page="../../common/jquery_url.jsp" />
	<jsp:include page="./js/licensePlate_vo_js.jsp" />
	<jsp:include page="./js/licensePlate_js.jsp" />
</head>

<body>

	<jsp:include page="../../common/header.jsp" />

	<section>
		<div id="section_wrap">
		
			<div class="div_license_plate_regist_wrap">
			
				<div class="div_license_plate_regist">
					<form name="form_div_license_plate_regist">
						<input type="hidden" name="u_no" value="<%=((UserVo)session.getAttribute("userVo")).getU_no()%>">
						번호판 입력
						<br>
						<input type="text" name="s_name" placeholder="등록할 번호판을 입력해주세요.">
						<br>
						내용 입력
						<br>
						<input type="text" name="s_info" placeholder="내용을 입력해주세요.">
						<input type="button" onclick="sendForm();" value="등록">
						<input type="reset" value="초기화">
					</form>
				</div>
				
				<div class="div_license_plate_list">

					<div class="search">
						<input name="search_bar" placeholder="찾고자 하는 번호판을 입력하세요">					
						<input type="button" name="search_btn" value="찾기" onclick="ajax_getlicensePlateList();">
					</div>
					
					<div class="set_amount">
						<select name="set_amount">
							<option value="5">5개</option>
							<option value="10">10개</option>
							<option value="20">20개</option>
						</select>
						<select name="set_order">
							<option value="DESC">내림차순</option>
							<option value="ASC">오름차순</option>
						</select>
					</div>
					
					<div class="table_wrap">
						<table>
							<thead>
								<tr>
									<td>식별번호</td>
									<td>번호판이름</td>
									<td>번호판내용</td>
									<td>번호판등록날짜</td>
									<td>번호판수정날짜</td>
								</tr>
							</thead>
						</table>
					</div>
					
					<div class="page_wrap">
	
						<div class="page_number">
						</div>
		
						<div class="page_goto">
							<input type="number" name="page_target_num">&nbsp; &#47; <span class="page_total_num"></span> 
							<a class="goto_page_btn">페이지 이동</a>
						</div>
	
					</div>	
					
				</div>
				
			</div>
			
		</div>
	</section>

	<jsp:include page="../../common/footer.jsp" />
	
</body>
</html>

<template id="licensePlate_item_list">
	<tbody>
		<tr>
			<td class="s_no"></td>
			<td class="s_name">
				<input type="text" name="s_name" disabled="disabled">
			</td>
			<td class="s_info">
				<input type="text" name="s_info">
				<a class="change_info_btn">수정</a>
			</td>
			<td class="s_reg_date"></td>
			<td class="s_mod_date"></td>
		</tr>
	</tbody>
</template>