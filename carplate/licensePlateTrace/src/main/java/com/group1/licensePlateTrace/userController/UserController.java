package com.group1.licensePlateTrace.userController;

import java.util.Map;

import javax.servlet.http.HttpSession;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;

import com.group1.licensePlateTrace.userService.UserService;
import com.group1.licensePlateTrace.vo.UserVo;

import lombok.extern.slf4j.Slf4j;

@Controller
@RequestMapping("/user")
@Slf4j
public class UserController {
	
	@Autowired
	UserService userService;

	/*
	 * 로그인 페이지
	 */
	@GetMapping("/loginForm")
	public String loginForm(HttpSession session) {
		log.debug("");
		
		if (session.getAttribute("userVo") != null)
			return "redirect:/";
		
		return "user/login/login";
	}
	
	/*
	 * 로그인
	 */
	@PostMapping(value = "/login_confirm")
	@ResponseBody
	public Object loginConfirm(UserVo userVo, HttpSession session) {
		log.debug("로그인 요청 : {}\n", userVo.toString());
		
		Map<String, Object> map = userService.loginConfirm(userVo, session);
		
		return map;
	}
	
	/*
	 * 로그아웃
	 */
	@GetMapping(value = "/logout_confirm")
	public String logoutConfirm(HttpSession session) {
		log.debug("로그아웃 요청");
		
		session.invalidate();
		
		return "redirect:/";
	}
	
	/*
	 * 계정생성
	 */
	@PostMapping(value = "/regist_confirm")
	@ResponseBody
	public Object registConfirm(UserVo userVo) {
		log.debug("계정등록 요청 : {}\n", userVo.toString());
		
		Map<String, Object> map = userService.registConfirm(userVo);
		
		return map;
	}
	
}
