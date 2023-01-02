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
	<jsp:include page="./include/common_js.jsp" />
	<script src="<c:url value='/resources/js/detected_list.js' />" type="text/javascript" ></script>
	<link href="<c:url value='/resources/css/common.css' />" rel="stylesheet" type="text/css">
	<link href="<c:url value='/resources/css/include/article.css' />" rel="stylesheet" type="text/css">
	<link href="<c:url value='/resources/css/detected_list.css' />" rel="stylesheet" type="text/css">
	<link href="<c:url value='/resources/css/modal.css' />" rel="stylesheet" type="text/css">
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
			<div class="modal">
				<div class="modal_body">
					<img class="img_detail" src="" />
					<table class="img_info">
						<tr>
							<td>i_no</td>
							<td class="i_no"></td>
						</tr>
						<tr>
							<td>i_device</td>
							<td class="i_device"></td>
						</tr>
						<tr>
							<td>i_img_name</td>
							<td class="i_img_name"></td>
						</tr>
						<tr>
							<td>i_reg_date</td>
							<td class="i_reg_date"></td>
						</tr>
					</table>
				</div>
			</div>
			<div class="classify">
				Monthly :&nbsp;<input type="month" class="month">&nbsp;<input type="button" id="searchMonthly" value="Search"><br>
            	Daily :&nbsp;&nbsp;<input type="date" class="day">&nbsp;<input type="button" id="searchDaily" value="Search">
			</div>
			<div class="list">
				<table class="paginated">
                    <%
                    List<DetectorVo> detectorVos = (List<DetectorVo>)request.getAttribute("detectorVos");
                    for (int i = 0; i < detectorVos.size(); i++){
                    	if (i % 5 == 0) {
                    %>
                    	<tr>
                    <%
                    	}
                    %>                    
                            <td>
	                            <a href="#none" class="popup"
								                            data-i_no=<%=detectorVos.get(i).getI_no()%> 
								                            data-i_device=<%=detectorVos.get(i).getI_device()%> 
								                            data-i_img_name=<%=detectorVos.get(i).getI_img_name()%> 
								                            data-i_reg_date=<%=detectorVos.get(i).getI_reg_date().replace(" ", "+")%> >
	                            	<img title="<%=detectorVos.get(i).getI_reg_date()%>" src="//192.168.0.103/imgs/<%=detectorVos.get(i).getI_img_name()%>" width="126" />
	                            </a>
                            </td>
                    <%
                    	if (i % 5 == 4){
                    %>
                    	</tr>
                    <%
                    	}
                    }
                    %>
              	</table>
        	</div>
        	<div class="btnContent">
                <div class="pagination" id="pagination"></div>
            </div>
		</div>
	
	</article>
	
	<jsp:include page="./include/footer.jsp" />
	
</body>

</html>