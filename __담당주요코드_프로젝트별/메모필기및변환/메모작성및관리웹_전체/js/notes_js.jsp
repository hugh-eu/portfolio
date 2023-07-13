<%@page import="com.hugh.boaard.vo.BoaardVo"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>




<script>

function checkSession() {
	var u_id = "<%=session.getAttribute("u_id")%>";

	if (u_id == "null") {
		alert("Please log in.")
		$(location).attr("href", "<c:url value='/' />");
		
	}

}

function addHeader(){
	checkSession();
	
	$("#btnSignOut").click(function(){
		checkSession();
		
		if (confirm("Are you sure you want to sign out?")) {
			$(location).attr("href", "<c:url value='/' />");
			
		}
		
	});

}

function canvas(){
	checkSession();
	
	var context = $(".noteCanvas").get(0).getContext("2d", { willReadFrequently: true });
	var startX = 0;
	var startY = 0;
	var endX = 0;
	var endY = 0;
	var flag = false;
	var flag_draw = false;
	var restore_array = [];
	var index = -1;
	
	context.lineWidth = 3;

	$(".noteCanvas").on({		
		mousedown:function(event){
			var position=$(this).offset();
			var x = event.pageX - position.left;
			var y = event.pageY - position.top;
			startX = x;
			startY = y;
			flag = true;
			flag_draw = true;
			
		},
		mousemove:function(event){
			if(flag) {
				var position = $(this).offset();
				endX = event.pageX - position.left;
				endY = event.pageY - position.top;
				context.beginPath();
				context.moveTo(startX, startY);
				context.lineTo(endX, endY);
				context.stroke();
				startX = endX;
				startY = endY;
				
			}
		},
		mouseup:function(){
			flag=false;
			if (flag_draw) {
				restore_array.push(context.getImageData(0, 0, $(".noteCanvas").get(0).width, $(".noteCanvas").get(0).height));
				index += 1;
				flag_draw = false;
				
			}
		},
		mouseout:function(){
			flag=false;
			if (flag_draw) {
				restore_array.push(context.getImageData(0, 0, $(".noteCanvas").get(0).width, $(".noteCanvas").get(0).height));
				index += 1;
				flag_draw = false;
				
			}
		}
	});
	
	$(".undoCanvas").click(function(){
		checkSession();
		
		if (index <= 0) {
			context.clearRect(0, 0, $(".noteCanvas").get(0).width, $(".noteCanvas").get(0).height);
			restore_array = [];
		    index = -1;
		    
		} else {
			index -= 1;
			restore_array.pop();
			context.putImageData(restore_array[index], 0, 0);
			
		}
	});

	$(".clearCanvas").click(function(){
		checkSession();
		
		context.clearRect(0, 0, $(".noteCanvas").get(0).width, $(".noteCanvas").get(0).height);
		restore_array=[];
	    index =-1;
	    
	});

	$(".saveCanvas").click(function(){
		checkSession();
		
		$(".noteCanvas").get(0).toBlob((blob)=>{
			var data = $(".noteCanvas").get(0).toDataURL("image/png").toString().replace("data:image/png;base64,", "");
			
			$.ajax({
				url : "<c:url value='/uploadNote' />",
				type : "POST",
				data : JSON.stringify({"canvasData": data}),
				contentType : "application/json",
				success : function(result) {
					if (result > 0) {
						alert("upload succeed.");
						
						context.clearRect(0, 0, $(".noteCanvas").get(0).width, $(".noteCanvas").get(0).height);
						restore_array=[];
					    index =-1;
					    
						$(".conversion").hide();
						$(".addNote").hide();
					    $(".canvasList").fadeIn(500);
					    
					    showNotes();

					} else if (result == 0) {
						alert("upload failed.");

					} else {
						alert("Image size is too small.");
					}
				},
				error : function(request, status, error){
					alert("Connection error.");
					
					console.log("code : " + request.status);
			        console.log("message : " + request.responseText);
			        console.log("error : " + error);

				}
			});
		});
	});

	$(".cancelCanvas").click(function(){
		checkSession();
		
		if (confirm("Are you sure you want to cancel?")) {
			$(".conversion").hide();
			$(".addNote").hide();
			$(".canvasList").fadeIn(500);
			
			slideShow();

			context.clearRect(0, 0, $(".noteCanvas").get(0).width, $(".noteCanvas").get(0).height);
			restore_array=[];
		    index =-1;
		    
		}
	});

}

