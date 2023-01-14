<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE html>
<html>
<head>
	<jsp:include page="../../common/authCheck.jsp" />
	<jsp:include page="../../common/superAdminCheck.jsp" />
	<jsp:include page="../../common/title.jsp" />
	
	<link href="<c:url value='/resources/common/css/common.css' />"rel="stylesheet" type="text/css" />
	<link href="<c:url value='/resources/admin/css/accountManagement.css' />" rel="stylesheet" type="text/css" />
	
	<jsp:include page="../../common/jquery_url.jsp" />
	<jsp:include page="./js/accountManagement_vo_js.jsp" />
	<jsp:include page="./js/accountManagement_js.jsp" />
</head>

<body>

	<jsp:include page="../../common/header.jsp" />

	<section>
		<div id="section_wrap">
			
			<div class="accountManagement_wrap">
				
				<div class="search_bar">
					<input type="text" name="user_search_by_name" placeholder="찾고자 하는 이름을 입력해주세요.">
					<input type="button" name="search_bar_btn" value="찾기">
				</div>
				
				<div class="set_amount">
					<select name="set_amount">
						<option value="5">5개</option>
						<option value="10">10개</option>
						<option value="20">20개</option>
					</select>
				</div>
				
				<div class="user_list">
					<table>
						<thead>
							<tr>
								<td>식별번호</td>
								<td>아이디</td>
								<td>패스워드</td>
								<td>이름</td>
								<td>메일</td>
								<td>전화번호</td>
								<td>등록날짜</td>
								<td>수정날짜</td>
								<td>권한</td>
								<td>권한내용</td>
								<td>권한등록날짜</td>
								<td>권한수정날짜</td>
							</tr>
						</thead>
					</table>
				</div>
				
				<div class="page_wrap">
	
					<div class="page_number">
					</div>
	
					<div class="page_goto">
						<input type="number" name="page_target_num">&nbsp; &#47; <span class="page_total_num"></span> 
						<a class="goto_page_btn">Go to page</a>
					</div>
	
				</div>

			</div>
			
		</div>
	</section>

	<jsp:include page="../../common/footer.jsp" />
	<jsp:include page="./modify_form.jsp" />

</body>
</html>

<template id="user_list_item">
	<tbody>
		<tr>
			<td class="u_no"></td>
			<td class="u_id"></td>
			<td class="u_pw">
				******
				<br>
				<a class="change_pw_btn">변경</a>
			</td>
			<td class="u_name">
				<input type="text" name="u_name">
				<br>
				<a class="change_name_btn">변경</a>
			</td>
			<td class="u_mail">
				<input type="email" name="u_mail">
				<br>
				<a class="change_email_btn">변경</a>
			</td>
			<td class="u_phone">
				<input type="text" name="u_phone">
				<br>
				<a class="change_phone_btn">변경</a>
			</td>
			<td class="u_reg_date"></td>
			<td class="u_mod_date"></td>
			<td class="a_no">
				<select name="a_no">
					<option value="1">관리자</option>
					<option value="2">일반사용자</option>
					<option value="3">승인대기</option>
				</select>
			</td>
			<td class="a_auth_info"></td>
			<td class="a_reg_date"></td>
			<td class="a_mod_date"></td>
		</tr>
	</tbody>
</template>
