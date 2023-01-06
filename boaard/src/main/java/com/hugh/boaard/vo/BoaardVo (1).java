package com.hugh.boaard.vo;

import lombok.Getter;
import lombok.Setter;

@Getter
@Setter
public class BoaardVo {

	private int u_no;
    private String u_id;
    private String u_pw;
    private String u_email;
    private String u_reg_date;
    private String u_mod_date;
    
    private String new_pw;
    private String confirm_new_pw;
	
    private int n_no;
    private String n_name;
    private String n_reg_date;
    
    private int c_no;
    private String c_text;
    private String c_reg_date;
    private String c_mod_date;
    
}
