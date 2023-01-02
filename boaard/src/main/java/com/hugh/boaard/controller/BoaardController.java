package com.hugh.boaard.controller;

import java.io.IOException;
import java.io.PrintWriter;
import java.util.List;
import java.util.Map;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

import com.hugh.boaard.service.BoaardService;
import com.hugh.boaard.vo.BoaardVo;

@Controller
public class BoaardController {
	
	@Autowired
	BoaardService boaardService;
	
	@Autowired
	BCryptPasswordEncoder passEncoder;
	
	@RequestMapping(value = {"", "/"}, method = RequestMethod.GET)
	public String signIn(HttpSession session) {
		System.out.println("[Controller] signIn() called.");
		
		String nextPage = "sign_in";
		
		session.invalidate();
		
		return nextPage;
		
	}
	
	@RequestMapping(value = "/signUp", method = RequestMethod.GET)
	public String signUp() {
		System.out.println("[Controller] signUp() called.");
		
		String nextPage = "sign_up";
		
		return nextPage;
		
	}
	
	@RequestMapping(value = "/confirmSignUp", method = RequestMethod.POST)
	public String confirmSignUp(BoaardVo boaardVo, HttpServletResponse response) throws IOException {
		System.out.println("[Controller] confirmSignUp() called.");
		
		String nextPage = "sign_in";
		
		boaardVo.setU_pw(passEncoder.encode(boaardVo.getU_pw()));
		
		int result = boaardService.confirmSignUp(boaardVo);
		
		if (result > 0) {
			response.setContentType("text/html; charset=UTF-8");
			PrintWriter out = response.getWriter();
			out.println("<script>alert('Sign Up Succeed.');</script>");
			out.flush();
			
		} else if (result == 0) {
			response.setContentType("text/html; charset=UTF-8");
			PrintWriter out = response.getWriter();
			out.println("<script>alert('Sign Up Failed.');</script>");
			out.flush();
			
		} else {
			response.setContentType("text/html; charset=UTF-8");
			PrintWriter out = response.getWriter();
			out.println("<script>alert('ID is duplicated.');</script>");
			out.flush();
			
		}
		
		return nextPage;
		
	}
	
	@RequestMapping(value = "/confirmSignIn", method = RequestMethod.POST)
	public String confirmSignIn(BoaardVo boaardVo, HttpSession session, HttpServletResponse response) throws IOException {
		System.out.println("[Controller] confirmSignIn() called.");
		
		String nextPage = null;
		
		BoaardVo resultBoaardVo = boaardService.confirmSignIn(boaardVo);
		
		if (resultBoaardVo != null && passEncoder.matches(boaardVo.getU_pw(), resultBoaardVo.getU_pw())) {
			session.setAttribute("u_no", resultBoaardVo.getU_no());
			session.setAttribute("u_id", resultBoaardVo.getU_id());
			session.setMaxInactiveInterval(60 * 60);
			
			response.setContentType("text/html; charset=UTF-8");
		    PrintWriter out = response.getWriter();
		    out.println("<script>alert('Sign In Succeed.');</script>");
		    out.flush();
		    nextPage = "notes";
			
		} else {
			response.setContentType("text/html; charset=UTF-8");
		    PrintWriter out = response.getWriter();
		    out.println("<script>alert('Sign In Failed.');</script>");
		    out.flush();
		    nextPage = "sign_in";
			
		}
		
		return nextPage;
		
	}
	
	@RequestMapping(value = "/uploadNote", method = RequestMethod.POST)
	@ResponseBody
	public int uploadNote(@RequestBody Map<String, Object> map, HttpSession session, HttpServletRequest request) {
		System.out.println("[Controller] uploadNote() called.");
		
		int u_no =  (int)session.getAttribute("u_no");
		
		return boaardService.uploadNote(map, u_no, request);
		
	}

