package com.group1.licensePlateTrace.userDao;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import com.group1.licensePlateTrace.paging.Criteria;
import com.group1.licensePlateTrace.userMapper.LicensePlateMapper;
import com.group1.licensePlateTrace.vo.LicensePlateVo;

import lombok.extern.slf4j.Slf4j;

@Component
@Slf4j
public class LicensePlateDao {
	
	@Autowired
	LicensePlateMapper licensePlateMapper;
	
	public int licensePlateRegistConfirm(LicensePlateVo licensePlateVo, int u_no) {
		log.debug("");
		
		int result = 0;
		int tryMaxCnt = 3;
		
		while (tryMaxCnt > 0) {
			
			result = licensePlateMapper.insertLicensePlate(licensePlateVo.getS_name(),
												  		   licensePlateVo.getS_info(),
												  		   u_no);
			
			if (result > 0) return result;
			tryMaxCnt--;
		}
		
		return result;
	}

	public int getlicensePlateListCnt(Map<String, String> msgMap) {
		log.debug("");
		
		int u_no = Integer.parseInt(msgMap.get("u_no"));
		String licensePlateName = msgMap.get("licensePlateName");
		int result = 0;
		int tryMaxCnt = 3;

		try {
			
			while (tryMaxCnt > 0) {
				
				if (licensePlateName == "")
					result = licensePlateMapper.selectAllLicensePlateCnt();
				else
					result = licensePlateMapper.selectAllLicensePlateCntByName(licensePlateName);
					
				if (result > 0) return result;
				
				tryMaxCnt--;
			}
			
		} catch (Exception e) {
			log.warn("error: {}\n", e);
		}
		
		return result;
	}

	public List<LicensePlateVo> getlicensePlateList(Map<String, String> msgMap, Criteria criteria) {
		log.debug("");
		
		int u_no = Integer.parseInt(msgMap.get("u_no"));
		String order = msgMap.get("order");
		String licensePlateName = msgMap.get("licensePlateName");
		
		List<LicensePlateVo> licensePlateVos = new ArrayList<>();
		int tryMaxCnt = 3;
		
		while (tryMaxCnt > 0) {
			
			if (order.equals("DESC") && licensePlateName == "") {
				licensePlateVos = licensePlateMapper.selectAllLicensePlateDESC(criteria.getSkip(),
																			   criteria.getAmount());
			}
			
			if (order.equals("ASC") && licensePlateName == "") {
				
				licensePlateVos = licensePlateMapper.selectAllLicensePlateASC(criteria.getSkip(),
																			   criteria.getAmount());
			}
			
			if (order.equals("DESC") && licensePlateName != "") {
				
				licensePlateVos = licensePlateMapper.selectAllLicensePlateDESCByName(criteria.getSkip(),
																					 criteria.getAmount(),
																					 licensePlateName);
			}
			
			if (order.equals("ASC") && licensePlateName != "") {
				
				licensePlateVos = licensePlateMapper.selectAllLicensePlateASCByName(criteria.getSkip(),
																					 criteria.getAmount(),
																					 licensePlateName);
			}
			
			if (licensePlateVos.size() > 0) return licensePlateVos;
			
			tryMaxCnt--;
		}
		
		return null;
	}

	public int deleteLicensePlateConfirm(LicensePlateVo licensePlateVo) {
		log.debug("");
		
		int result = 0;
		int tryMaxCnt = 3;
		
		while (tryMaxCnt > 0) {
			
			result = licensePlateMapper.deleteLicensePlate(licensePlateVo.getS_no());
			
			if (result > 0) return result;
			
			tryMaxCnt--;
		}
		
		return result;
	}

	public int modifyLicensePlateConfirm(LicensePlateVo licensePlateVo) {
		log.debug("");
		
		int result = 0;
		int tryMaxCnt = 3;
		
		while (tryMaxCnt > 0) {
			
			result = licensePlateMapper.updateLicensePlateInfo(licensePlateVo.getS_no(), licensePlateVo.getS_info());
			
			if (result > 0) return result;
			
			tryMaxCnt--;
		}
		
		return result;
	}

	public boolean isLicensePlate(LicensePlateVo licensePlateVo) {
		log.debug("");
		
		int result = -1;
		int tryMaxCnt = 3;
		
		while (tryMaxCnt > 0) {
			
			result = licensePlateMapper.selectLicensePlateCnt(licensePlateVo.getS_name());
			
			if (result > 0) return true;
			tryMaxCnt--;
		}
		
		return false;
	}

}
