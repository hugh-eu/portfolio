<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<script>

function addHeader(){

	$("#btnSignOut").click(function(){
		if (confirm("Are you sure you want to sign out?")) {
			$(location).attr("href", "<%=request.getContextPath()%>/");
			
		}
	});
}

$(function(){
	addHeader();

})

</script>