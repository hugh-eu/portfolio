<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>

<script>

$(function() {

	$('#header_wrap a.streaming').parent().addClass('selected');
	addCameraList();
})

function addCameraList() {
	
	$(".cameraEach").click(function(){
		let c_no = $(this).data("c_no");
		let c_name = $(this).data("c_name");
		let c_latitude = $(this).data("c_latitude");
		let c_longitude = $(this).data("c_longitude");
		let c_ip = $(this).data("c_ip");
		let c_port = $(this).data("c_port");
		let c_status = $(this).data("c_status");
		let strOriginal = ""
		
		if (c_status == "1") {
			strOriginal = "<img src='http://" + c_ip + ":9090/?action=stream'>";
			
		} else {
			strOriginal = "<span class='cameraNoSignal'>No signal.</span>"
			
		}
		
		let strInfo = "";
			strInfo += "<tr>";
			strInfo += 		"<td>Device</td><td>" + c_name + "</td>";
			strInfo += "</tr>";
			strInfo += "<tr>";
			strInfo += 		"<td>Lat</td><td>" + c_latitude + "</td>";
			strInfo += "</tr>";
			strInfo += "<tr>";
			strInfo += 		"<td>Lon</td><td>" + c_longitude + "</td>";
			strInfo += "</tr>";
			strInfo += "<tr>";
			strInfo += 		"<td>IP</td><td>" + c_ip + "</td>";
			strInfo += "</tr>";
			strInfo += "<tr>";
			strInfo += 		"<td>Port</td><td>" + c_port + "</td>";
			strInfo += "</tr>";
		
		if (c_status == "0") {
			$("#cameraToggleSwitch").removeClass("active");
			$("#cameraToggleButton").removeClass("active");
			
		} else {
			$("#cameraToggleSwitch").addClass("active");
			$("#cameraToggleButton").addClass("active");
			
		}
		
		$("#cameraOriginal").append(strOriginal);
		$("#cameraInfo").append(strInfo);
		
		$("body").css("overflow", "hidden");
		$("#cameraDetailBack").fadeIn(500);
		
		$("#cameraToggleSwitch").click(function() {
			if ($("#cameraToggleSwitch").hasClass("active")) {				
				c_status = "0";
				
			} else {				
				c_status = "1";
				
			}
			
			$.ajax({
				url : "<c:url value='/streaming/setCameraStatus' />",
				type : "POST",
				data : JSON.stringify({
					"c_no": c_no,
					"c_ip": c_ip,
					"c_port": c_port,
					"c_status": c_status

				}),
				contentType : "application/json",
				success : function(result) {
					if (result > 0) {
						if ($("#cameraToggleSwitch").hasClass("active")) {
							$("#cameraToggleSwitch").removeClass("active");
							$("#cameraToggleButton").removeClass("active");
							
							$("#cameraOriginal").empty();
							$("#cameraOriginal").append("<span class='cameraNoSignal'>No signal.</span>");
							
						} else {
							$("#cameraToggleSwitch").addClass("active");
							$("#cameraToggleButton").addClass("active");
							
							strOriginal = "<img src='http://" + c_ip + ":9090/?action=stream'>";
							$("#cameraOriginal").empty();
							$("#cameraOriginal").append(strOriginal);
							
						}
						
					} else {
						if ($("#cameraToggleSwitch").hasClass("active")) {
							c_status = "1";
							
						} else {
							c_status = "0";
							
						}
					}
				},
				error : function(request, status, error){
					console.log("code : " + request.status);
					console.log("message : " + request.responseText);
					console.log("error : " + error);

				}
				
			});
			
		});
		
	});
	
	$(document).on('click', '#cameraDetailBack', function() {
		console.log('cameraDetailBack click');

		location.href='<c:url value="/streaming" />';
	});
	
}

</script>