function showNotes(){
	checkSession();
	
	var u_no = "<%=session.getAttribute("u_no")%>";
	
	$.ajax({
		url : "<c:url value='/getNotes' />",
		type : "POST",
		data : JSON.stringify({"u_no": u_no}),
		contentType : "application/json",
		success : function(boaardVos) {
			$(".slide").empty();
			for (var i = 0; i < boaardVos.length; i++){
				var n_no = boaardVos.at(i).n_no;
				var n_name = boaardVos.at(i).n_name;

				$(".slide").append("<li><img src='//192.168.0.123/boaard/notes/" + n_name + "' class='noteImg' data-n_no='" + n_no + "' /></li>")
			}
			$(".slide").append("<li><img src='//192.168.0.123/boaard/sources/plusBtn.png' id='plusBtn' /></li>")

			addImg();
			slideShow();
			addSlide();
			
		},
		error : function(request, status, error){
			alert("Connection error.");
			
			console.log("code : " + request.status);
	        console.log("message : " + request.responseText);
	        console.log("error : " + error);
			
		}
	});

}

function addImg() {
	checkSession();
	
	$(".noteImg").click(function(){
		checkSession();
		
		var n_no = $(this).data("n_no");
		
		$.ajax({
			url : "<c:url value='/getText' />",
			type : "POST",
			data : JSON.stringify({"n_no": n_no}),
			contentType : "application/json",
			success : function(boaardVo) {
				if (boaardVo != null) {
					$(".conversionTxt").data("c_no", boaardVo.c_no)
					$(".conversionTxt").data("n_no", boaardVo.n_no)
					$(".conversionTxt").val(boaardVo.c_text);
					
					$(".addNote").hide();
				    $(".canvasList").hide();
					$(".conversion").fadeIn(500);

				} else {
					alert("Connection error.");
				}
			},
			error : function(request, status, error){
				alert("Connection error.");

				console.log("code : " + request.status);
		        console.log("message : " + request.responseText);
		        console.log("error : " + error);
				
			}
		});
	});

}

function slideShow(){
	checkSession();
	
	var slide = document.querySelector(".slide");
	var slideImg = document.querySelectorAll(".slide li");
	var currentIdx = 0;
	var slideCount = slideImg.length;
	var slideWidth = 602;

	slide.style.width = slideWidth * slideCount + "px";
	
	if (slideCount > 1) {
		slide.style.left = (-(slideCount - 2) * 602) + "px";
		currentIdx = slideCount - 2;
	}
	
	$(".prev").click(function() {
		checkSession();
		
		if (currentIdx > 0){
			var num = currentIdx - 1
			slide.style.left = (-num * 602) + "px";
			currentIdx = num;
		 
		}
	});

	$(".next").click(function() {
		checkSession();
		
		if (currentIdx < (slideCount - 1)) {
			var num = currentIdx + 1
			slide.style.left = (-num * 602) + "px";
			currentIdx = num;
		 
		}
	});
}

function addSlide(){
	checkSession();
	
	$("#plusBtn").click(function(){
		checkSession();
		
		$(".canvasList").hide();
		$(".conversion").hide();
		$(".addNote").fadeIn(500);
		
	});

}

function addConversion(){
	checkSession();
	
	$(".modifyNote").click(function(){
		checkSession();
		
		var c_no = $(".conversionTxt").data("c_no");
		var c_text = $(".conversionTxt").val();
		
		$.ajax({
			url : "<c:url value='/modifyText' />",
			type : "POST",
			data : JSON.stringify({"c_no": c_no, "c_text": c_text}),
			contentType : "application/json",
			success : function(result) {
				if (result == 1) {
				 	alert("Modify Succeed.")

					$(".conversion").hide();
					$(".addNote").hide();
				    $(".canvasList").fadeIn(500);
				    $(".conversionTxt").val("")

				} else {
				 	alert("Modify Failed.")

				}
			},
			error : function(request, status, error){
				alert("Connection error.");

				console.log("code : " + request.status);
		        console.log("message : " + request.responseText);
		        console.log("error : " + error);
				
			}
		});
	});
	
	$(".deleteNote").click(function(){
		checkSession();
		
		if (confirm("Are you sure you want to delete?")) {
			var n_no = $(".conversionTxt").data("n_no");
			
			$.ajax({
				url : "<c:url value='/deleteNote' />",
				type : "POST",
				data : JSON.stringify({"n_no": n_no}),
				contentType : "application/json",
				success : function(result) {
					if (result == 1) {
					 	alert("Delete Succeed.")
	
						$(".conversion").hide();
						$(".addNote").hide();
					    $(".canvasList").fadeIn(500);
					    $(".conversionTxt").val("")
					    
					    showNotes();
	
					} else {
					 	alert("Delete Failed.")
	
					}
				    
				},
				error : function(request, status, error){
					alert("Connection error.");
	
					console.log("code : " + request.status);
			        console.log("message : " + request.responseText);
			        console.log("error : " + error);
					
				}
			});
		}
	});
	
	$(".cancelNote").click(function(){
		checkSession();
		
		$(".conversion").hide();
		$(".addNote").hide();
	    $(".canvasList").fadeIn(500);
	    $(".conversionTxt").val("")
	    
	});
	
}

