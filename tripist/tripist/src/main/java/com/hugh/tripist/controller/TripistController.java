package com.hugh.tripist.controller;

import java.util.List;
import java.util.Map;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.ResponseBody;

import com.hugh.tripist.service.TripistService;
import com.hugh.tripist.vo.TripistVo;

import jakarta.servlet.http.HttpSession;

@Controller
public class TripistController {
	
	@Autowired
	private TripistService tripistService;
	
	
	@GetMapping(value = {"", "/"})
	public String index() {
		System.out.println("[TripistController] index() called.");
		
		String nextPage = "index";
		
		return nextPage;
		
	}
	
	@PostMapping(value = "/confirmSignUp")
	@ResponseBody
	public int confirmSignUp(@RequestBody TripistVo tripistVo) {
		System.out.println("[TripistController] confirmSignUp() called.");
		
		return tripistService.confirmSignUp(tripistVo);
		
	}
	
	@PostMapping(value = "/confirmSignIn")
	@ResponseBody
	public int confirmSignIn(@RequestBody TripistVo tripistVo, HttpSession session) {
		System.out.println("[TripistController] confirmSignIn() called.");
		
		TripistVo resultVo = tripistService.confirmSignIn(tripistVo);
		
		if (resultVo != null) {
			session.setAttribute("tripistVo", resultVo);
			session.setMaxInactiveInterval(30 * 60);
			
			return 1;
			
		} else {
			
			return 0;
		
		}
		
	}
	

	@PostMapping(value = "/getMarkerList")
	@ResponseBody
	public List<TripistVo> getMarkerList(@RequestBody Map<String, Object> map) {
		System.out.println("[TripistController] getMarkerList() called.");
		
		System.out.println(map);
		
		return tripistService.getMarkerList(map.get("tripistVo"));
		
	}
	
	
	@GetMapping(value = "/signOut")
	public String signOut(HttpSession session) {
		System.out.println("[TripistController] signOut() called.");
		
		String nextPage = "redirect:/";
		
		session.invalidate();
		
		return nextPage;
		
	}

}
