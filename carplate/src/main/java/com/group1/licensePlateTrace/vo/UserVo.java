package com.group1.licensePlateTrace.vo;

import lombok.Data;

@Data
public class UserVo {
	
	private int u_no;
	private String u_id;
	private String u_pw;
	private String u_name;
	private String u_mail;
	private String u_phone;
	private String u_reg_date;
	private String u_mod_date;
	private int a_no;
	private String a_auth_info;
	private String a_reg_date;			
	private String a_mod_date;

}
