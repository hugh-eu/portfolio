package com.hugh.tripist.service;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.hugh.tripist.dao.ITripistDao;
import com.hugh.tripist.vo.TripistVo;

@Service
public class TripistService {
	
	@Autowired
	private ITripistDao tripistDao;

	public int confirmSignUp(TripistVo tripistVo) {
		System.out.println("[TripistService] confirmSignUp() called.");
		
		List<TripistVo> tripistVos = tripistDao.confirmSignUp(tripistVo);
		
		if (tripistVos.size() == 0) {
			
			int result = tripistDao.addUser(tripistVo);
			
			return result;
			
		} else {
			
			return -1;
			
		}
		
	}

	public TripistVo confirmSignIn(TripistVo tripistVo) {
		System.out.println("[TripistService] confirmSignIn() called.");
		
		List<TripistVo> tripistVos = tripistDao.confirmSignIn(tripistVo);
		
		if (tripistVos.size() > 0) {
			
			return tripistVos.get(0);
			
		} else {
			
			return null;
			
		}
		
	}

	public List<TripistVo> getMarkerList(Object object) {
		System.out.println("[TripistService] getMarkerList() called.");
		
		return tripistDao.getMarkerList(object);
		
	}
	

}