function modalMyPage(){
	checkSession();
	
	$("#myId").click(function(){
		checkSession();
		
		var u_no = <%=session.getAttribute("u_no")%>;
		
		$.ajax({
			url : "<c:url value='/getMyPage' />",
			type : "POST",
			data : JSON.stringify({"u_no": u_no}),
			contentType : "application/json",
			success : function(boaardVo) {
				var u_no = boaardVo.u_no;
				var u_id = boaardVo.u_id;
				var u_email = boaardVo.u_email;

				$("#noMyPage").val(u_no);
				$("#idMyPage").val(u_id);
				$("#emailMyPage").val(u_email);
				
				$(".myPage").toggleClass("show");

				if ($(".myPage").hasClass("show")) {
					$("body").css("overflow", "hidden");
				}
				
			},
			error : function(request, status, error){
				alert("Connection error.");
				
				console.log("code : " + request.status);
		        console.log("message : " + request.responseText);
		        console.log("error : " + error);
				
			}
			
		});
		
	});
	
	$("#btnCancelMyPage").click(function(){
		checkSession();
		
		$(".myPage").toggleClass("show");
		
		if (!$(".myPage").hasClass("show")) {
			$("body").css("overflow", "auto");
			
		}
		
		$("#formMyPage input:not(#btnModifyMyPage)").val("");
		
	});
	
	$("#btnModifyMyPage").click(function(){
		checkSession();
		
		if (confirm("Are you sure you want to modify?")) {
			var u_no = $("#noMyPage").val();
			var u_pw = $("#pwMyPage").val();
			var new_pw = $("#newPwMyPage").val();
			var confirm_new_pw = $("#confirmNewPwMyPage").val();
			var u_email = $("#emailMyPage").val();
			var regex = /^[0-9a-zA-Z]([-_.]?[0-9a-zA-Z])*@[0-9a-zA-Z]([-_.]?[0-9a-zA-Z])*.[a-zA-Z]{2,3}$/i;
			
			if (u_pw == "") {
				alert("Please enter your current password.");
				$("#pwMyPage").focus();
				
			} else if (new_pw.length > 20) {
				alert("Please set new password to 20 characters or less.");
				$("#newPwMyPage").val("");
				$("#confirmNewPwMyPage").val("");
				$("#newPwMyPage").focus();
				
			} else if (new_pw != confirm_new_pw) {
				alert("Please confirm your new password.");
				$("#newPwMyPage").val("");
				$("#confirmNewPwMyPage").val("");
				$("#newPwMyPage").focus();
				
			} else if (u_email == "") {
				alert("Please enter Email.");
				$("#emailMyPage").focus();
				
			} else if (!u_email.match(regex)) {
				alert("Please enter a valid email.");
				$("#emailMyPage").focus();
				
			} else {
				$("#formMyPage").submit();
				
			}
			
		}
		
	});
	
	$("#btnWithdrawal").click(function(){
		checkSession();
		
		if (confirm("Are you sure you want to withdraw?")) {
			var u_no = <%=session.getAttribute("u_no")%>;
			var u_pw = $("#pwMyPage").val();
			
			$.ajax({
				url : "<c:url value='/withdrawal' />",
				type : "POST",
				data : JSON.stringify({"u_no": u_no, "u_pw": u_pw}),
				contentType : "application/json",
				success : function(result) {
					if (result > 0) {
						alert("Withdrawal Succeed.");
						$(location).attr("href", "<c:url value='/' />");
						
					} else if (result == 0) {
						alert("Withdrawal Failed.");
						
					} else {
						alert("Password is incorrect.");
						
					}
					
				},
				error : function(request, status, error){
					alert("Connection error.");
					
					console.log("code : " + request.status);
			        console.log("message : " + request.responseText);
			        console.log("error : " + error);
					
				}
				
			});
			
		}
		
	});
	
}

checkSession();

$(function(){
	$(".conversion").hide();
	$(".addNote").hide();
	$(".canvasList").fadeIn(500);

	addHeader();
	canvas();
	showNotes();
	addConversion();
	modalMyPage();

})

</script>