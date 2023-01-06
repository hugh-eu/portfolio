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
</header>