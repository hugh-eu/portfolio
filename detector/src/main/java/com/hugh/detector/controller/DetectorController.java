<<<<<<< HEAD
package com.hugh.detector.controller;

import java.io.PrintWriter;
import java.util.List;
import java.util.Map;

import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.codehaus.jackson.map.util.JSONPObject;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

import com.hugh.detector.service.DetectorService;
import com.hugh.detector.vo.DetectorVo;

@Controller
public class DetectorController {

	@Autowired
	private DetectorService detectorService;
	
	@RequestMapping(value = {"", "/"}, method = RequestMethod.GET)
	public String home() {
		
		return "redirect:/login";
	}
	
	@RequestMapping(value = "/login")
	public String login() {
		System.out.println("[DetectorController] login() called.");
		String nextPage = "login";
		
		return nextPage;
	}
	
	@RequestMapping(value = "/loginConfirm", method = RequestMethod.POST)
	public String loginConfirm(DetectorVo detectorVo, HttpSession session, HttpServletResponse response) throws Exception {
		System.out.println("[DetectorController] loginConfirm() called.");
		String nextPage = null;
		
		DetectorVo result = detectorService.confirmLogin(detectorVo);
		
		if (result != null) {
			
			if (result.getU_auth().equals("O")) {
				session.setAttribute("id", detectorVo);
				session.setMaxInactiveInterval(30 * 60);
				
				response.setContentType("text/html; charset=UTF-8");
				PrintWriter out = response.getWriter();
				out.println("<script language='javascript'>");
				out.println("alert('로그인 성공.');");
				out.println("</script>");
				out.flush();
	
				nextPage = "streaming";
			} else {
				response.setContentType("text/html; charset=UTF-8");
				PrintWriter out = response.getWriter();
				out.println("<script language='javascript'>");
				out.println("alert('가입 승인 대기중.');");
				out.println("</script>");
				out.flush();
				
				nextPage = "login";
			}
		} else {
			response.setContentType("text/html; charset=UTF-8");
			PrintWriter out = response.getWriter();
			out.println("<script language='javascript'>");
			out.println("alert('로그인 실패.');");
			out.println("</script>");
			out.flush();
			
			nextPage = "login";
		}
		
		return nextPage;
	}
	
	@RequestMapping(value = "/signUp")
	public String signUp() {
		System.out.println("[DetectorController] signUp() called.");
		String nextPage = "sign_up";
		
		return nextPage;
	}
	
	@RequestMapping(value = "/signUpConfirm", method = RequestMethod.POST)
	public String signUpConfirm (DetectorVo detectorVo, HttpServletResponse response) throws Exception {
		System.out.println("[DetectorController] signUpConfirm() called.");
		String nextPage = "login";
		
		int result = detectorService.confirmSignUp(detectorVo);
		
		if (result == DetectorService.SIGNUP_SUCCESS) {
			response.setContentType("text/html; charset=UTF-8");
			PrintWriter out = response.getWriter();
			out.println("<script language='javascript'>");
			out.println("alert('회원가입 성공.');");
			out.println("</script>");
			out.flush();
		} else if (result == DetectorService.SIGNUP_DUPLICATE) {
			response.setContentType("text/html; charset=UTF-8");
			PrintWriter out = response.getWriter();
			out.println("<script language='javascript'>");
			out.println("alert('아이디 중복.');");
			out.println("</script>");
			out.flush();
		} else {
			response.setContentType("text/html; charset=UTF-8");
			PrintWriter out = response.getWriter();
			out.println("<script language='javascript'>");
			out.println("alert('서버 통신 에러.');");
			out.println("</script>");
			out.flush();
		}
		
		return nextPage;
	}
	
	@RequestMapping(value = "/streaming")
	public String streaming(HttpSession session) {
		System.out.println("[DetectorController] streaming() called.");
		String nextPage = null;
		
		if (session.getAttribute("id") != null) {
			nextPage = "streaming";
		} else {
			nextPage = "redirect:/login";
		}
		
		return nextPage;
	}
	
	@RequestMapping(value = "/detectedList")
	public String detectedList(HttpSession session, Model model) {
		System.out.println("[DetectorController] detectedList() called.");
		String nextPage = null;
		
		if (session.getAttribute("id") != null) {
			
			List<DetectorVo> detectorVos = detectorService.getDetectedList();
			model.addAttribute("detectorVos", detectorVos);
			nextPage = "detected_list";
			
		} else {
			nextPage = "redirect:/login";
		}
		
		return nextPage;
	}
	
