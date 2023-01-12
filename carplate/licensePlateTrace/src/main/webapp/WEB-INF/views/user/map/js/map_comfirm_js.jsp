<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>

<script src="https://unpkg.com/@googlemaps/markerclusterer/dist/index.min.js"></script>
<script type="text/javascript" >
var malls = {};
var arrays = [];
var reg_date_arrays = [];

$(document).ready(function(){
	console.log("ready() CALLED!");
	
	$('#header_wrap a.map').parent().addClass('selected');
	
	ajax_yearSelect();

	ajax_dbPlateInfos();

});

var markers = [];
function initMap() {
	markers = [];
	console.log("initMap() CALLED!");
	  const map = new google.maps.Map(document.getElementById("map"), {
	    center: { lat: 36.715569, lng: 128.069456 },
	    zoom: 8
	    });
	  
	  // 마커로 위치 표시
	  
	  arrays.forEach(({ label, name, lat, lng, c_no }) => {
		  
		  const contentString =
			  '<div id="content">' +
			    '<h1 id="firstHeading" class="firstHeading">카메라 고유번호: ' + c_no + '</h1>' +
			    '<div id="bodyContent">' +
			    "<p>" + 
			    "<b>위도</b>: " + lat + " <b>경도</b>: " + lng + 
				"<br>" + 
			    "</div>" +
			   "</div>";
			    
		  const infowindow = new google.maps.InfoWindow({
			  content: contentString,
			  ariaLabel: "Test",
		  });
		  
		  const marker = new google.maps.Marker({
			  position: { lat, lng },
		      map: map,
		   });
		
	  // 클릭시 정보 보여주기 이벤트
	  marker.addListener("click", () => {
	    map.panTo(marker.position);		// 지도 중심 이동
		ajax_getPlates(c_no);
		
		infowindow.open({
			anchor: marker, 
			map,
		});
	});
	  
		markers.push(marker);
		// console.log(markers);
	    
});
	// 클러스터링
	const markerCluster = new markerClusterer.MarkerClusterer({ markers, map});
	
}

function ajax_plateSelect(){

	var msg = {
			'year': getYear(),
			'month': getMonth(),
			'day': getDay(),
			'camera': getCamera(),
			'plate': getPlate()
	}
	$.ajax({
		url: '<c:url value="/map/getPlateInfo" />', 
		type: 'POST', 
		data: JSON.stringify(msg), 
		contentType: 'application/json; charset=utf-8;', 
		dataType: 'json',  
		success: function(data) {
			console.log('AJAX SUCCESS - ajax_yearSelect()');
		},
		error: function(data){
			console.log('AJAX FAIL - ajax_yearSelect()');
		}
		
	});
		
}

function ajax_yearSelect(){
	var msg = {
		"plate": getPlate()
	}

	$.ajax({
		url: '<c:url value="/map/getDate" />', 
		type: 'POST', 
		data: JSON.stringify(msg), 
		contentType: 'application/json; charset=utf-8;', 
		dataType: 'json',  
		success: function(data) {
			console.log('AJAX SUCCESS - ajax_yearSelect()');
			
			let mapDateVos = data.MapDateVo;
			
			let map_control = document.querySelector('.map_control');
			map_control.options.length = 0;
			let option = document.createElement('option');
			option.innerText = "--선택--";
			map_control.append(option);
			let text = $('.map_control option:checked').text();
			console.log("text---------> " + text);

			for(let i = 0; i < mapDateVos.length; i++){
				option = document.createElement('option');
				option.innerText = mapDateVos[i];
				map_control.append(option);
				
			}
			ajax_getItems();
		},
		error: function(data) {
			console.log('AJAX FAIL - ajax_yearSelect()');
		}
		
	});
}

function monthSelect() {
	console.log("monthSelect() CALLED!");
	setMonth(null);
	setDay(null);
	let map_control = document.querySelector('.map_control');
	let mainOption = map_control.options[map_control.selectedIndex].innerText;
	console.log("mainOption: \n" + mainOption);

	setYear(mainOption);
	
	var msg = {
			'plate': getPlate(),
			'year': getYear()
		}
		$.ajax({
			url: '<c:url value="/map/monthSelect" />', 
			type: 'POST', 
			data: JSON.stringify(msg), 
			contentType: 'application/json; charset=utf-8;', 
			dataType: 'json',  
			success: function(data){
				console.log('AJAX SUCCESS - monthSelect()');

				if (getYear() == "--선택--"){
					setYear(null);
					ajax_yearSelect();
					return;
				}
				
				let mapDateVos = data.MapDateVo;
				
				let month_control = document.querySelector('.month_control');
				month_control.options.length = 0;
				let option = document.createElement('option');
				option.innerText = "--선택--";
				month_control.append(option);
				clearDay();
				
				for(let i = 0; i < mapDateVos.length; i++){
					option = document.createElement('option');
					option.innerText = mapDateVos[i];
					month_control.append(option);
					
				}
				ajax_getItems();

				},
				error: function(data) {
					console.log('AJAX FAIL - monthSelect()');
					
				}
				
			});
	
	
}

