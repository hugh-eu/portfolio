package com.group1.licensePlateTrace.userService;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.group1.licensePlateTrace.userDao.StreamingDao;
import com.group1.licensePlateTrace.vo.StreamingVo;
import com.jcraft.jsch.Channel;
import com.jcraft.jsch.ChannelExec;
import com.jcraft.jsch.JSch;
import com.jcraft.jsch.Session;

import lombok.extern.slf4j.Slf4j;

@Service
@Slf4j
public class StreamingService {

	@Autowired
	StreamingDao streamingDao;

	public List<StreamingVo> getCameraList() {
		log.debug("[StreamingService] getCameraList() called.\n");
		
		return streamingDao.getCameraList();
		
	}

	
	public int sendCommand(String deviceIp, int devicePort, String deviceUser, String devicePassword, String strCmd) {
		log.debug("[StreamingService] sendCommand() called.\n");
		
		Session jschSession = null;
		Channel jschChannel = null;
		
		try {
			log.debug("[StreamingService] Connecting to " + deviceIp + "\n");
			
			JSch jsch = new JSch();
			jschSession = jsch.getSession(deviceUser, deviceIp, devicePort);
			jschSession.setPassword(devicePassword);
			java.util.Properties config = new java.util.Properties();
			config.put("StrictHostKeyChecking", "no");
			jschSession.setConfig(config);
			jschSession.connect();
			
			log.debug("[StreamingService] Connected to " + deviceIp + "\n");
			
			jschChannel = jschSession.openChannel("exec");
			ChannelExec channelExec = (ChannelExec)jschChannel;
			channelExec.setCommand(strCmd);
			channelExec.connect();
			

			
			return 1;
			
		} catch (Exception e) {
			e.printStackTrace();
			
			return 0;
			
		} finally {
			if (jschChannel != null) {
				jschChannel.disconnect();
				
			}
			
			if (jschSession != null) {
				jschSession.disconnect();
				
			}
			
		}
		
	}
	
	
	public int setCameraStatus(StreamingVo streamingVo) {
		log.debug("[StreamingService] setCameraStatus() called.\n");
		
		String deviceIp = streamingVo.getC_ip();
		int devicePort = streamingVo.getC_port();
		
		StreamingVo idPwToCtlVo = streamingDao.getIdPw(streamingVo);
		String deviceUser = idPwToCtlVo.getC_id();
		String devicePassword = idPwToCtlVo.getC_pw();
		
		String strCmd = "";
		int result = 0;
		
		if (streamingVo.getC_status().equals("1")) {
			strCmd = "sh /home/" + deviceUser + "/mjpg.sh";
			result += sendCommand(deviceIp, devicePort, deviceUser, devicePassword, strCmd);
			strCmd = "sh /home/" + deviceUser + "/carplate.sh";
			result += sendCommand(deviceIp, devicePort, deviceUser, devicePassword, strCmd);
			
		} else {
			strCmd = "ps -ef | grep carplate | grep -v grep | awk '{print $2}' | xargs kill -9";
			result += sendCommand(deviceIp, devicePort, deviceUser, devicePassword, strCmd);
			strCmd = "ps -ef | grep mjpg | grep -v grep | awk '{print $2}' | xargs kill -9";
			result += sendCommand(deviceIp, devicePort, deviceUser, devicePassword, strCmd);
			
		}
		
		if (result == 2) {
			
			return streamingDao.setCameraStatus(streamingVo);
			
		} else {
			
			return -1;
			
		}
		
	}
	
}
