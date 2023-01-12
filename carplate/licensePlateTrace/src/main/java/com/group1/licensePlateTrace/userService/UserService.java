package com.group1.licensePlateTrace.userService;

import java.util.HashMap;
import java.util.Map;

import javax.servlet.http.HttpSession;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.group1.licensePlateTrace.userDao.UserDao;
import com.group1.licensePlateTrace.vo.UserVo;

import lombok.extern.slf4j.Slf4j;

@Service
@Slf4j
public class UserService {
	
	@Autowired
	UserDao userDao;

	public Map<String, Object> loginConfirm(UserVo userVo, HttpSession session) {
		log.debug("");
		
		Map<String, Object> map = new HashMap<String, Object>();
		
		if (!userDao.isUser(userVo)) {
			
			map.put("result", "not_exists");
			return map;
		} 
		
		userVo = userDao.loginConfirm(userVo);
		
		if (userVo != null) {
			
			session.setAttribute("userVo", userVo);
			session.setMaxInactiveInterval(60 * 60);
			
			map.put("result", "success");
			
		} else {
			
			map.put("result", "fail");
			
		}
		
		return map;
	}

	public Map<String, Object> registConfirm(UserVo userVo) {
		log.debug("");
		
		Map<String, Object> map = new HashMap<String, Object>();
		
		if (userDao.isUser(userVo)) {
			
			map.put("result", "already_exists");
			return map;
		}
		
		int result = userDao.registConfirm(userVo);
		
		if (result > 0)
			map.put("result", "success");
		else
			map.put("result", "fail");
		
		return map;
	}

	public boolean isUser(HttpSession session) {
		log.debug("");
		
		UserVo userVo = (UserVo)session.getAttribute("userVo");
		if (userVo != null) return true;
		
		return false;
	}

}