function daySelect(){
	console.log("daySelect() CALLED!");
	
	let month_control = document.querySelector('.month_control');
	setMonth(month_control.options[month_control.selectedIndex].innerText);
	
	console.log("getYear(): \n" + getYear());
	console.log("getMonth(): \n" + getMonth());
		
	var msg = {
			'plate': getPlate(),
			'year': getYear(),
			'month': getMonth()
		}
		$.ajax({
			url: '<c:url value="/map/daySelect" />', 
			type: 'POST', 
			data: JSON.stringify(msg), 
			contentType: 'application/json; charset=utf-8;', 
			dataType: 'json',  
			success: function(data){
				console.log('AJAX SUCCESS - daySelect()');
				
				let mapDateVos = data.MapDateVo;
				
				let day_control = document.querySelector('.day_control');
				day_control.options.length = 0;
				let option = document.createElement('option');
				option.innerText = "--선택--";
				day_control.append(option);
				
				for(let i = 0; i < mapDateVos.length; i++){
					option = document.createElement('option');
					option.innerText = mapDateVos[i];
					day_control.append(option);
					
				}
				ajax_getItems();
				},
				error: function(data) {
					console.log('AJAX FAIL - daySelect()');
					
				}
				
			});
	
}

function daySet(){
	console.log("daySet() CALLED!");
	let day_control = document.querySelector('.day_control');
	setDay(day_control.options[day_control.selectedIndex].innerText);
	console.log(getDay());



	ajax_getItems();
	
}

function plate_info(){
	let plate_info = document.getElementById('l_info').value;
	console.log(plate_info.length);
	setPlate(plate_info);

	if(plate_info.length <= 7 || plate_info.length <= 8){
		clearMonth();
		clearDay();
		setYear(null);
		setDay(null);
		setMonth(null);
		ajax_PlateDB(getPlate());
		ajax_yearSelect();

	}else if (plate_info.length >= 9){
		$('#section_wrap .plat_info input[name="l_info"]').focus();
		$('#section_wrap .plat_info input[name="l_info"]').val('');
		ajax_PlateDB(getPlate());
	}
}

function ajax_getItems() {
console.log('ajax_getDiaryItems() CALLED!!');
arrays.length = 0;
reg_date_arrays.length = 0;

	var msg = {
			'year': getYear(),
			'month': getMonth(),
			'day': getDay(),
			'camera': getCamera(),
			'plate': getPlate()
		}
	$.ajax({
		url: '<c:url value="/map/getItems" />', 
		type: 'POST', 
		data: JSON.stringify(msg), 
		contentType: 'application/json; charset=utf-8;', 
		dataType: 'json',  
		success: function(data) {
			console.log('AJAX SUCCESS - ajax_getItems()');
			
			let mapVos = data.MapVos;
			
			for (let i = 0; i < mapVos.length; i++){
				
				let mapVo = mapVos[i];
				let s_no = mapVo.s_no;
				let s_name = mapVo.s_name;
				let s_info = mapVo.s_info;
				let s_reg_date = mapVo.s_reg_date;
				let s_mod_date = mapVo.s_mod_date;
				
				let l_no = mapVo.l_no;
				let l_info = mapVo.l_info;
				let l_info_reg_date = mapVo.l_info_reg_date;
				let l_img_name = mapVo.l_img_name;
				
				let c_no = mapVo.c_no;
				let c_name = mapVo.c_name;
				let c_latitude = mapVo.c_latitude;
				let c_longitude = mapVo.c_longitude;
				let c_set_date = mapVo.c_set_date;
				
				malls['label'] = s_name;
				malls['name'] = s_name;
				malls['lat'] = c_latitude;
				malls['lng'] = c_longitude;
				malls['c_no'] = c_no;
				
				arrays.push(malls);
				reg_date_arrays.push(l_info_reg_date);
				
				malls = {};
				
			}
			initMap();
		},
		error: function(data) {
			console.log('AJAX FAIL - ajax_getItems()');
		}
	});
}

