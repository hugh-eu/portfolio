package com.office.thymeleafex.controller;

import java.util.HashMap;
import java.util.Map;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;

@Controller
public class SportsController {
	
	@GetMapping(value = {"", "/", "/getSports"})
	public String getSports(Model model) {
		System.out.println("[SportsController] getSports() called.");
		
		Map<String, String> map = new HashMap<>();
		map.put("a", "a");
		map.put("b", "b");
		map.put("c", "c");
		
		model.addAttribute("data", map);
		
		return "index";
	}

}