	@RequestMapping(value = "/checkImg", method = RequestMethod.GET)
	public String checkImg(HttpSession session, Model model, DetectorVo detectorVo) {
		System.out.println("[DetectorController] adminPage() called.");
		String nextPage = null;
		
		if (session.getAttribute("id") != null) {
			String i_img_name = detectorVo.getI_img_name();
			
			model.addAttribute("i_img_name", i_img_name);
			nextPage = "check_img";
			
		} else {
			nextPage = "redirect:/login";
		}
		
		return nextPage;
	}
	
	@RequestMapping(value = "/adminPage")
	public String adminPage(HttpSession session, Model model) {
		System.out.println("[DetectorController] adminPage() called.");
		String nextPage = null;
		
		if (session.getAttribute("id") != null) {
			
			List<DetectorVo> detectorVos = detectorService.getUserList();
			model.addAttribute("detectorVos", detectorVos);
			nextPage = "admin_page";
			
		} else {
			nextPage = "redirect:/login";
		}
		
		return nextPage;
	}
	
	@RequestMapping(value = "/changeAuth", method = RequestMethod.GET)
	public String changeAuth(DetectorVo detectorVo, HttpSession session, Model model) {
		System.out.println("[DetectorController] changeAuth() called.");
		String nextPage = null;
		
		if (session.getAttribute("id") != null) {
			int u_no = detectorVo.getU_no();
			String u_auth = detectorVo.getU_auth();
			
			if (u_auth.equals("O")) {
				u_auth = "X";
			} else {
				u_auth = "O";
			}
			
			List<DetectorVo> detectorVos = detectorService.changeAuth(u_no, u_auth);
			model.addAttribute("detectorVos", detectorVos);
			nextPage = "admin_page";
			
		} else {
			nextPage = "redirect:/login";
		}
		
		return nextPage;
	}
	
	@RequestMapping(value = "/logout")
	public String logout(HttpSession session) {
		System.out.println("[DetectorController] logout() called.");
		String nextPage = "login";
		
		session.removeAttribute("id");

		return nextPage;
	}
	
	@RequestMapping(value = "/ajaxMonthly", method = RequestMethod.POST)
	@ResponseBody
	public List<DetectorVo> ajaxMonthly(@RequestBody Map<String, Object> data) {
		System.out.println("[DetectorController] ajaxMonthly() called.");

		String month = (String)data.get("month");
		List<DetectorVo> detectorVos = detectorService.getDetectedListMonthly(month);
		
		return detectorVos;
		
	}
	
	@RequestMapping(value = "/ajaxDaily", method = RequestMethod.POST)
	@ResponseBody
	public List<DetectorVo> ajaxDaily(@RequestBody Map<String, Object> data) {
		System.out.println("[DetectorController] ajaxDaily() called.");

		String day = (String)data.get("day");
		List<DetectorVo> detectorVos = detectorService.getDetectedListDaily(day);
		
		return detectorVos;
		
	}
	
}
=======
<<<<<<< HEAD
package com.hugh.detector.controller;

import java.io.PrintWriter;
import java.util.List;
import java.util.Map;

import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.codehaus.jackson.map.util.JSONPObject;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

import com.hugh.detector.service.DetectorService;
import com.hugh.detector.vo.DetectorVo;

@Controller
public class DetectorController {

	@Autowired
	private DetectorService detectorService;
	
	@RequestMapping(value = {"", "/"}, method = RequestMethod.GET)
	public String home() {
		
		return "redirect:/login";
	}
	
	@RequestMapping(value = "/login")
	public String login() {
		System.out.println("[DetectorController] login() called.");
		String nextPage = "login";
		
		return nextPage;
	}
	
	@RequestMapping(value = "/loginConfirm", method = RequestMethod.POST)
	public String loginConfirm(DetectorVo detectorVo, HttpSession session, HttpServletResponse response) throws Exception {
		System.out.println("[DetectorController] loginConfirm() called.");
		String nextPage = null;
		
		DetectorVo result = detectorService.confirmLogin(detectorVo);
		
		if (result != null) {
			
			if (result.getU_auth().equals("O")) {
				session.setAttribute("id", detectorVo);
				session.setMaxInactiveInterval(30 * 60);
				
				response.setContentType("text/html; charset=UTF-8");
				PrintWriter out = response.getWriter();
				out.println("<script language='javascript'>");
				out.println("alert('로그인 성공.');");
				out.println("</script>");
				out.flush();
	
				nextPage = "streaming";
			} else {
				response.setContentType("text/html; charset=UTF-8");
				PrintWriter out = response.getWriter();
				out.println("<script language='javascript'>");
				out.println("alert('가입 승인 대기중.');");
				out.println("</script>");
				out.flush();
				
				nextPage = "login";
			}
		} else {
			response.setContentType("text/html; charset=UTF-8");
			PrintWriter out = response.getWriter();
			out.println("<script language='javascript'>");
			out.println("alert('로그인 실패.');");
			out.println("</script>");
			out.flush();
			
			nextPage = "login";
		}
		
		return nextPage;
	}
	