	@RequestMapping(value = "/getNotes", method = RequestMethod.POST)
	@ResponseBody
	public List<BoaardVo> getNotes(@RequestBody Map<String, Integer> map) {
		System.out.println("[Controller] getNotes() called.");
		
		int u_no = map.get("u_no");
		
		return boaardService.getNotes(u_no);
		
	}
	
	@RequestMapping(value = "/getText", method = RequestMethod.POST)
	@ResponseBody
	public BoaardVo getText(@RequestBody Map<String, Integer> map) {
		System.out.println("[Controller] getText() called.");
		
		int n_no = map.get("n_no");
		
		return boaardService.getText(n_no);
		
	}
	
	@RequestMapping(value = "/modifyText", method = RequestMethod.POST)
	@ResponseBody
	public int modifyText(@RequestBody Map<String, String> map) {
		System.out.println("[Controller] modifyText() called.");
		
		int c_no = Integer.parseInt(map.get("c_no"));
		String c_text = map.get("c_text");
		
		return boaardService.modifyText(c_no, c_text);
		
	}
	
	@RequestMapping(value = "/deleteNote", method = RequestMethod.POST)
	@ResponseBody
	public int deleteNote(@RequestBody Map<String, Integer> map) {
		System.out.println("[Controller] deleteNote() called.");
		
		int n_no = map.get("n_no");
		
		return boaardService.deleteNote(n_no);

	}

	@RequestMapping(value = "/getMyPage", method = RequestMethod.POST)
	@ResponseBody
	public BoaardVo getMyPage(@RequestBody Map<String, Integer> map) {
		System.out.println("[Controller] getMyPage() called.");
		
		int u_no = map.get("u_no");
		
		return boaardService.getMyPage(u_no);
		
	}
	
	@RequestMapping(value = "/modifyMyPage", method = RequestMethod.POST)
	public String modifyMyPage(BoaardVo boaardVo, HttpServletResponse response) throws IOException {
		System.out.println("[Controller] confirmModifyMyPage() called.");
		
		String nextPage = "notes";
		
		BoaardVo resultBoaardVo = boaardService.confirmPwForModify(boaardVo);
		
		if (resultBoaardVo != null) {
			if (passEncoder.matches(boaardVo.getU_pw(), resultBoaardVo.getU_pw())) {
				if (!boaardVo.getNew_pw().equals("")) {
					boaardVo.setNew_pw(passEncoder.encode(boaardVo.getNew_pw()));
					
				}
				
				if (boaardService.modifyMyPage(boaardVo) > 0) {
					response.setContentType("text/html; charset=UTF-8");
					PrintWriter out = response.getWriter();
					out.println("<script>alert('Modify Succeed.');</script>");
					out.flush();
					
				} else {
					response.setContentType("text/html; charset=UTF-8");
					PrintWriter out = response.getWriter();
					out.println("<script>alert('Modify Failed.');</script>");
					out.flush();
					
				}
				
			} else {
				response.setContentType("text/html; charset=UTF-8");
				PrintWriter out = response.getWriter();
				out.println("<script>alert('Password is incorrect.');</script>");
				out.flush();
				
			}
			
			
		} else {
			response.setContentType("text/html; charset=UTF-8");
			PrintWriter out = response.getWriter();
			out.println("<script>alert('Connection error.');</script>");
			out.flush();
			
		}
		
		return nextPage;
		
	}
	
	@RequestMapping(value = "/withdrawal", method = RequestMethod.POST)
	@ResponseBody
	public int withdrawal(@RequestBody Map<String, Object> map) {
		System.out.println("[Controller] withdrawal() called.");
		
		int u_no = (int)map.get("u_no");
		String u_pw = (String)map.get("u_pw");
		
		BoaardVo resultBoaardVo = boaardService.confirmPwForWithdrawal(u_no);
		
		if (resultBoaardVo != null) {
			if (passEncoder.matches(u_pw, resultBoaardVo.getU_pw())) {
				
				return boaardService.withdrawal(u_no);
				
			} else {
				
				return -1;
				
			}
			
		} else {
			
			return 0;
			
		}
		
	}
	
}
