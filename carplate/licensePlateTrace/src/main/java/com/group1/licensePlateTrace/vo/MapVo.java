package com.group1.licensePlateTrace.vo;

import lombok.Data;

@Data
public class MapVo {
	
	/* 검색 데이터 */
	private int s_no;
	private String s_name; 
	private String s_info;
	private String s_reg_date;
	private String s_mod_date;
	
	/* 범죄자 데이터 */
	private int l_no;
	private String l_info;
	private String l_info_reg_date;
	private String l_img_name;
	
	
    /* 카메라 정보 */
    private int c_no;
    private String c_name;
    private double c_latitude;		// 위도
    private double c_longitude; 	// 경도
    private String c_set_date;
    
}