	@RequestMapping(value = "/signUp")
	public String signUp() {
		System.out.println("[DetectorController] signUp() called.");
		String nextPage = "sign_up";
		
		return nextPage;
	}
	
	@RequestMapping(value = "/signUpConfirm", method = RequestMethod.POST)
	public String signUpConfirm (DetectorVo detectorVo, HttpServletResponse response) throws Exception {
		System.out.println("[DetectorController] signUpConfirm() called.");
		String nextPage = "login";
		
		int result = detectorService.confirmSignUp(detectorVo);
		
		if (result == DetectorService.SIGNUP_SUCCESS) {
			response.setContentType("text/html; charset=UTF-8");
			PrintWriter out = response.getWriter();
			out.println("<script language='javascript'>");
			out.println("alert('회원가입 성공.');");
			out.println("</script>");
			out.flush();
		} else if (result == DetectorService.SIGNUP_DUPLICATE) {
			response.setContentType("text/html; charset=UTF-8");
			PrintWriter out = response.getWriter();
			out.println("<script language='javascript'>");
			out.println("alert('아이디 중복.');");
			out.println("</script>");
			out.flush();
		} else {
			response.setContentType("text/html; charset=UTF-8");
			PrintWriter out = response.getWriter();
			out.println("<script language='javascript'>");
			out.println("alert('서버 통신 에러.');");
			out.println("</script>");
			out.flush();
		}
		
		return nextPage;
	}
	
	@RequestMapping(value = "/streaming")
	public String streaming(HttpSession session) {
		System.out.println("[DetectorController] streaming() called.");
		String nextPage = null;
		
		if (session.getAttribute("id") != null) {
			nextPage = "streaming";
		} else {
			nextPage = "redirect:/login";
		}
		
		return nextPage;
	}
	
	@RequestMapping(value = "/detectedList")
	public String detectedList(HttpSession session, Model model) {
		System.out.println("[DetectorController] detectedList() called.");
		String nextPage = null;
		
		if (session.getAttribute("id") != null) {
			
			List<DetectorVo> detectorVos = detectorService.getDetectedList();
			model.addAttribute("detectorVos", detectorVos);
			nextPage = "detected_list";
			
		} else {
			nextPage = "redirect:/login";
		}
		
		return nextPage;
	}
	
	@RequestMapping(value = "/checkImg", method = RequestMethod.GET)
	public String checkImg(HttpSession session, Model model, DetectorVo detectorVo) {
		System.out.println("[DetectorController] adminPage() called.");
		String nextPage = null;
		
		if (session.getAttribute("id") != null) {
			String i_img_name = detectorVo.getI_img_name();
			
			model.addAttribute("i_img_name", i_img_name);
			nextPage = "check_img";
			
		} else {
			nextPage = "redirect:/login";
		}
		
		return nextPage;
	}
	
	@RequestMapping(value = "/adminPage")
	public String adminPage(HttpSession session, Model model) {
		System.out.println("[DetectorController] adminPage() called.");
		String nextPage = null;
		
		if (session.getAttribute("id") != null) {
			
			List<DetectorVo> detectorVos = detectorService.getUserList();
			model.addAttribute("detectorVos", detectorVos);
			nextPage = "admin_page";
			
		} else {
			nextPage = "redirect:/login";
		}
		
		return nextPage;
	}
	
	@RequestMapping(value = "/changeAuth", method = RequestMethod.GET)
	public String changeAuth(DetectorVo detectorVo, HttpSession session, Model model) {
		System.out.println("[DetectorController] changeAuth() called.");
		String nextPage = null;
		
		if (session.getAttribute("id") != null) {
			int u_no = detectorVo.getU_no();
			String u_auth = detectorVo.getU_auth();
			
			if (u_auth.equals("O")) {
				u_auth = "X";
			} else {
				u_auth = "O";
			}
			
			List<DetectorVo> detectorVos = detectorService.changeAuth(u_no, u_auth);
			model.addAttribute("detectorVos", detectorVos);
			nextPage = "admin_page";
			
		} else {
			nextPage = "redirect:/login";
		}
		
		return nextPage;
	}
	
