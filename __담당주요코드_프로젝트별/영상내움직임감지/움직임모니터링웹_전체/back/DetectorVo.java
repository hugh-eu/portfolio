package com.hugh.detector.vo;

import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class DetectorVo {

	private int u_no;
    private String u_id;
    private String u_pw;
    private String u_auth;
    private String u_reg_date;
    private String u_mod_date;
	
    private int i_no;
    private String i_device;
    private String i_img_name;
    private String i_reg_date;
	
}
