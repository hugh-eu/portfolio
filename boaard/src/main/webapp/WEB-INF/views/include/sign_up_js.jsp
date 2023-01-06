<<<<<<< HEAD
<%@page import="com.hugh.boaard.vo.BoaardVo"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<script>

function addSignUp(){
	
	$("#submitSignUp").click(function(){
		var u_id = $("#idSignUp").val();
		var u_pw = $("#pwSignUp").val();
		var u_email = $("#emailSignUp").val();
		var regex = /^[0-9a-zA-Z]([-_.]?[0-9a-zA-Z])*@[0-9a-zA-Z]([-_.]?[0-9a-zA-Z])*.[a-zA-Z]{2,3}$/i;
		
		if (u_id == "") {
			alert("Please enter ID.");
			$("#idSignUp").focus();
			
		} else if (u_id.length > 10) {
			alert("Please set ID to 10 characters or less.");
			$("#idSignUp").focus();
			
		} else if (u_pw == "") {
			alert("Please enter password.");
			$("#pwSignUp").focus();
			
		} else if (u_pw.length > 20) {
			alert("Please set password to 20 characters or less.");
			$("#pwSignUp").focus();
			
		} else if (u_email == "") {
			alert("Please enter Email.");
			$("#emailSignUp").focus();
			
		} else if (!u_email.match(regex)) {
			alert("Please enter a valid email.");
			$("#emailSignUp").focus();
			
		} else {
			$("#formSignUp").submit();
			
		}
		
	});
	
	$("#cancelSignUp").click(function(){
		$(location).attr("href", "<c:url value='/' />");
		
	});
	
}

$(function(){
	addSignUp();

})

=======
<%@page import="com.hugh.boaard.vo.BoaardVo"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<script>

function addSignUp(){
	
	$("#submitSignUp").click(function(){
		var u_id = $("#idSignUp").val();
		var u_pw = $("#pwSignUp").val();
		var u_email = $("#emailSignUp").val();
		var regex = /^[0-9a-zA-Z]([-_.]?[0-9a-zA-Z])*@[0-9a-zA-Z]([-_.]?[0-9a-zA-Z])*.[a-zA-Z]{2,3}$/i;
		
		if (u_id == "") {
			alert("Please enter ID.");
			$("#idSignUp").focus();
			
		} else if (u_id.length > 10) {
			alert("Please set ID to 10 characters or less.");
			$("#idSignUp").focus();
			
		} else if (u_pw == "") {
			alert("Please enter password.");
			$("#pwSignUp").focus();
			
		} else if (u_pw.length > 20) {
			alert("Please set password to 20 characters or less.");
			$("#pwSignUp").focus();
			
		} else if (u_email == "") {
			alert("Please enter Email.");
			$("#emailSignUp").focus();
			
		} else if (!u_email.match(regex)) {
			alert("Please enter a valid email.");
			$("#emailSignUp").focus();
			
		} else {
			$("#formSignUp").submit();
			
		}
		
	});
	
	$("#cancelSignUp").click(function(){
		$(location).attr("href", "<c:url value='/' />");
		
	});
	
}

$(function(){
	addSignUp();

})

>>>>>>> 5aa76ea3a0591d427a636e8d726911934985e0b2
</script>