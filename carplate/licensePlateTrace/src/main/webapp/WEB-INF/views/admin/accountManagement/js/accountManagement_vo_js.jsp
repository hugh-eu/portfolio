<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>

<script type="text/javascript">

var pageNum;		// 현재 페이지
var amount;			// 현재 페이지에 출력하려는 아이템 개수

function getPageNum() {
	
	if (pageNum == null || pageNum == undefined || pageNum == '' || pageNum == ' ')
		pageNum = 1;
	
	return pageNum;
}

function setPageNum(p) {
	pageNum = p;
}

function getAmount() {
	
	if (amount == null || amount == undefined || amount == '' || amount == ' ')
		amount = 5;
	
	return amount;
}

function setAmount(p) {
	amount = p;
}

</script>
