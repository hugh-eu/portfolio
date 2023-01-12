<%@page import="com.group1.licensePlateTrace.vo.MapVo"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>

<script type="text/javascript">

var year;
var month;
var day;
var camera;
var plate;

function getYear(){
	
	if(year == null || year == undefined || year == '' || year == ' '){
	year = null;
	}
	return year;
	
}

function setYear(y){
	year = y;
}

function getMonth(){
	
	if(month == null || month == undefined || month == '' || month == ' '){
	month = null;
	}
	return month;
	
}

function setMonth(m){
	month = m;
}

function getDay(){
	
	if(day == null || day == undefined || day == '' || day == ' '){
	day = null;
	}
	return day;
	
}

function setDay(d){
	day = d;
}

function getCamera(){
	
	if(camera == null || camera == undefined || camera == '' || camera == ' '){
	camera = null;
	}
	return camera;
	
}

function setCamera(c){
	camera = c;
}

function getPlate(){
	
	if(plate == null || plate == undefined || plate == '' || plate == ' '){
		plate = null;
		}
		return plate;
}

function setPlate(p){
	plate = p;
}

</script>