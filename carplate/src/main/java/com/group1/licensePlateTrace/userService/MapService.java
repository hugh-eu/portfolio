package com.group1.licensePlateTrace.userService;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.group1.licensePlateTrace.userDao.MapDao;
import com.group1.licensePlateTrace.userUtil.MapUtil;
import com.group1.licensePlateTrace.vo.MapDateVo;
import com.group1.licensePlateTrace.vo.MapVo;

import lombok.extern.slf4j.Slf4j;

@Service
@Slf4j
public class MapService {

	@Autowired
	MapDao mapDao;

	public Map<String, Object> getItems(Map<String, String> msgMap) {
		log.debug("");
		
		Map<String, Object> map = new HashMap<String, Object>();
		
		List<MapVo> mapVos = null;
		
		MapUtil mapUtil = new MapUtil();
		
		int result = mapUtil.quarter(msgMap);
		
		switch (result) {
		case MapUtil.SELECT_PLATE:
			mapVos = mapDao.getPlateItem(msgMap);		// 번호판 클릭시(날짜 정보 없음)
			break;
			
		case MapUtil.SELECT_PLATE_YEAR:
			mapVos = mapDao.getYearItems(msgMap);		// 년도 클릭시(번호판 정보 있을시)
			break;
			
		case MapUtil.SELECT_PLATE_YEAR_MONTH:
			mapVos = mapDao.getMonthItems(msgMap);		// 월 클릭시(번호판 정보 있을시)
			break;
			
		case MapUtil.SELECT_PLATE_YEAR_MONTH_DAY:
			mapVos = mapDao.getDayItems(msgMap);		// 일 클릭시(번호판 정보 있을시)
			break;
			
		case MapUtil.SELECT_ALL:
			mapVos = mapDao.getItems();					// 리밋 걸어둠 따로 설정할것임
			break;
			
		case MapUtil.SELECT_YEAR:
			mapVos = mapDao.getYearItems(msgMap);		// 년도 클릭시
			break;
			
		case MapUtil.SELECT_YEAR_MONTH:
			mapVos = mapDao.getMonthItems(msgMap);		// 월 클릭시
			break;
			
		case MapUtil.SELECT_YEAR_MONTH_DAY:
			mapVos = mapDao.getDayItems(msgMap);		// 일 클릭시
			break;
		}
//		
//		if (msgMap.get("year") == null && msgMap.get("month") == null && msgMap.get("day") == null && msgMap.get("camera") == null ) {
//			mapVos = mapDao.getItems();					// 전체 조회
//			
//		}
//		else if (msgMap.get("year") != null && msgMap.get("month") == null && msgMap.get("day") == null && msgMap.get("camera") == null ) {
//			mapVos = mapDao.getYearItems(msgMap);		// 년도 클릭시
//		}
//		
//		else if (msgMap.get("year") != null && msgMap.get("month") != null && msgMap.get("day") == null && msgMap.get("camera") == null ) {
//			mapVos = mapDao.getMonthItems(msgMap);		// 월 클릭시
//		}
//		
//		else if (msgMap.get("year") != null && msgMap.get("month") != null && msgMap.get("day") != null && msgMap.get("camera") == null ){
//			mapVos = mapDao.getDayItems(msgMap);		// 일 클릭시
//		}
//		
//		else if (msgMap.get("year") != null && msgMap.get("month") != null && msgMap.get("day") != null && msgMap.get("camera") != null && msgMap.get("plate") == null ){
//			mapVos = mapDao.getDayItems(msgMap);		// 카메라 클릭시
//		}
//		
//		else if (msgMap.get("year") != null && msgMap.get("month") != null && msgMap.get("day") != null && msgMap.get("camera") != null && msgMap.get("plate") != null ){
//			mapVos = mapDao.getPlateItems(msgMap);		// 날짜와 번호판 클릭시
//		}
//		
//		else if (msgMap.get("year") == null && msgMap.get("month") == null && msgMap.get("day") == null && msgMap.get("camera") == null && msgMap.get("plate") != null ){
//			mapVos = mapDao.getPlateItem(msgMap);		// 번호판 클릭시
//		}
		
		map.put("MapVos", mapVos);
		
		System.out.println(map.get("MapVos"));
		
		return map;
		
	}

