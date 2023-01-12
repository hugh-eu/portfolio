package com.group1.licensePlateTrace.adminController;

import java.util.Map;

import javax.servlet.http.HttpSession;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import com.group1.licensePlateTrace.adminService.AdminService;
import com.group1.licensePlateTrace.vo.UserVo;

import lombok.extern.slf4j.Slf4j;

@Controller
@RequestMapping("/admin")
@Slf4j
public class AdminController {

	@Autowired
	AdminService adminService;
	
	/*
	 * 계정 관리 페이지 접속
	 */
	@GetMapping(value = "/accountManagement")
	public String AccountManagement(HttpSession session) {
		log.debug("");
		
		return "/admin/accountManagement/accountManagement";
	}
	
	/*
	 * 계정 목록 가져오기
	 */
	@PostMapping(value = "/getUserList")
	@ResponseBody
	public Object getUserList(@RequestBody Map<String, String> msgMap) {
		log.debug("");
		
		Map<String, Object> map = adminService.getUserList(msgMap);
		
		return map;
	}
	
	/*
	 * 찾는이름을 통해 일치하는 계정 목록 가져오기
	 */
	@PostMapping(value = "/getUserListByName")
	@ResponseBody
	public Object getUserListByName(@RequestBody Map<String, String> msgMap) {
		log.debug("");
		
		Map<String, Object> map = adminService.getUserListByName(msgMap);
		
		return map;
	}
	
	/*
	 * 유저 삭제시키기
	 */
	@PostMapping(value = "/delete_user_confirm")
	@ResponseBody
	public Object deleteUserConfirm(UserVo userVo) {
		log.debug("{}\n", userVo.toString());
		
		Map<String, Object> map = adminService.deleteUserConfirm(userVo);
		
		return map;
	}
	
	/*
	 * 유저 패스워드 변경시키기
	 */
	@PostMapping(value = "/modify_pw_confirm")
	@ResponseBody
	public Object modifyPwConfirm(UserVo userVo) {
		log.debug("{}\n", userVo.toString());
		
		Map<String, Object> map = adminService.modifyPwConfirm(userVo);
		
		return map;
	}
	
	/*
	 * 유저 이름 변경시키기
	 */
	@PostMapping(value = "/modify_name_confirm")
	@ResponseBody
	public Object modifyNameConfirm(UserVo userVo) {
		log.debug("{}\n", userVo.toString());
		
		Map<String, Object> map = adminService.modifyNameConfirm(userVo);
		
		return map;
	}
	
	/*
	 * 유저 메일 변경시키기
	 */
	@PostMapping(value = "/modify_mail_confirm")
	@ResponseBody
	public Object modifyMailConfirm(UserVo userVo) {
		log.debug("{}\n", userVo.toString());
		
		Map<String, Object> map = adminService.modifyMailConfirm(userVo);
		
		return map;
	}
	
	/*
	 * 유저 전화번호 변경시키기
	 */
	@PostMapping(value = "/modify_phone_confirm")
	@ResponseBody
	public Object modifyPhoneConfirm(UserVo userVo) {
		log.debug("{}\n", userVo.toString());
		
		Map<String, Object> map = adminService.modifyPhoneConfirm(userVo);
		
		return map;
	}
	
	/*
	 * 유저 전화번호 변경시키기
	 */
	@PostMapping(value = "/modify_auth_confirm")
	@ResponseBody
	public Object modifyAuthConfirm(UserVo userVo) {
		log.debug("{}\n", userVo.toString());
		
		Map<String, Object> map = adminService.modifyAuthConfirm(userVo);
		
		return map;
	}
	
}
