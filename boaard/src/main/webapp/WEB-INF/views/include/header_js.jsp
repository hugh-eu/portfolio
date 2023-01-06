<<<<<<< HEAD
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

=======
<<<<<<< HEAD
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

=======
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

>>>>>>> 5aa76ea3a0591d427a636e8d726911934985e0b2
>>>>>>> dfafe29c0482dd92cdc454a767f9bed240e80ae9
</script>