package com.group1.licensePlateTrace.userService;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import javax.servlet.http.HttpSession;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.group1.licensePlateTrace.paging.Criteria;
import com.group1.licensePlateTrace.paging.PageMakerVo;
import com.group1.licensePlateTrace.userDao.LicensePlateDao;
import com.group1.licensePlateTrace.vo.LicensePlateVo;
import com.group1.licensePlateTrace.vo.UserVo;

import lombok.extern.slf4j.Slf4j;

@Service
@Slf4j
public class LicensePlateService {
	
	@Autowired
	private UserService userService;
	
	@Autowired
	private LicensePlateDao licensePlateDao;
	
	public Map<String, Object> licensePlateRegistConfirm(LicensePlateVo licensePlateVo, HttpSession session) {
		log.debug("");
		
		Map<String, Object> map = new HashMap<String, Object>();
		
		if (!userService.isUser(session)) {
			
			map.put("result", "not_logined");
			return map;
		}
		
		if (licensePlateDao.isLicensePlate(licensePlateVo)) {
			
			map.put("result", "already_exists");
			return map;
		}
		
		int result = licensePlateDao.licensePlateRegistConfirm(licensePlateVo, 
															   ((UserVo)session.getAttribute("userVo")).getU_no());
		
		if (result > 0) map.put("result", "success");
		else map.put("result", "fail");
		
		return map;
	}

	public Map<String, Object> getlicensePlateList(Map<String, String> msgMap) {
		log.debug("");

		Map<String, Object> map = new HashMap<String, Object>();
		
		Criteria criteria = new Criteria(Integer.parseInt(msgMap.get("pageNum")), 
				 						 Integer.parseInt(msgMap.get("amount")));
		
		int totalCnt = licensePlateDao.getlicensePlateListCnt(msgMap);
		
		PageMakerVo pageMakerVo = new PageMakerVo(criteria, totalCnt);
		List<LicensePlateVo> licensePlateVos = licensePlateDao.getlicensePlateList(msgMap, criteria);
		
		map.put("pageMakerVo", pageMakerVo);
		map.put("licensePlateVos", licensePlateVos);
		
		return map;
	}

	public Map<String, Object> deleteLicensePlateConfirm(LicensePlateVo licensePlateVo) {
		log.debug("");
		
		Map<String, Object> map = new HashMap<String, Object>();
		int result = licensePlateDao.deleteLicensePlateConfirm(licensePlateVo);

		if (result > 0) map.put("result", "success");
		else map.put("result", "fail");
		
		return map;
	}

	public Map<String, Object> modifyLicensePlateConfirm(LicensePlateVo licensePlateVo) {
		log.debug("");
		
		Map<String, Object> map = new HashMap<String, Object>();
		int result = licensePlateDao.modifyLicensePlateConfirm(licensePlateVo);

		if (result > 0) map.put("result", "success");
		else map.put("result", "fail");
		
		return map;
	}

}
