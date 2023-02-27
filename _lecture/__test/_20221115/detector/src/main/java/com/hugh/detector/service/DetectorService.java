package com.hugh.detector.service;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.hugh.detector.dao.DetectorDao;
import com.hugh.detector.vo.DetectorVo;

@Service
public class DetectorService {

	@Autowired
	private DetectorDao detectorDao;
	
	final public static int SIGNUP_SUCCESS = 1;
	final public static int SIGNUP_FAIL = 0;
	final public static int SIGNUP_DUPLICATE  = -1;
	
	public DetectorVo confirmLogin(DetectorVo detectorVo) {
		System.out.println("[DetectorService] confirmLogin() called.");
		
		return detectorDao.confirmLogin(detectorVo);
	}

	public int confirmSignUp(DetectorVo detectorVo) {
		System.out.println("[DetectorService] confirmSignUp() called.");
		
		return detectorDao.confirmSignUp(detectorVo);
	
	}

	public List<DetectorVo> getDetectedList() {
		System.out.println("[DetectorService] confirmSignUp() called.");
		
		return detectorDao.getDetectedList();
	}

	public List<DetectorVo> getUserList() {
		System.out.println("[DetectorService] getUserList() called.");
		
		return detectorDao.getUserList();
	}

	public List<DetectorVo> changeAuth(int u_no, String u_auth) {
		System.out.println("[DetectorService] changeAuth() called.");
		
		return detectorDao.changeAuth(u_no, u_auth);
	}

}
