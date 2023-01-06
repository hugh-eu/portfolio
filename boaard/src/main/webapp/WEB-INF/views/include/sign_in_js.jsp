<<<<<<< HEAD
<%@page import="com.hugh.boaard.vo.BoaardVo"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<script>

function addSignIn(){

	$("#btnSignIn").click(function(){
		var u_id = $("#idSignIn").val();
		var u_pw = $("#pwSignIn").val();
		
		if (u_id == "") {
			alert("Please enter your ID.");
			$("#idSignIn").focus();
			
		} else if (u_pw == "") {
			alert("Please enter your password.");
			$("#pwSignIn").focus();
			
		} else {
			$("#formSignIn").submit();
			
		}
	});
	
	$("#btnSignUp").click(function(){
		$(location).attr("href", "<c:url value='/signUp' />");
		
	});
	
}

$(function(){
	addSignIn();

})

=======
<<<<<<< HEAD
<%@page import="com.hugh.boaard.vo.BoaardVo"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<script>

function addSignIn(){

	$("#btnSignIn").click(function(){
		var u_id = $("#idSignIn").val();
		var u_pw = $("#pwSignIn").val();
		
		if (u_id == "") {
			alert("Please enter your ID.");
			$("#idSignIn").focus();
			
		} else if (u_pw == "") {
			alert("Please enter your password.");
			$("#pwSignIn").focus();
			
		} else {
			$("#formSignIn").submit();
			
		}
	});
	
	$("#btnSignUp").click(function(){
		$(location).attr("href", "<c:url value='/signUp' />");
		
	});
	
}

$(function(){
	addSignIn();

})

=======
<%@page import="com.hugh.boaard.vo.BoaardVo"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<script>

function addSignIn(){

	$("#btnSignIn").click(function(){
		var u_id = $("#idSignIn").val();
		var u_pw = $("#pwSignIn").val();
		
		if (u_id == "") {
			alert("Please enter your ID.");
			$("#idSignIn").focus();
			
		} else if (u_pw == "") {
			alert("Please enter your password.");
			$("#pwSignIn").focus();
			
		} else {
			$("#formSignIn").submit();
			
		}
	});
	
	$("#btnSignUp").click(function(){
		$(location).attr("href", "<c:url value='/signUp' />");
		
	});
	
}

$(function(){
	addSignIn();

})

>>>>>>> 5aa76ea3a0591d427a636e8d726911934985e0b2
>>>>>>> dfafe29c0482dd92cdc454a767f9bed240e80ae9
</script>