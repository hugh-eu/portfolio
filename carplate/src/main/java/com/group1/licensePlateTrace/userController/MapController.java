package com.group1.licensePlateTrace.userController;

import java.util.Map;

import javax.servlet.http.HttpSession;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import com.group1.licensePlateTrace.userService.MapService;
import com.group1.licensePlateTrace.vo.MapVo;

import lombok.extern.slf4j.Slf4j;

@Controller
@RequestMapping("/map")
@Slf4j
public class MapController {

	@Autowired
	MapService mapService;
	
	/*
	 * 지도
	 * */
	@GetMapping("/map_comfirm")
	public String map_comfirm(HttpSession session) {
		log.debug("위치정보확인 요청\n");
		
		String nextPage = "user/map/map_comfirm";
		
		return nextPage;
	}
	
	@PostMapping("/getItems")
	@ResponseBody
	public Object getItems(@RequestBody Map<String, String> msgMap) {
		log.debug("마커 요청\n");
		
		Map<String, Object> map = mapService.getItems(msgMap);
		
		return map;
	}
	
	@PostMapping("/getDate")
	@ResponseBody
	public Object getDate(@RequestBody Map<String, String> msgMap) {
		log.debug("");		
		
		Map<String, Object> map = mapService.getDate(msgMap);
		
		return map;
	}
	
	@PostMapping("/monthSelect")
	@ResponseBody
	public Object monthSelect(@RequestBody Map<String, String> msgMap) {
		log.debug("");
		
		Map<String, Object> map = mapService.monthSelect(msgMap);
		
		return map;
		
	}
	
	@PostMapping("/daySelect")
	@ResponseBody
	public Object daySelect(@RequestBody Map<String, String> msgMap) {
		log.debug("");
		
		Map<String, Object> map = mapService.daySelect(msgMap);
		
		return map;
		
	}
	
	@PostMapping("/getPlates")
	@ResponseBody
	public Object getPlates(@RequestBody Map<String, String> msgMap){
		log.debug("");
		
		Map<String, Object> map = mapService.getPlates(msgMap);
		
		return map;
	}
	
	@PostMapping("/getDetailItems")
	@ResponseBody
	public Object getDetailItems(@RequestBody MapVo mapVo) {
		log.debug("");
		
		Map<String, MapVo> map = mapService.getDetailItems(mapVo);
		
		return map;
		
	}
	
	@PostMapping("/getPlateDB")
	@ResponseBody
	public Map<String, Object> getPlateDB(@RequestBody Map<String, String> msgMap) {
		log.debug("");
		
		Map<String, Object> map = mapService.getPlateDB(msgMap.get("plate"));
		
		return map;
	}
	
	@PostMapping("/dbPlateInfos")
	@ResponseBody
	public Map<String, Object> dbPlateInfos() {
		log.debug("");
		
		Map<String, Object> map = mapService.dbPlateInfos();
		
		return map;
		
	}
	
}