function add_events(){
	console.log('add_events() CALLED!');

	$('table.plate_list_table td.plate_info a').click(function(){
		console.log('plate_info CLICK EVENT HANDLER!');
		console.log($(this));

		showDetail($(this).data('l_no'), $(this).data('c_no'));
	});

	$('.plate_list_table td.thumnail a').click(function(){
		console.log('thumnail CLICK EVENT HANDLER!');
		console.log($(this));

		showDetail($(this).data('l_no'), $(this).data('c_no'));
	});

	$('#plate_detail_wrap .plate_detail div a.close').click(function(){
		console.log('close CLICK EVENT HANDLER!');

		closeDetail();
	});

}

function ajax_getPlates(c_no){
	console.log("ajax_getPlates CALLED!");
	$('#section_wrap .plate_list_table').remove();

	var msg = {
				'year': getYear(),
				'month': getMonth(),
				'day': getDay(),
				'plate': getPlate(),
				'c_no': c_no,
			}
		$.ajax({
			url: '<c:url value="/map/getPlates" />', 
			type: 'POST', 
			data: JSON.stringify(msg), 
			contentType: 'application/json; charset=utf-8;', 
			dataType: 'json',  
			success: function(data) {
				console.log('AJAX SUCCESS - ajax_getPlates()');


				let mapVos = data.MapVo;
				
				for (let i = 0; i < mapVos.length; i++){
					
					let mapVo = mapVos[i];
					let s_no = mapVo.s_no;
					let s_name = mapVo.s_name;
					let s_info = mapVo.s_info;
					let s_reg_date = mapVo.s_reg_date;
					let s_mod_date = mapVo.s_mod_date;
					
					let l_no = mapVo.l_no;
					let l_info = mapVo.l_info;
					let l_info_reg_date = mapVo.l_info_reg_date;
					let l_img_name = mapVo.l_img_name;
					
					let c_no = mapVo.c_no;
					let c_name = mapVo.c_name;
					let c_latitude = mapVo.c_latitude;
					let c_longitude = mapVo.c_longitude;
					let c_set_date = mapVo.c_set_date;

					let t = document.querySelector('#plate_list_item');
					let clone = document.importNode(t.content, true);

					let clone_table = clone.querySelector("table");
					$(clone_table).attr('id', i);

					$('div.plate_list').append(clone);

					$('#' + i + ' td.date span.year').text(getYear());
					$('#' + i + ' td.date span.month').text(getMonth());
					$('#' + i + ' td.date span.date').text(getDay());
					$('#' + i + ' td.date span.c_no').text("카메라 고유 번호: " + c_no);

					$('#' + i + ' td.plate_info a').text("번호판 : " + s_name + " 범죄명: " + s_info);
					$('#' + i + ' td.thumnail a img').attr('src', "http://192.168.31.135:80/img/" + l_img_name);

					$('#' + i + ' td.plate_info a').data('l_no', l_no); 
					$('#' + i + ' td.plate_info a').data('c_no', c_no); 
					$('#' + i + ' td.thumnail a').data('l_no', l_no);
					$('#' + i + ' td.thumnail a').data('c_no', c_no);
				}
				add_events();
			},
			error: function(data) {
				console.log('AJAX FAIL - ajax_getPlates()');
			}
			
		});

}

function showDetail(l_no, c_no){
	console.log('showDetail() CALLED!!');

	$('#plate_detail_wrap .plate_detail').attr('style', 'display: block;');
	
	ajax_Detail_items(l_no, c_no);

}

function closeDetail(){
	console.log('closeDetail() CALLED!!');

	$('#plate_detail_wrap .plate_detail').attr('style', 'display: none;');
}

function ajax_Detail_items(l_no, c_no){
	console.log("ajax_Detail_items CALLED!");

	var msg = {
				'l_no': l_no,
				'c_no': c_no
			}
		$.ajax({
			url: '<c:url value="/map/getDetailItems" />', 
			type: 'POST', 
			data: JSON.stringify(msg), 
			contentType: 'application/json; charset=utf-8;', 
			dataType: 'json',  
			success: function(data) {
				console.log('AJAX SUCCESS - ajax_Detail_items()');


				let mapVo = data;

				let s_no = mapVo.s_no;
				let s_name = mapVo.s_name;
				let s_info = mapVo.s_info;
				let s_reg_date = mapVo.s_reg_date;
				let s_mod_date = mapVo.s_mod_date;
				
				let l_no = mapVo.l_no;
				let l_info = mapVo.l_info;
				let l_info_reg_date = mapVo.l_info_reg_date;
				let l_img_name = mapVo.l_img_name;
				
				let c_no = mapVo.c_no;
				let c_name = mapVo.c_name;
				let c_latitude = mapVo.c_latitude;
				let c_longitude = mapVo.c_longitude;
				let c_set_date = mapVo.c_set_date;

				$('#plate_detail_wrap div.plate_detail ul li td.s_info').text(s_info);
				$('#plate_detail_wrap div.plate_detail ul li td.c_no').text(c_no);
				$('#plate_detail_wrap div.plate_detail ul li td.s_name').text(s_name);
				$('#plate_detail_wrap div.plate_detail ul li td.s_reg_date').text(s_reg_date);
				$('#plate_detail_wrap div.plate_detail ul li td.l_info_reg_date').text(l_info_reg_date);
				$('#plate_detail_wrap div.plate_detail ul li td.l_img_name a').attr('href', "http://192.168.31.135:80/img/" + l_img_name);
				$('#plate_detail_wrap div.plate_detail ul li td.l_img_name a img').attr('src', "http://192.168.31.135:80/img/" + l_img_name);

			},
			error: function(data) {
				console.log('AJAX FAIL - ajax_Detail_items()');
			}
			
		});
}

