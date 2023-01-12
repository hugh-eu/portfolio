<%@page import="com.group1.licensePlateTrace.vo.MapVo" %>
<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8" %>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>

<head>
	<jsp:include page="../../common/authCheck.jsp" />
	<jsp:include page="../../common/title.jsp" />

	<link href="<c:url value='/resources/common/css/common.css' />" rel="stylesheet" type="text/css" />
	<link href="<c:url value='/resources/user/css/map_comfirm.css' />" rel="stylesheet" type="text/css" />

	<jsp:include page="../../common/jquery_url.jsp" />
	<jsp:include page="./js/map_comfirm_js.jsp" />
	<jsp:include page="./Vo/map_comfirm_Vo_js.jsp" />

</head>

<body>

	<jsp:include page="../../common/header.jsp" />

	<section>
		<div id="section_wrap">
			<div id="map_wrap">

				<div class="map_date_write">
					<select class="map_control" onchange="monthSelect();"></select>
					년&nbsp;
					<select class="month_control" onchange="daySelect();"></select>
					월&nbsp;
					<select class="day_control" onchange="daySet();"></select>
					일&nbsp;&nbsp;&nbsp;
					<select class="plate_select" onchange="plate_selected();"></select>
				</div>

				<div class="plat_info">
					<input type="text" name="l_info" id="l_info" placeholder="자동차 번호판을 입력하세요(123가4568, )">
					<input type="button" value="Select" onclick="plate_info();">
					<input type="reset" onclick="resetItems();">
				</div>

				<div id="map">
				</div>

				<div class="plate_list">
				</div>
				
			</div>

			<div id="plate_detail_wrap">
				<div class="plate_detail" style="display: none;">
					<ul>
						<li>
							<div class="plat_img">
								<img>
							</div>
							<div class="plat_infos">
								<table>
									<tr>
										<td>범죄자 정보</td>
										<td>카메라 고유 번호</td>
										<td>번호판</td>
										<td>번호판정보 등록일</td>
										<td>번호판 검출일</td>
										<td>검출 사진</td>
									</tr>
									<tr>
										<td class="s_info"></td>
										<td class="c_no"></td>
										<td class="s_name"></td>
										<td class="s_reg_date"></td>
										<td class="l_info_reg_date"></td>
										<td class="l_img_name"><a href="#none"><img src="#none"></a>
										</td>
									</tr>
								</table>
							</div>
							<div>
								<a class="close" href="#none">CLOSE</a>
							</div>
						</li>
					</ul>
				</div>
			</div>
			
		</div>

		<jsp:include page="../../common/footer.jsp" />

	</section>

</body>

</html>

<template id="plate_list_item">
	<table class="plate_list_table">
		<tr>
			<td class="date">
				<div><span class="year"></span></div>
				<div><span class="month"></span>/<span class="date"></span></div>
				<div><span class="c_no">카메라 번호</span></div>
			</td>
			<td class="plate_info">
				<a href="#none">내용</a>
			</td>
			<td class="thumnail">
				<a href="#none"><img
						src="http://192.168.0.102/img/52%ea%b0%b83108_20221221093246_1.jpg/>"></a>
			</td>
		</tr>
	</table>
</template>