	public Map<String, Object> getDate(Map<String, String> msgMap) {
		log.debug("");
		
		System.out.println("------------>" + msgMap.get("plate"));
		
		Map<String, Object> map = new HashMap<String, Object>();
		List<MapDateVo> dateVos = null;
		ArrayList<String> yearList = new ArrayList<>();
		
		if (msgMap.get("plate") == null) {
			
			dateVos = mapDao.getDate(msgMap.get("plate"));
			
			System.out.println("dateVos.get(0): \n" + dateVos.get(0));
			
			for(int i = 0; i < dateVos.size(); i++) {
				MapDateVo list = dateVos.get(i);
				String year = list.getL_info_reg_date().substring(0, 4).replaceAll("[-@ ,]", " ");
				
				if (yearList.contains(year)) {
					continue;
				}
				yearList.add(year);
				
			}
			
		}else if (msgMap.get("plate") != null){
			
			dateVos = mapDao.getDate(msgMap.get("plate"));
			
			for(int i = 0; i < dateVos.size(); i++) {
				MapDateVo list = dateVos.get(i);
				String year = list.getL_info_reg_date().substring(0, 4).replaceAll("[-@ ,]", " ");
				
				if (yearList.contains(year)) {
					continue;
				}
				yearList.add(year);
				
			}
			System.out.println("---------->" + yearList);
		}
		map.put("MapDateVo", yearList);
		
		return map;
		
	}

	public Map<String, Object> monthSelect(Map<String, String> msgMap) {
		log.debug("");
		
		Map<String, Object> map = new HashMap<String, Object>();
		
		List<MapDateVo> dateVos = new ArrayList<MapDateVo>();
		
		dateVos = null;
		if (msgMap.get("plate") == null)
			dateVos = mapDao.monthSelect(msgMap);
		
		else if (msgMap.get("plate") != null)
			dateVos = mapDao.monthSelect(msgMap);
		
		if (dateVos == null)
			return null;
		
		ArrayList<String> monthList = new ArrayList<>();
		
		for(int i = 0; i < dateVos.size(); i++) {
			MapDateVo list = dateVos.get(i);
			String month = list.getL_info_reg_date().substring(5, 7).replaceAll("[-@ ,]", " ");
			System.out.println(month);
			
			if (monthList.contains(month)) {
				continue;
			}
			monthList.add(month);
			
		}
		System.out.println("monthList" + monthList);
		System.out.println("dateVos: length" + dateVos.size());
		
		map.put("MapDateVo", monthList);
		
		return map;
	}

	public Map<String, Object> daySelect(Map<String, String> msgMap) {
		log.debug("");
		
		Map<String, Object> map = new HashMap<String, Object>();
		
		List<MapDateVo> dateVos = new ArrayList<MapDateVo>();
		
		dateVos = null;
		if (msgMap.get("plate") == null)
			dateVos = mapDao.daySelect(msgMap);
		
		else if (msgMap.get("plate") != null)
			dateVos = mapDao.daySelect(msgMap);
		
		if (dateVos == null)
			return null;
		
		ArrayList<String> dayList = new ArrayList<>();
		
		for(int i = 0; i < dateVos.size(); i++) {
			MapDateVo list = dateVos.get(i);
			String day = "";
			
			if (list.getL_info_reg_date().length() < 19) { 
				day = list.getL_info_reg_date().substring(7, 9).replaceAll("[-@ ,]", " ");
			}else {
				day = list.getL_info_reg_date().substring(8, 11).replaceAll("[-@ ,]", " ");
			}
			
			System.out.println(day);
			
			if (dayList.contains(day)) {
				continue;
			}
			dayList.add(day);
			
		}
		
		System.out.println("yearList" + dayList);
		
		map.put("MapDateVo", dayList);
		
		return map;
		
	}