function clearMonth() {
	let month_control = document.querySelector('.month_control');
	month_control.options.length = 0;
	let option = document.createElement('option');
	option.innerText = "--선택--";
	month_control.append(option);

}

function clearDay() {
	let day_control = document.querySelector('.day_control');
	day_control.options.length = 0;
	let option = document.createElement('option');
	option.innerText = "--선택--";
	day_control.append(option);
}

function defaultValue() {
	setMonth(null);
	setDay(null);
	setYear(null);
	setCamera(null);
	setPlate(null);
	$('#section_wrap .plat_info input[name="l_info"]').val('');
}

function resetItems() {
	defaultValue();
	malls = {};
	arrays = [];
	ajax_yearSelect();
	clearMonth();
	clearDay();
	$('#section_wrap .plate_list_table').remove();
	closeDetail();
	ajax_dbPlateInfos();
}

function ajax_PlateDB(plate) {
	console.log('ajax_PlateDB() CALLED!');

	var msg = {
		'plate':plate
			}
		$.ajax({
			url: '<c:url value="/map/getPlateDB" />', 
			type: 'POST', 
			data: JSON.stringify(msg), 
			contentType: 'application/json; charset=utf-8;', 
			dataType: 'json',  
			success: function(data) {
				console.log('AJAX SUCCESS - ajax_PlateDB()');
				
				let plateDB = data.mapVos;
				let plateSearched = data.result;	

				if(plateDB.length <= 0){
					alert("번호판이 등록되어 있지 않습니다 등록 후 이용해주세요.");
					$('#section_wrap .plat_info input[name="l_info"]').focus();
					$('#section_wrap .plat_info input[name="l_info"]').val('');
					return;
				}
				if (plateSearched <= 0){
					alert("번호판은 등록 되었으나 검출된 데이터가 없습니다");
				}else{
					alert("검출 완료 되었습니다.");
				}


			},
			error: function(data) {
				console.log('AJAX FAIL - ajax_PlateDB()');
			}
		});

}
 
function plate_selected(){
	console.log("plate_selected() CALLED!");

	let plateInfo = $('#section_wrap div.map_date_write .plate_select option:checked').text();
	if (plateInfo != "--선택--")
		$('#section_wrap .plat_info input[name="l_info"]').val(plateInfo);
	else 
		$('#section_wrap .plat_info input[name="l_info"]').val('');

	
}

function ajax_dbPlateInfos() {
	console.log("ajax_dbPlateInfos() CALLED!");

		$.ajax({
			url: '<c:url value="/map/dbPlateInfos" />', 
			type: 'POST', 
			contentType: 'application/json; charset=utf-8;', 
			dataType: 'json',  
			success: function(data) {
				console.log('AJAX SUCCESS - ajax_dbPlateInfos()');

				let mapVos = data.mapVos;
				
				let plate_select = document.querySelector('.plate_select');
				plate_select.options.length = 0;
				let option = document.createElement('option');
				option.innerText = "--선택--";
				plate_select.append(option);

				for (let i = 0; i < mapVos.length; i++){
					
					let mapVo = mapVos[i];
					let s_no = mapVo.s_no;
					let u_no = mapVo.u_no;
					let s_name = mapVo.s_name;
					let s_info = mapVo.s_info;
					let s_reg_date = mapVo.s_reg_date;
					let s_mod_date = mapVo.s_mod_date;

					option = document.createElement('option');
					option.innerText = s_name;
					plate_select.append(option);
				}
			},
			error: function(data) {
				console.log('AJAX FAIL - ajax_dbPlateInfos()');
			}
		});
}

</script>
<script defer src="https://maps.googleapis.com/maps/api/js?key=AIzaSyBqBEjcit29IHm4FOwN1ouXVxYSEgKcoco&callback=initMap"></script>
