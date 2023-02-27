<%@page import="com.hugh.detector.vo.DetectorVo"%>
<%@page import="java.util.List"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>

<head>
	<meta charset="UTF-8">
	<title>Detector</title>
	<link href="<c:url value='/resources/css/common.css' />" rel="stylesheet" type="text/css">
	<link href="<c:url value='/resources/css/detected_list.css' />" rel="stylesheet" type="text/css">
	<script src="https://code.jquery.com/jquery-3.6.1.min.js" integrity="sha256-o88AwQnZB+VDvE9tvIXrMQaPlFFSUTR+nldQm1LuPXQ=" crossorigin="anonymous"></script>
	<script>
	    function page(){
	        $('table.paginated').each(function() {
	            var numPage = 10;
	            var currentPage = 0;
	            var numPerPage = 5;
	            var $table = $(this);
	            var pagination = $("#pagination");
	            var numRows = $table.find('tr').length;
	            var numPages = Math.ceil(numRows / numPerPage);
	            if (numPages==0) return;
	            var $pager = $('<div class="pager"></div>');
	            var nowp = currentPage;
	            var endp = nowp+10;
	            $table.bind('repaginate', function() {
	                $table.find('tr').hide().slice(currentPage * numPerPage, (currentPage + 1) * numPerPage).show();
	                $("#pagination").html("");
	                if (numPages > 1) {
	                    if (currentPage < 5 && numPages-currentPage >= 5) {
	                        nowp = 0;
	                        endp = numPage;
	                    } else {
	                        nowp = currentPage -5;
	                        endp = nowp+numPage;
	                        pi = 1;
	                    }
	                    if (numPages < endp) {
	                        endp = numPages;
	                        nowp = numPages-numPage;
	                    }
	                    if (nowp < 1) {
	                        nowp = 0;
	                    }
	                } else {
	                    nowp = 0;
	                    endp = numPages;
	                }
	                $('<span class="pageNum first">≪ </span>').bind('click', {newPage: page},function(event) {
	                    currentPage = 0;
	                    $table.trigger('repaginate');
	                    $($(".pageNum")[2]).addClass('active').siblings().removeClass('active');
	                }).appendTo(pagination).addClass('clickable');
	                $('<span class="pageNum back">< </span>').bind('click', {newPage: page},function(event) {
	                    if(currentPage == 0) return;
	                    currentPage = currentPage-1;
	                    $table.trigger('repaginate');
	                    $($(".pageNum")[(currentPage-nowp)+2]).addClass('active').siblings().removeClass('active');
	                }).appendTo(pagination).addClass('clickable');
	                for (var page = nowp ; page < endp; page++) {
	                    $('<span class="pageNum"></span>').text((page + 1).toString() + ' ').bind('click', {newPage: page}, function(event) {
	                        currentPage = event.data['newPage'];
	                        $table.trigger('repaginate');
	                        $($(".pageNum")[(currentPage-nowp)+2]).addClass('active').siblings().removeClass('active');
	                    }).appendTo(pagination).addClass('clickable');
	                }
	                $('<span class="pageNum next"> ></span>').bind('click', {newPage: page},function(event) {
	                    if(currentPage == numPages-1) return;
	                    currentPage = currentPage+1;
	                    $table.trigger('repaginate');
	                    $($(".pageNum")[(currentPage-nowp)+2]).addClass('active').siblings().removeClass('active');
	                }).appendTo(pagination).addClass('clickable');
	                $('<span class="pageNum last"> ≫</span>').bind('click', {newPage: page},function(event) {
	                    currentPage = numPages-1;
	                    $table.trigger('repaginate');
	                    $($(".pageNum")[endp-nowp+1]).addClass('active').siblings().removeClass('active');
	                }).appendTo(pagination).addClass('clickable');
	                $($(".pageNum")[2]).addClass('active');
	            });
	            $pager.insertAfter($table).find('span.pageNum:first').next().next().addClass('active');
	            $pager.appendTo(pagination);
	            $table.trigger('repaginate');
	        });
	    }
	</script>
	<script>
		$(function() {
		    page();
		});
	</script>
</head>

<body>

	<%
	if (session.getAttribute("id") == null) {
		response.sendRedirect(request.getContextPath() + "/login");
	}
	%>

	<header>
		<div id="wrap_header">
			<div class="text_header">
				Detector
			</div>
			<div class="menu_header">
				<a href="<%=request.getContextPath()%>/logout">logout</a>
			</div>
		</div>
	</header>
	
	<nav>
		<div id="wrap_nav">
			<div class="menu_nav">
				<a href="<%=request.getContextPath()%>/streaming">| Streaming |</a>&nbsp;&nbsp;
				<a href="<%=request.getContextPath()%>/detectedList">| Detected List |</a>&nbsp;&nbsp;
				<a href="<%=request.getContextPath()%>/adminPage">| Admin Page |</a>
			</div>
		</div>
	</nav>
	
	<article>
		<div id="wrap_article">
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
                            <td><a href="<%=request.getContextPath()%>/checkImg?i_img_name=<%=detectorVos.get(i).getI_img_name()%>"><img title="<%=detectorVos.get(i).getI_reg_date()%>" src="//192.168.0.103/imgs/<%=detectorVos.get(i).getI_img_name()%>" width="126" /></a></td>
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
	
	<footer>
		<div id="wrap_footer">
			<div class="copyright">
				Copyright(c) Hugh All rights reserved.
			</div>
		</div>
	</footer>
	
</body>

</html>