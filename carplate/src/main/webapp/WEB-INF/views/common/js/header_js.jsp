<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>

<script type="text/javascript">

$(function() {
	
	set_section_footer_width();
    header_events();
})

function set_section_footer_width() {
    $('section').css('width', "calc(100vw - 300px)");
    $('#footer_wrap').css('width', "calc(100vw - 300px)");
}

function header_events() {
    console.log('header_events()');
    
    $(window).resize(function() {
        set_section_footer_width();
    });
}
</script>