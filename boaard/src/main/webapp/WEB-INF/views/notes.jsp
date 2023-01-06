<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>

<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<link rel="icon" href="<c:url value='/resources/static/favicon.ico' />" type="image/x-icon" />
	<link href="<c:url value='/resources/css/common.css' />" rel="stylesheet" type="text/css">
	<link href="<c:url value='/resources/css/notes.css' />" rel="stylesheet" type="text/css">
	<jsp:include page="./include/title.jsp" />
	<jsp:include page="./include/common_js.jsp" />
	<jsp:include page="./include/notes_js.jsp" />
</head>

<body onselectstart="return false">
	
	<jsp:include page="./include/header.jsp" />
	
	<article>
	
		<div id="wrap_article">
			<div class="canvasList">
				<ul class="slide">
				</ul>
				<p class="controlSlide">
					<span class="prev">&lang;</span>
					<span class="next">&rang;</span>
				</p>
			</div>
			<div class="conversion">
				<div class="noteTxt">
					<textarea class="conversionTxt"></textarea>
				</div>
				<div class="controlNote">
					<input type="button" class="modifyNote" value="Modify">
					<input type="button" class="deleteNote" value="Delete">
					<input type="button" class="cancelNote" value="Cancel">
				</div>
			</div>
			<div class="addNote">
				<div class="canvas">
					<canvas class="noteCanvas" width="600" height="600"></canvas>
				</div>
				<div class="controlCanvas">
					<input type="button" class="undoCanvas" value="Undo">
					<input type="button" class="clearCanvas" value="Clear">
					<input type="button" class="saveCanvas" value="Save">
					<input type="button" class="cancelCanvas" value="Cancel">
				</div>
			</div>
			<div class="myPage">
				<div class="wrap_myPage">
					<div class="cancelMyPage">
						<span id="btnCancelMyPage">&#215;</span>&nbsp;&nbsp;
					</div>
					<div class="myPageForm">
						<form action="<%=request.getContextPath()%>/modifyMyPage" method="post" id="formMyPage">
							<input type="hidden" name="u_no" id="noMyPage">
							<input type="text" name="u_id" placeholder="ID" id="idMyPage" readonly><br>
							<input type="password" name="u_pw" placeholder="Password" id="pwMyPage"><br>
							<input type="password" name="new_pw" placeholder="New Password" id="newPwMyPage"><br>
							<input type="password" name="confirm_new_pw" placeholder="Confirm New Password" id="confirmNewPwMyPage"><br>
							<input type="email" name="u_email" placeholder="Email" id="emailMyPage"><br>
							<input type="button" class="modifyMyPageBtn" value="Modify" id="btnModifyMyPage">
						</form>
					</div>
					<div class="controlMyPage">
						<input type="button" class="withdrawal" value="Withdrawal" id="btnWithdrawal">
					</div>
				</div>
			</div>
		</div>
	
	</article>
	
	<jsp:include page="./include/footer.jsp" />
	
</body>

</html>