package com.hugh.tripist.service;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.hugh.tripist.dao.ITripistDao;
import com.hugh.tripist.vo.TripistVo;

@Service
public class TripistService {
	public static final int DUPLICATE_ID = -1;

	public static final int SIGNIN_SUCCESS = 1;
	public static final int SIGNIN_FAIL = 0;

	public static final int MODIFY_SUCCESS = 1;
	public static final int MODIFY_FAIL = 0;

	public static final int WITHDRAWAL_SUCCESS = 1;
	public static final int WITHDRAWAL_FAIL = 0;

	public static final int CORRECT_PASSWORD = 1;
	public static final int WRONG_PASSWORD = -1;

	@Autowired
	private ITripistDao tripistDao;

	public int confirmSignUp(TripistVo tripistVo) {
		System.out.println("[TripistService] confirmSignUp() called.");
		
		TripistVo resultVo = tripistDao.confirmSignUp(tripistVo);
		
		if (resultVo == null) {
			
			int result = tripistDao.addUser(tripistVo);
			
			return result;
			
		} else {
			
			return DUPLICATE_ID;
			
		}
		
	}

	public TripistVo confirmSignIn(TripistVo tripistVo) {
		System.out.println("[TripistService] confirmSignIn() called.");
		
		return tripistDao.confirmSignIn(tripistVo);
		
	}

	public List<TripistVo> getMarkerList(TripistVo tripistVo) {
		System.out.println("[TripistService] getMarkerList() called.");
		
		return tripistDao.getMarkerList(tripistVo);
		
	}

    public int confirmPwToModify(TripistVo tripistVo) {
		System.out.println("[TripistService] confirmPwToModify() called.");

		TripistVo resultVo = tripistDao.confirmPwToModify(tripistVo);

		if (resultVo != null) {
			if (tripistVo.getU_new_pw() != "") {
				tripistVo.setU_pw(tripistVo.getU_new_pw());
				tripistVo.setU_new_pw("");

			}

			Map<String, Object> map = new HashMap<>();
			map.put("u_no", tripistVo.getU_no());
			map.put("u_pw", tripistVo.getU_pw());
			map.put("u_email", tripistVo.getU_email());

			return tripistDao.modifyMyInfo(map);
			
		} else {
			
			return WRONG_PASSWORD;
			
		}

    }

	public TripistVo getTripistVoForSession(int u_no) {
		System.out.println("[TripistService] getTripistVoForSession() called.");

		return tripistDao.getTripistVoForSession(u_no);

	}

	public int deleteAccount(TripistVo tripistVo) {
		System.out.println("[TripistService] deleteAccount() called.");

		TripistVo resultVo = tripistDao.confirmPwToDelete(tripistVo);

		if (resultVo != null) {

			return tripistDao.deleteAccount(tripistVo.getU_no());

		} else {

			return WRONG_PASSWORD;

		}


	}

	public int insertMarkerInfo(TripistVo tripistVo) {
		System.out.println("[TripistService] insertMarkerInfo() called.");

		Map<String, Object> map = new HashMap<>();
		map.put("u_no", tripistVo.getU_no());
		map.put("m_lat", tripistVo.getM_lat());
		map.put("m_lng", tripistVo.getM_lng());
		map.put("m_location", tripistVo.getM_location());
		map.put("m_period", tripistVo.getM_period());
		map.put("m_cost", tripistVo.getM_cost());
		map.put("m_contents", tripistVo.getM_contents());
		map.put("m_img_name", tripistVo.getM_img_name());

		return tripistDao.insertMarkerInfo(map);

	}

	public TripistVo getMarkerInfo(TripistVo tripistVo) {
		System.out.println("[TripistService] getMarkerInfo() called.");

		return tripistDao.getMarkerInfo(tripistVo);

	}

	public int modifyMarkerInfo(TripistVo tripistVo) {
		System.out.println("[TripistService] modifyMarkerInfo() called.");

		Map<String, Object> map = new HashMap<>();
		map.put("m_no", tripistVo.getM_no());
		map.put("m_location", tripistVo.getM_location());
		map.put("m_period", tripistVo.getM_period());
		map.put("m_cost", tripistVo.getM_cost());
		map.put("m_contents", tripistVo.getM_contents());
		map.put("m_img_name", tripistVo.getM_img_name());

		return tripistDao.modifyMarkerInfo(map);

	}

    public int deleteMarkerInfo(TripistVo tripistVo) {
        System.out.println("[TripistService] deleteMarkerInfo() called.");

		return tripistDao.deleteMarkerInfo(tripistVo);

    }
	

}
