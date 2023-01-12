package com.group1.licensePlateTrace.userController;

import java.util.Map;

import javax.servlet.http.HttpSession;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import com.group1.licensePlateTrace.userService.LicensePlateService;
import com.group1.licensePlateTrace.userService.UserService;
import com.group1.licensePlateTrace.vo.LicensePlateVo;

import lombok.extern.slf4j.Slf4j;

@Controller
@RequestMapping("/licensePlate")
@Slf4j
public class LicensePlateController {
	
	@Autowired
	UserService userService;
	
	@Autowired
	LicensePlateService licensePlateService;

	/*
	 * 번호판 등록 페이지
	 */
	@GetMapping(value = {"", "/"})
	public String home(HttpSession session) {
		log.debug("");
		
		return "user/licensePlate/licensePlate";
	}
	
	/*
	 * 번호판 등록
	 */
	@PostMapping(value = "/licensePlateRegistConfirm")
	@ResponseBody
	public Object licensePlateRegistConfirm(LicensePlateVo licensePlateVo, HttpSession session) {
		log.debug("{}\n", licensePlateVo.toString());
		
		Map<String, Object> map = licensePlateService.licensePlateRegistConfirm(licensePlateVo, session);
		
		return map;
	}
	
	/*
	 * 번호판 목록 가져오기
	 */
	@PostMapping(value = "/getlicensePlateList")
	@ResponseBody
	public Object getlicensePlateList(@RequestBody Map<String, String> msgMap) {
		log.debug("<= {}\n", msgMap);
		
		Map<String, Object> map = licensePlateService.getlicensePlateList(msgMap);
		
		return map;
	}
	
	/*
	 * 번호판 삭제
	 */
	@PostMapping(value = "/delete_licensePlate_confirm")
	@ResponseBody
	public Object deleteLicensePlateConfirm(LicensePlateVo licensePlateVo) {
		log.debug("s_no = {}\n", licensePlateVo.getS_no());
		
		Map<String, Object> map = licensePlateService.deleteLicensePlateConfirm(licensePlateVo);
		
		return map;
	}
	
	/*
	 * 번호판 내용 변경
	 */
	@PostMapping(value = "/modify_licensePlate_confirm")
	@ResponseBody
	public Object modifyLicensePlateConfirm(LicensePlateVo licensePlateVo) {
		log.debug("{}\n", licensePlateVo.toString());
		
		Map<String, Object> map = licensePlateService.modifyLicensePlateConfirm(licensePlateVo);
		
		return map;
	}
	
}
