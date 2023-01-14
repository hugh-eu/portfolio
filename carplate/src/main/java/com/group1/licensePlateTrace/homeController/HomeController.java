package com.group1.licensePlateTrace.homeController;

import javax.servlet.http.HttpSession;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

import lombok.extern.slf4j.Slf4j;

@Controller
@Slf4j
public class HomeController {
	
	@RequestMapping(value = {"", "/"}, method = RequestMethod.GET)
	public String home(HttpSession session) {
		log.debug("");
		
		if (session.getAttribute("userVo") == null)
			return "user/login/login";
		
		return "redirect:map/map_comfirm";
	}
}
