package com.group1.licensePlateTrace.userDao;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import com.group1.licensePlateTrace.userMapper.StreamingMapper;
import com.group1.licensePlateTrace.vo.StreamingVo;

import lombok.extern.slf4j.Slf4j;

@Component
@Slf4j
public class StreamingDao {
	
	@Autowired
	StreamingMapper streamingMapper;

	public List<StreamingVo> getCameraList() {
		log.debug("[StreamingDao] getCameraList() called.\n");
		
		List<StreamingVo> streamingVos = null;
		
		try {
			streamingVos = streamingMapper.getCameraList();
			
		} catch (Exception e) {
			e.printStackTrace();
			
		}
		
		return streamingVos;
		
	}

	public int setCameraStatus(StreamingVo streamingVo) {
		log.debug("[StreamingDao] setCameraStatus() called.\n");
		
		return streamingMapper.setCameraStatus(streamingVo);
		
	}

	public StreamingVo getIdPw(StreamingVo streamingVo) {
		log.debug("[StreamingDao] getIdPw() called.\n");
		
		return streamingMapper.getIdPw(streamingVo);
		
	}

}
