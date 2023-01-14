package com.group1.licensePlateTrace.errorPage;

import org.springframework.http.HttpStatus;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.ControllerAdvice;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.bind.annotation.ResponseStatus;
import org.springframework.web.servlet.NoHandlerFoundException;

import lombok.extern.slf4j.Slf4j;

@ControllerAdvice
@Slf4j
public class ErrorPageController {

	@ExceptionHandler(Exception.class)
	public String handleException(Exception ex, Model model) {
		log.error("Exception 발생 : {}\n", ex.getMessage());
		
		model.addAttribute("msg", "잠시 후 다시 시도해주세요");
		
		return "error/error";
	}
	
	@ExceptionHandler(NoHandlerFoundException.class)
	@ResponseStatus(value = HttpStatus.NOT_FOUND)
	public String handle404(NoHandlerFoundException ex, Model model) {
		log.error("404 에러 발생 : {}\n", ex.getRequestURL());
		
		model.addAttribute("msg", "존재하지 않는 페이지 입니다.");
		
		return "error/error";
	}
	
}