	public Map<String, Object> getPlates(Map<String, String> msgMap) {
		log.debug("");
		
		Map<String, Object> map = new HashMap<String, Object>();
		
		List<MapVo> mapVos = null;
		
		MapUtil mapUtil = new MapUtil();
		
		int result = mapUtil.quarter(msgMap);
		/* 1월10여기까지 함 내일 할것 번호판 정보 있을때 없을때 나눠서 그에 따른 마커 찍기 */
		switch (result) {
		case MapUtil.SELECT_PLATE:
			mapVos = mapDao.getPlatesAll(msgMap);		// 날짜 정보가 없을때(번호판 있을때)
			break;
			
		case MapUtil.SELECT_PLATE_YEAR:
			mapVos = mapDao.getPlatesYear(msgMap);		// 년도 정보는 있을때(번호판 있을때)
			break;
			
		case MapUtil.SELECT_PLATE_YEAR_MONTH:
			mapVos = mapDao.getPlatesYMonth(msgMap);	// 월 정보는 있을때(번호판 있을때)
			break;
			
		case MapUtil.SELECT_PLATE_YEAR_MONTH_DAY:
			mapVos = mapDao.getPlatesYMDay(msgMap);		// 날짜 정보 있을때(번호판 있을때)
			break;
			
		case MapUtil.SELECT_ALL:
			mapVos = mapDao.getPlatesAll(msgMap);		// 날짜 정보가 없을때(번호판 없을때)
			break;
			
		case MapUtil.SELECT_YEAR:
			mapVos = mapDao.getPlatesYear(msgMap);		// 년도 정보는 있을때(번호판 없을때)
			break;
			
		case MapUtil.SELECT_YEAR_MONTH:
			mapVos = mapDao.getPlatesYMonth(msgMap);	// 월 클릭시(번호판 없을때)
			break;
			
		case MapUtil.SELECT_YEAR_MONTH_DAY:
			mapVos = mapDao.getPlatesYMDay(msgMap);		// 일 클릭시(번호판 없을때)
			break;
		}
//		
//		if (msgMap.get("year") == null && msgMap.get("month") == null && msgMap.get("day") == null)
//			mapVos = mapDao.getPlatesAll(msgMap);		// 날짜 정보가 없을때
//		
//		else if (msgMap.get("year") != null && msgMap.get("month") == null && msgMap.get("day") == null)
//			mapVos = mapDao.getPlatesYear(msgMap);		// 년도 정보는 있을때
//			
//		else if (msgMap.get("year") != null && msgMap.get("month") != null && msgMap.get("day") == null)
//			mapVos = mapDao.getPlatesYMonth(msgMap);	// 월 정보는 있을때
//			
//		else if (msgMap.get("year") != null && msgMap.get("month") != null && msgMap.get("day") != null)
//			mapVos = mapDao.getPlatesYMDay(msgMap);		// 날짜 정보 있을때
//		
		map.put("MapVo", mapVos);
		
		return map;
		
	}

	public Map<String, MapVo> getDetailItems(MapVo mapVo) {
		log.debug("");
		
		Map<String, MapVo> map = mapDao.getDetailItems(mapVo);
		
		return map;
	}

	public Map<String, Object>dbPlateInfos() {
		log.debug("");
		
		Map<String, Object> map = new HashMap<String, Object>();
		
		List<MapVo> mapVos = mapDao.dbPlateInfos();
		
		map.put("mapVos", mapVos);
		
		return map;
	}

	public Map<String, Object> getPlateDB(String plate) {
		log.debug("");
		
		
		int result = -1;
		Map<String, Object> map = new HashMap<String, Object>();
		List<MapVo> mapVos = mapDao.getPlateDB(plate);
		
		if (mapVos == null) { 
			map.put("mapVos", mapVos);
			return map;
		}else {
			result = mapDao.getPlateSearched(plate);
			if (result == MapUtil.NOT_PLATE_SEARCHED)
				map.put("result", MapUtil.NOT_PLATE_SEARCHED);
		}
		map.put("mapVos", mapVos);
		map.put("result", result);
		
		return map;
	}
	
	
	
	
}
