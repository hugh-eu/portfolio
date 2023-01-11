package com.group1.licensePlateTrace.userController;

import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import com.group1.licensePlateTrace.userService.StreamingService;
import com.group1.licensePlateTrace.vo.StreamingVo;

import lombok.extern.slf4j.Slf4j;

@Controller
@RequestMapping("/streaming")
@Slf4j
public class StreamingController {
	
	
	@Autowired
	StreamingService streamingService;
	
	@GetMapping(value = {"", "/"})
	public String streaming(Model model) {
		log.debug("[StreamingController] streaming() called.\n");
		
		String nextPage = "user/streaming/streaming";
		
		List<StreamingVo> streamingVos = streamingService.getCameraList();
		
		model.addAttribute("streamingVos", streamingVos);
		
		return nextPage;
		
	}
	
	@PostMapping(value = "/setCameraStatus")
	@ResponseBody
	public int setCameraStatus(@RequestBody StreamingVo streamingVo) {
		log.debug("[StreamingController] setCameraStatus() called.\n");
		
		return streamingService.setCameraStatus(streamingVo);
		
	}
	
}
