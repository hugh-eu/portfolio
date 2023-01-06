<<<<<<< HEAD
<header>
	<div id="wrap_header">
		<div class="titleHeader">
			<img src="<%=request.getContextPath()%>/resources/static/main.png" id="imgMain" /><br>
		</div>
		<div class="signOut">
		<%
		if (session.getAttribute("u_no") != null) {
		%>
			<span id="myId">&#64;<%=session.getAttribute("u_id")%></span>&nbsp;
			<input type="button" class="signOutBtn" value="Sign Out" id="btnSignOut">
		<%
		}
		%>
		</div>
	</div>
=======
<<<<<<< HEAD
<header>
	<div id="wrap_header">
		<div class="titleHeader">
			<img src="<%=request.getContextPath()%>/resources/static/main.png" id="imgMain" /><br>
		</div>
		<div class="signOut">
		<%
		if (session.getAttribute("u_no") != null) {
		%>
			<span id="myId">&#64;<%=session.getAttribute("u_id")%></span>&nbsp;
			<input type="button" class="signOutBtn" value="Sign Out" id="btnSignOut">
		<%
		}
		%>
		</div>
	</div>
=======
<header>
	<div id="wrap_header">
		<div class="titleHeader">
			<img src="<%=request.getContextPath()%>/resources/static/main.png" id="imgMain" /><br>
		</div>
		<div class="signOut">
		<%
		if (session.getAttribute("u_no") != null) {
		%>
			<span id="myId">&#64;<%=session.getAttribute("u_id")%></span>&nbsp;
			<input type="button" class="signOutBtn" value="Sign Out" id="btnSignOut">
		<%
		}
		%>
		</div>
	</div>
>>>>>>> dfafe29c0482dd92cdc454a767f9bed240e80ae9
>>>>>>> 5aa76ea3a0591d427a636e8d726911934985e0b2
</header>