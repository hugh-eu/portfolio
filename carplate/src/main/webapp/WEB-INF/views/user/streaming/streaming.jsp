<%@page import="org.springframework.ui.Model"%>
<%@page import="com.group1.licensePlateTrace.vo.StreamingVo"%>
<%@page import="java.util.List"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE html>
<html>
<head>
	<jsp:include page="../../common/title.jsp" />
	
	<link href="<c:url value='/resources/common/css/common.css' />"rel="stylesheet" type="text/css" />
	<link href="<c:url value='/resources/user/css/streaming.css' />" rel="stylesheet" type="text/css" />
	
	<jsp:include page="../../common/jquery_url.jsp" />
	<jsp:include page="../../common/authCheck.jsp" />
	<jsp:include page="./js/streaming_js.jsp" />
</head>
<body>

	<jsp:include page="../../common/header.jsp" />
	
	<section id="section_wrap">
		
        <div id="cameraList">
        	<table id="cameraListTable">
       		<%
       			List<StreamingVo> streamingVos = (List<StreamingVo>)request.getAttribute("streamingVos");
       			int colList = (int)Math.ceil(Math.sqrt(streamingVos.size()));
       			double width = 800.0 / colList, height = 600.0 / colList;
             	for (int i = 0; i < streamingVos.size(); i++) {
             		if (i % colList == 0) {
            %>
             			<tr>
            <%
             		}
            %>
		             		<td class="cameraEach" width="<%=width%>" height="<%=height%>" data-c_no="<%=streamingVos.get(i).getC_no()%>" data-c_name="<%=streamingVos.get(i).getC_name()%>" data-c_latitude="<%=streamingVos.get(i).getC_latitude()%>" data-c_longitude="<%=streamingVos.get(i).getC_longitude()%>" data-c_ip="<%=streamingVos.get(i).getC_ip()%>" data-c_port="<%=streamingVos.get(i).getC_port()%>" data-c_status="<%=streamingVos.get(i).getC_status()%>">
				        		<span class="cameraName">
				        			<%=streamingVos.get(i).getC_name()%>
				        		</span>
			<%
			        		if (streamingVos.get(i).getC_status().equals("1")) {
       		%>
				        		<img class="cameraVideo" src="http://<%=streamingVos.get(i).getC_ip()%>:9090/?action=stream" width="<%=width%>" height="<%=height%>">
       		<%
			        		} else {
       		%>
				        		<span class="cameraNoSignal">No signal.</span>
       		<%
			        		}
       		%>
		             		</td>
            <%
            		if ((i % colList == colList - 1) || ((i % colList != colList - 1) && (i == streamingVos.size() - 1))) {
            %>
             			</tr>
            <%
            		}
             	}
       		%>
        		
        	
        	</table>
        
        </div>
        <div id="cameraDetailBack">
        	<div id="cameraDetailContents">
		        <div id="cameraDetail">
		        	<div id="cameraControl">
			        	<span id="cameraToggleSwitch">
		        			<span id="cameraToggleButton"></span>
		        		</span>
	        		</div>
	        		<div id="cameraOriginal">
	        		</div>
	        		<table id="cameraInfo">
	        		</table>
		        </div>
	        </div>
        </div>
		
	</section>

	<jsp:include page="../../common/footer.jsp" />
	
</body>
</html>