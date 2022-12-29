package com.hugh.tripist.vo;

import lombok.Data;

@Data
public class TripistVo {

	private int u_no;
    private String u_id;
    private String u_pw;
    private String u_email;
    private String u_reg_date;
    private String u_mod_date;
    
    private int m_no;
    private String m_lat;
    private String m_lng;
    private String m_location;
    private String m_period;
    private String m_contents;
    private String m_img_name;
    private String m_reg_date;
    private String m_mod_date;
	
}
