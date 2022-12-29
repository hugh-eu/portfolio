package com.hugh.tripist.controller;

import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.List; 

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
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
	public String index(Model model) throws IOException {
		System.out.println("[TripistController] index() called.");
		
		String nextPage = "index";

		String mapApiKey = Files.readString(Paths.get("E:\\Drive\\_dev\\_project\\_private\\tripist\\mapApiKey.txt"));

		model.addAttribute("mapAddress", "https://maps.googleapis.com/maps/api/js?key=" + mapApiKey);
		
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
			
			return TripistService.SIGNIN_SUCCESS;
			
		} else {
			
			return TripistService.SIGNIN_FAIL;
		
		}
		
	}
	

	@PostMapping(value = "/getMarkerList")
	@ResponseBody
	public List<TripistVo> getMarkerList(@RequestBody TripistVo tripistVo) {
		System.out.println("[TripistController] getMarkerList() called.");
		
		return tripistService.getMarkerList(tripistVo);
		
	}
	
	@PostMapping(value = "/modifyMyInfo")
	@ResponseBody
	public int modifyMyInfo(@RequestBody TripistVo tripistVo, HttpSession session) {
		System.out.println("[TripistController] modifyMyInfo() called.");

		int result = tripistService.confirmPwToModify(tripistVo);

		if (result == TripistService.MODIFY_SUCCESS) {
			session.setAttribute("tripistVo", tripistService.getTripistVoForSession(tripistVo.getU_no()));
			session.setMaxInactiveInterval(30 * 60);

		}

		return result;

	}

	@PostMapping(value = "/deleteAccount")
	@ResponseBody
	public int deleteAccount(@RequestBody TripistVo tripistVo, HttpSession session) {
		System.out.println("[TripistController] deleteAccount() called.");

		int result = tripistService.deleteAccount(tripistVo);
		
		if (result == TripistService.WITHDRAWAL_SUCCESS) {
			session.invalidate();

		}

		return result;

	}

	@GetMapping(value = "/signOut")
	public String signOut(HttpSession session) {
		System.out.println("[TripistController] signOut() called.");
		
		String nextPage = "redirect:/";
		
		session.invalidate();
		
		return nextPage;
		
	}

}
