package com.group1.licensePlateTrace.userDao;

import java.util.List;
import java.util.Map;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.crypto.password.PasswordEncoder;
import org.springframework.stereotype.Component;

import com.group1.licensePlateTrace.paging.Criteria;
import com.group1.licensePlateTrace.userMapper.UserMapper;
import com.group1.licensePlateTrace.vo.UserVo;

import lombok.extern.slf4j.Slf4j;

@Component
@Slf4j
public class UserDao {
	
	@Autowired
	PasswordEncoder passwordEncoder;
	
	@Autowired
	UserMapper userMapper;

	public int registConfirm(UserVo userVo) {
		log.debug("");
		
		int result = 0;
		int tryMaxCnt = 3;
		
		while (tryMaxCnt > 0) {
			
			result = userMapper.insertUserInfo(
											   userVo.getU_id(), 
											   passwordEncoder.encode(userVo.getU_pw()),
											   userVo.getU_name(),
											   userVo.getU_mail(),
											   userVo.getU_phone()
											  );
			
			if (result > 0) return result;
			tryMaxCnt--;
		}
		
		return result;
	}

	public boolean isUser(UserVo userVo) {
		log.debug("");
		
		userVo = userMapper.selectUserById(userVo.getU_id());
		
		if (userVo != null) return true;
		
		return false;
	}

	public UserVo getUserById(UserVo userVo) {
		
		String u_id = userVo.getU_id();
		int tryMaxCnt = 3;
		
		while (tryMaxCnt > 0) {
			
			UserVo tempUserVo = userMapper.selectUserById(u_id);
			
			if (tempUserVo != null) return tempUserVo;
			
			tryMaxCnt--;
		}
		
		return null;
	}

	public UserVo loginConfirm(UserVo userVo) {
		log.debug("");
		
		String u_pw = userVo.getU_pw();
		
		userVo = getUserById(userVo);
		
		if (passwordEncoder.matches(u_pw, userVo.getU_pw())) {
			return userVo;
		}
		
		return null;
	}

	public int getUserListCnt() {
		log.debug("");
		
		int result = 0;
		int tryMaxCnt = 3;

		try {
			
			while (tryMaxCnt > 0) {
				
				result = userMapper.selectAllUsersCnt();
				if (result > 0) return result;
				
				tryMaxCnt--;
			}
			
		} catch (Exception e) {
			log.warn("error: {}\n", e);
		}
		
		return result;
	}
	
	public int getUserListCntByName(Map<String, String> msgMap) {
		log.debug("");
		
		int result = 0;
		int tryMaxCnt = 3;

		try {
			
			while (tryMaxCnt > 0) {
				
				result = userMapper.selectAllUsersCntByName(msgMap.get("u_name"));
				if (result > 0) return result;
				
				tryMaxCnt--;
			}
			
		} catch (Exception e) {
			log.warn("error: {}\n", e);
		}
		
		return result;
	}
	
	public List<UserVo> getUserList(Map<String, String> msgMap, Criteria criteria) {
		log.debug("");
		
		int tryMaxCnt = 3;
		
		while (tryMaxCnt > 0) {
			
			List<UserVo> userVos = userMapper.selectAllUsers(criteria.getSkip(),
															 criteria.getAmount());
			if (userVos.size() > 0) return userVos;
			
			tryMaxCnt--;
		}
		
		return null;
	}
	
	public List<UserVo> getUserListByName(Map<String, String> msgMap, Criteria criteria) {
		log.debug("");
		
		int tryMaxCnt = 3;
		
		while (tryMaxCnt > 0) {
			
			List<UserVo> userVos = userMapper.selectUsersByName(criteria.getSkip(),
															 	criteria.getAmount(),
															 	msgMap.get("u_name"));
			if (userVos.size() > 0) return userVos;
			
			tryMaxCnt--;
		}
		
		return null;
	}

	public int deleteUserConfirm(UserVo userVo) {
		log.debug("");
		
		int result = 0;
		int tryMaxCnt = 3;
		
		while (tryMaxCnt > 0) {
			
			result = userMapper.deleteUser(userVo.getU_no());
			
			if (result > 0) return result;
			
			tryMaxCnt--;
		}
		
		return result;
	}
	
	public int modifyPwConfirm(UserVo userVo) {
		log.debug("");
		
		int result = 0;
		int tryMaxCnt = 3;
		
		while (tryMaxCnt > 0) {
			
			result = userMapper.updateUserPw(userVo.getU_no(), passwordEncoder.encode(userVo.getU_pw()));
			
			if (result > 0) return result;
			
			tryMaxCnt--;
		}
		
		return result;
	}

	public int modifyNameConfirm(UserVo userVo) {
		log.debug("");
		
		int result = 0;
		int tryMaxCnt = 3;
		
		while (tryMaxCnt > 0) {
			
			result = userMapper.updateUserName(userVo.getU_no(), userVo.getU_name());
			
			if (result > 0) return result;
			
			tryMaxCnt--;
		}
		
		return result;
	}
	
	public int modifyMailConfirm(UserVo userVo) {
		log.debug("");
		
		int result = 0;
		int tryMaxCnt = 3;
		
		while (tryMaxCnt > 0) {
			
			result = userMapper.updateUserEmail(userVo.getU_no(), userVo.getU_mail());
			
			if (result > 0) return result;
			
			tryMaxCnt--;
		}
		
		return result;
	}
	
	public int modifyPhoneConfirm(UserVo userVo) {
		log.debug("");
		
		int result = 0;
		int tryMaxCnt = 3;
		
		while (tryMaxCnt > 0) {
			
			result = userMapper.updateUserPhone(userVo.getU_no(), userVo.getU_phone());
			
			if (result > 0) return result;
			
			tryMaxCnt--;
		}
		
		return result;
	}
	
	public int modifyAuthConfirm(UserVo userVo) {
		log.debug("");
		
		int result = 0;
		int tryMaxCnt = 3;
		
		while (tryMaxCnt > 0) {
			
			result = userMapper.updateUserAuth(userVo.getU_no(), userVo.getA_no());
			
			if (result > 0) return result;
			
			tryMaxCnt--;
		}
		
		return result;
	}

}
