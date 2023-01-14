package com.group1.licensePlateTrace.adminService;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.servlet.http.HttpSession;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.group1.licensePlateTrace.paging.Criteria;
import com.group1.licensePlateTrace.paging.PageMakerVo;
import com.group1.licensePlateTrace.userDao.UserDao;
import com.group1.licensePlateTrace.vo.UserVo;

import lombok.extern.slf4j.Slf4j;

@Service
@Slf4j
public class AdminService {

	@Autowired
	UserDao userDao;
	
	/*
	 * 어드민 계정인지 체크
	 */
	public boolean isAdmin(HttpSession session) {
		log.debug("");
		
		UserVo userVo = (UserVo)session.getAttribute("userVo");
		if (userVo == null) return false;
		if (userVo.getA_no() != 1) return false;
		
		return true;
	}

	public Map<String, Object> getUserList(Map<String, String> msgMap) {
		log.debug("");
		
		Map<String, Object> map = new HashMap<String, Object>();
		
		Criteria criteria = new Criteria(Integer.parseInt(msgMap.get("pageNum")), 
										 Integer.parseInt(msgMap.get("amount")));
		
		int totalCnt = userDao.getUserListCnt();
		
		PageMakerVo pageMakerVo = new PageMakerVo(criteria, totalCnt);
		List<UserVo> userVos = userDao.getUserList(msgMap, criteria);
		
		map.put("pageMakerVo", pageMakerVo);
		map.put("userVos", userVos);

		return map;
	}
	
	public Map<String, Object> getUserListByName(Map<String, String> msgMap) {
		log.debug("");
		
		Map<String, Object> map = new HashMap<String, Object>();
		
		Criteria criteria = new Criteria(Integer.parseInt(msgMap.get("pageNum")), 
										 Integer.parseInt(msgMap.get("amount")));
		
		int totalCnt = userDao.getUserListCntByName(msgMap);
		
		PageMakerVo pageMakerVo = new PageMakerVo(criteria, totalCnt);
		List<UserVo> userVos = userDao.getUserListByName(msgMap, criteria);
		
		map.put("pageMakerVo", pageMakerVo);
		map.put("userVos", userVos);

		return map;
	}
	
	public Map<String, Object> deleteUserConfirm(UserVo userVo) {
		log.debug("");
		
		Map<String, Object> map = new HashMap<String, Object>();
		int result = userDao.deleteUserConfirm(userVo);

		if (result > 0) map.put("result", "success");
		else map.put("result", "fail");
		
		return map;
	}

	public Map<String, Object> modifyPwConfirm(UserVo userVo) {
		log.debug("");
		
		Map<String, Object> map = new HashMap<String, Object>();
		int result = userDao.modifyPwConfirm(userVo);

		if (result > 0) map.put("result", "success");
		else map.put("result", "fail");
		
		return map;
	}
	
	public Map<String, Object> modifyNameConfirm(UserVo userVo) {
		log.debug("");
		
		Map<String, Object> map = new HashMap<String, Object>();
		int result = userDao.modifyNameConfirm(userVo);

		if (result > 0) map.put("result", "success");
		else map.put("result", "fail");
		
		return map;
	}

	public Map<String, Object> modifyMailConfirm(UserVo userVo) {
		log.debug("");
		
		Map<String, Object> map = new HashMap<String, Object>();
		int result = userDao.modifyMailConfirm(userVo);

		if (result > 0) map.put("result", "success");
		else map.put("result", "fail");
		
		return map;
	}

	public Map<String, Object> modifyPhoneConfirm(UserVo userVo) {
		log.debug("");
		
		Map<String, Object> map = new HashMap<String, Object>();
		int result = userDao.modifyPhoneConfirm(userVo);

		if (result > 0) map.put("result", "success");
		else map.put("result", "fail");
		
		return map;
	}

	public Map<String, Object> modifyAuthConfirm(UserVo userVo) {
		log.debug("");
		
		Map<String, Object> map = new HashMap<String, Object>();
		int result = userDao.modifyAuthConfirm(userVo);

		if (result > 0) map.put("result", "success");
		else map.put("result", "fail");
		
		return map;
	}

}
