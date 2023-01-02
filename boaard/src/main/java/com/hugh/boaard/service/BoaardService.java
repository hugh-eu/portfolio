package com.hugh.boaard.service;

import java.io.File;
import java.io.FileOutputStream;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.List;
import java.util.Map;

import javax.servlet.http.HttpServletRequest;

import org.apache.commons.codec.binary.Base64;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.hugh.boaard.dao.BoaardDao;
import com.hugh.boaard.util.SCPUtil;
import com.hugh.boaard.vo.BoaardVo;

import net.sourceforge.tess4j.ITessAPI.TessPageSegMode;
import net.sourceforge.tess4j.ITesseract;
import net.sourceforge.tess4j.Tesseract;

@Service
public class BoaardService {
	
	@Autowired
	BoaardDao boaardDao;
	
	public int confirmSignUp(BoaardVo boaardVo) {
		System.out.println("[Service] confirmSignUp() called.");
		
		return boaardDao.confirmSignUp(boaardVo);
		
	}

	public BoaardVo confirmSignIn(BoaardVo boaardVo) {
		System.out.println("[Service] confirmSignIn() called.");
		
		List<BoaardVo> boaardVos = boaardDao.confirmSignIn(boaardVo);
		
		if (boaardVos.size() > 0) {
			
			return boaardVos.get(0);
			
		} else {
			
			return null;
			
		}
		
	}
	
	public int uploadNote(Map<String, Object> map, int u_no, HttpServletRequest request) {
		System.out.println("[Service] uploadNote() called.");
		
		LocalDateTime now = LocalDateTime.now();
		DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyyMMddHHmmssSSSSSSS");
		String formatedNow = now.format(formatter);
		String localPath = request.getSession().getServletContext().getRealPath("/").concat("resources") + File.separator + "static" + File.separator;
		String remotePath = "/boaard/notes";
		String name_note = formatedNow + "_u_no_" + Integer.toString(u_no) + ".png";
		
		String canvasData = (String)map.get("canvasData");
		byte[] noteByte = Base64.decodeBase64(canvasData);

		FileOutputStream stream = null;

		File file_origin = null;

		SCPUtil scpUtil = null;
		
		int result = 0;
		
		try {
			stream = new FileOutputStream(localPath + name_note);
			stream.write(noteByte);
			stream.close();
			
			file_origin = new File(localPath + name_note);
			
			ITesseract instance = new Tesseract();
			instance.setDatapath(request.getSession().getServletContext().getRealPath("/").concat("resources") + File.separator + "static" + File.separator + "tessdata");
			instance.setLanguage("kor+Hangul+eng");
			instance.setPageSegMode(TessPageSegMode.PSM_AUTO);
			String c_text = instance.doOCR(file_origin);
			
			if (c_text.length() != 0) {
				scpUtil = new SCPUtil();
				scpUtil.init("192.168.0.123", "hugh", "1234");
				scpUtil.upload(remotePath, file_origin);
				scpUtil.disconnection();
				scpUtil = null;
				
				List<BoaardVo> boaardVos = boaardDao.insertNoteInfo(u_no, name_note);
				
				if (boaardVos != null && boaardVos.size() > 0) {
					BoaardVo boaardVo = new BoaardVo();
					boaardVo.setN_no(boaardVos.get(0).getN_no());
					boaardVo.setC_text(c_text);
					
					result = boaardDao.insertNoteText(boaardVo);
					
				}
				
			} else {
				
				result = -1;
				
			}
			
			
		} catch (Exception e) {
			e.printStackTrace();
			
		} finally {
			if (file_origin != null) {
				file_origin.delete();
				
			}
			
		}
		
		return result;
		
	}

	public List<BoaardVo> getNotes(int u_no) {
		System.out.println("[Service] getNotes() called.");
		
		return boaardDao.getNotes(u_no);
		
	}

	public BoaardVo getText(int n_no) {
		System.out.println("[Service] getText() called.");
		
		List<BoaardVo> boaardVos = boaardDao.getText(n_no);
		
		if (boaardVos.size() > 0) {
			
			return boaardVos.get(0);
			
		} else {
			
			return null;
			
		}
		
	}

	public int modifyText(int c_no, String c_text) {
		System.out.println("[Service] modifyText() called.");
		
		return boaardDao.modifyText(c_no, c_text);
		
	}

	public int deleteNote(int n_no) {
		System.out.println("[Service] deleteNote() called.");
		
		return boaardDao.deleteNote(n_no);
		
	}

	public BoaardVo getMyPage(int u_no) {
		System.out.println("[Service] getMyPage() called.");
		
		List<BoaardVo> boaardVos = boaardDao.getMyPage(u_no);
		
		if (boaardVos.size() > 0) {
			
			return boaardVos.get(0);
			
		} else {
			
			return null;
			
		}

	}

	public BoaardVo confirmPwForModify(BoaardVo boaardVo) {
		System.out.println("[Service] getMyPage() called.");
		
		List<BoaardVo> boaardVos = boaardDao.confirmPwForModify(boaardVo);
		
		if (boaardVos.size() > 0) {
			
			return boaardVos.get(0);
			
		} else {
			
			return null;
			
		}
		
	}

	public int modifyMyPage(BoaardVo boaardVo) {
		System.out.println("[Service] modifyMyPage() called.");
		
		return boaardDao.modifyMyPage(boaardVo);
		
	}

	public BoaardVo confirmPwForWithdrawal(int u_no) {
		System.out.println("[Service] confirmPwForWithdrawal() called.");

		List<BoaardVo> boaardVos = boaardDao.confirmPwForWithdrawal(u_no);
		
		if (boaardVos.size() > 0) {
			
			return boaardVos.get(0);
			
		} else {
			
			return null;
			
		}
		
	}

	public int withdrawal(int u_no) {
		System.out.println("[Service] withdrawal() called.");
		
		return boaardDao.withdrawal(u_no);

	}

}