	@RequestMapping(value = "/logout")
	public String logout(HttpSession session) {
		System.out.println("[DetectorController] logout() called.");
		String nextPage = "login";
		
		session.removeAttribute("id");

		return nextPage;
	}
	
	@RequestMapping(value = "/ajaxMonthly", method = RequestMethod.POST)
	@ResponseBody
	public List<DetectorVo> ajaxMonthly(@RequestBody Map<String, Object> data) {
		System.out.println("[DetectorController] ajaxMonthly() called.");

		String month = (String)data.get("month");
		List<DetectorVo> detectorVos = detectorService.getDetectedListMonthly(month);
		
		return detectorVos;
		
	}
	
	@RequestMapping(value = "/ajaxDaily", method = RequestMethod.POST)
	@ResponseBody
	public List<DetectorVo> ajaxDaily(@RequestBody Map<String, Object> data) {
		System.out.println("[DetectorController] ajaxDaily() called.");

		String day = (String)data.get("day");
		List<DetectorVo> detectorVos = detectorService.getDetectedListDaily(day);
		
		return detectorVos;
		
	}
	
}
=======
package com.hugh.detector.controller;

import java.io.PrintWriter;
import java.util.List;
import java.util.Map;

import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import org.codehaus.jackson.map.util.JSONPObject;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

import com.hugh.detector.service.DetectorService;
import com.hugh.detector.vo.DetectorVo;

@Controller
public class DetectorController {

	@Autowired
	private DetectorService detectorService;
	
	@RequestMapping(value = {"", "/"}, method = RequestMethod.GET)
	public String home() {
		
		return "redirect:/login";
	}
	
	@RequestMapping(value = "/login")
	public String login() {
		System.out.println("[DetectorController] login() called.");
		String nextPage = "login";
		
		return nextPage;
	}
	
	@RequestMapping(value = "/loginConfirm", method = RequestMethod.POST)
	public String loginConfirm(DetectorVo detectorVo, HttpSession session, HttpServletResponse response) throws Exception {
		System.out.println("[DetectorController] loginConfirm() called.");
		String nextPage = null;
		
		DetectorVo result = detectorService.confirmLogin(detectorVo);
		
		if (result != null) {
			
			if (result.getU_auth().equals("O")) {
				session.setAttribute("id", detectorVo);
				session.setMaxInactiveInterval(30 * 60);
				
				response.setContentType("text/html; charset=UTF-8");
				PrintWriter out = response.getWriter();
				out.println("<script language='javascript'>");
				out.println("alert('로그인 성공.');");
				out.println("</script>");
				out.flush();
	
				nextPage = "streaming";
			} else {
				response.setContentType("text/html; charset=UTF-8");
				PrintWriter out = response.getWriter();
				out.println("<script language='javascript'>");
				out.println("alert('가입 승인 대기중.');");
				out.println("</script>");
				out.flush();
				
				nextPage = "login";
			}
		} else {
			response.setContentType("text/html; charset=UTF-8");
			PrintWriter out = response.getWriter();
			out.println("<script language='javascript'>");
			out.println("alert('로그인 실패.');");
			out.println("</script>");
			out.flush();
			
			nextPage = "login";
		}
		
		return nextPage;
	}
	
	@RequestMapping(value = "/signUp")
	public String signUp() {
		System.out.println("[DetectorController] signUp() called.");
		String nextPage = "sign_up";
		
		return nextPage;
	}
	
	@RequestMapping(value = "/signUpConfirm", method = RequestMethod.POST)
	public String signUpConfirm (DetectorVo detectorVo, HttpServletResponse response) throws Exception {
		System.out.println("[DetectorController] signUpConfirm() called.");
		String nextPage = "login";
		
		int result = detectorService.confirmSignUp(detectorVo);
		
		if (result == DetectorService.SIGNUP_SUCCESS) {
			response.setContentType("text/html; charset=UTF-8");
			PrintWriter out = response.getWriter();
			out.println("<script language='javascript'>");
			out.println("alert('회원가입 성공.');");
			out.println("</script>");
			out.flush();
		} else if (result == DetectorService.SIGNUP_DUPLICATE) {
			response.setContentType("text/html; charset=UTF-8");
			PrintWriter out = response.getWriter();
			out.println("<script language='javascript'>");
			out.println("alert('아이디 중복.');");
			out.println("</script>");
			out.flush();
		} else {
			response.setContentType("text/html; charset=UTF-8");
			PrintWriter out = response.getWriter();
			out.println("<script language='javascript'>");
			out.println("alert('서버 통신 에러.');");
			out.println("</script>");
			out.flush();
		}
		
		return nextPage;
	}
	
