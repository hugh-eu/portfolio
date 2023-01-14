package com.group1.licensePlateTrace.userUtil;

import java.util.Map;

public class MapUtil {

	public static final int SELECT_PLATE_YEAR = 1;  
	public static final int SELECT_PLATE_YEAR_MONTH = 2;  
	public static final int SELECT_PLATE_YEAR_MONTH_DAY  = 3;
	public static final int SELECT_PLATE = 4;
	
	public static final int SELECT_ALL  = 5;
	public static final int SELECT_YEAR = 6;  
	public static final int SELECT_YEAR_MONTH = 7;  
	public static final int SELECT_YEAR_MONTH_DAY  = 8;
	
	public static final int NOT_PLATE_SEARCHED = -1;
	public static final int PLATE_SEARCHED = 1;
	
	
	public int quarter(Map<String, String> msgMap) {
		
		int result = -1;
		if (msgMap.get("plate") != null) {
			
			if(msgMap.get("year") == null && msgMap.get("month") == null && msgMap.get("day") == null) {
				result = SELECT_PLATE;
				
				return result;
				
			}else if (msgMap.get("year") != null && msgMap.get("month") == null && msgMap.get("day") == null) {
				result = SELECT_PLATE_YEAR;
				
				return result;
				
			}else if (msgMap.get("year") != null && msgMap.get("month") != null && msgMap.get("day") == null) {
				result = SELECT_PLATE_YEAR_MONTH;
				
				return result;
				
			}else if (msgMap.get("year") != null && msgMap.get("month") != null && msgMap.get("day") != null) {
				result = SELECT_PLATE_YEAR_MONTH_DAY;
				
				return result;
			}
			
		}else if (msgMap.get("plate") == null) {
			
			if (msgMap.get("year") == null && msgMap.get("month") == null && msgMap.get("day") == null) {
				result = SELECT_ALL;
			
			}else if (msgMap.get("year") != null && msgMap.get("month") == null && msgMap.get("day") == null) {
				result = SELECT_YEAR;
				
				return result;
				
			}else if (msgMap.get("year") != null && msgMap.get("month") != null && msgMap.get("day") == null) {
				result = SELECT_YEAR_MONTH;
				
				return result;
				
			}else if (msgMap.get("year") != null && msgMap.get("month") != null && msgMap.get("day") != null) {
				result = SELECT_YEAR_MONTH_DAY;
				
				return result;
			}
		}
		
		
		return result;
	}
	
	
}