	@RequestMapping(value = "/streaming")
	public String streaming(HttpSession session) {
		System.out.println("[DetectorController] streaming() called.");
		String nextPage = null;
		
		if (session.getAttribute("id") != null) {
			nextPage = "streaming";
		} else {
			nextPage = "redirect:/login";
		}
		
		return nextPage;
	}
	
	@RequestMapping(value = "/detectedList")
	public String detectedList(HttpSession session, Model model) {
		System.out.println("[DetectorController] detectedList() called.");
		String nextPage = null;
		
		if (session.getAttribute("id") != null) {
			
			List<DetectorVo> detectorVos = detectorService.getDetectedList();
			model.addAttribute("detectorVos", detectorVos);
			nextPage = "detected_list";
			
		} else {
			nextPage = "redirect:/login";
		}
		
		return nextPage;
	}
	
	@RequestMapping(value = "/checkImg", method = RequestMethod.GET)
	public String checkImg(HttpSession session, Model model, DetectorVo detectorVo) {
		System.out.println("[DetectorController] adminPage() called.");
		String nextPage = null;
		
		if (session.getAttribute("id") != null) {
			String i_img_name = detectorVo.getI_img_name();
			
			model.addAttribute("i_img_name", i_img_name);
			nextPage = "check_img";
			
		} else {
			nextPage = "redirect:/login";
		}
		
		return nextPage;
	}
	
	@RequestMapping(value = "/adminPage")
	public String adminPage(HttpSession session, Model model) {
		System.out.println("[DetectorController] adminPage() called.");
		String nextPage = null;
		
		if (session.getAttribute("id") != null) {
			
			List<DetectorVo> detectorVos = detectorService.getUserList();
			model.addAttribute("detectorVos", detectorVos);
			nextPage = "admin_page";
			
		} else {
			nextPage = "redirect:/login";
		}
		
		return nextPage;
	}
	
	@RequestMapping(value = "/changeAuth", method = RequestMethod.GET)
	public String changeAuth(DetectorVo detectorVo, HttpSession session, Model model) {
		System.out.println("[DetectorController] changeAuth() called.");
		String nextPage = null;
		
		if (session.getAttribute("id") != null) {
			int u_no = detectorVo.getU_no();
			String u_auth = detectorVo.getU_auth();
			
			if (u_auth.equals("O")) {
				u_auth = "X";
			} else {
				u_auth = "O";
			}
			
			List<DetectorVo> detectorVos = detectorService.changeAuth(u_no, u_auth);
			model.addAttribute("detectorVos", detectorVos);
			nextPage = "admin_page";
			
		} else {
			nextPage = "redirect:/login";
		}
		
		return nextPage;
	}
	
	@RequestMapping(value = "/logout")
	public String logout(HttpSession session) {
		System.out.println("[DetectorController] logout() called.");
		String nextPage = "login";
		
		session.removeAttribute("id");

		return nextPage;
	}
	
	@RequestMapping(value = "/ajaxMonthly", method = RequestMethod.POST)
	@ResponseBody
	public List<DetectorVo> ajaxMonthly(@RequestBody Map<String, Object> data) {
		System.out.println("[DetectorController] ajaxMonthly() called.");

		String month = (String)data.get("month");
		List<DetectorVo> detectorVos = detectorService.getDetectedListMonthly(month);
		
		return detectorVos;
		
	}
	
	@RequestMapping(value = "/ajaxDaily", method = RequestMethod.POST)
	@ResponseBody
	public List<DetectorVo> ajaxDaily(@RequestBody Map<String, Object> data) {
		System.out.println("[DetectorController] ajaxDaily() called.");

		String day = (String)data.get("day");
		List<DetectorVo> detectorVos = detectorService.getDetectedListDaily(day);
		
		return detectorVos;
		
	}
	
}
>>>>>>> dfafe29c0482dd92cdc454a767f9bed240e80ae9
>>>>>>> 5aa76ea3a0591d427a636e8d726911934985e0b2
