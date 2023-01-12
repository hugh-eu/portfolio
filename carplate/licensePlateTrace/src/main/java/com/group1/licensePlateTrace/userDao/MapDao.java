package com.group1.licensePlateTrace.userDao;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import com.group1.licensePlateTrace.userMapper.MapMapper;
import com.group1.licensePlateTrace.vo.MapDateVo;
import com.group1.licensePlateTrace.vo.MapVo;

import lombok.extern.slf4j.Slf4j;

@Component
@Slf4j
public class MapDao {

	@Autowired
	MapMapper mapMapper;

	/* 전체 조회 */
	public List<MapVo> getItems() {
		log.debug("");
		
		List<MapVo> mapVos = null;
		
		try {
			mapVos = mapMapper.selectItems();

			
		} catch (Exception e) {
			e.printStackTrace();
			
		}
		
		return mapVos;
		
	}

	/* 년도를 클릭시*/
	public List<MapVo> getYearItems(Map<String, String> msgMap) {
		log.debug("");
		
		List<MapVo> getYearItems = new ArrayList<MapVo>();
		
		getYearItems = null;
		
		if (msgMap.get("plate") == null) {
			// 번호판 정보가 없을시
			getYearItems = mapMapper.getYearItems(msgMap.get("year"));
			
		} else if (msgMap.get("plate") != null) {
			// 번호판 정보와 년도 정보가 있을시
			getYearItems = mapMapper.getYearPlateItems(msgMap.get("plate"), msgMap.get("year"));
			
		}
		
		return getYearItems;
	}
	
	/* DB에 검출된 년도 찾기 */
	public List<MapDateVo> getDate() {
		
		List<MapDateVo> mapDateVos = null;
		
		try {
			mapDateVos = mapMapper.selectYear();
			
			System.out.println("mapDateVos: \n" + mapDateVos);
			
		} catch (Exception e) {
			e.printStackTrace();
		}
		return mapDateVos;
	}

	/* DB에 검출된 월 찾기 */
	public List<MapDateVo> monthSelect(Map<String, String> msgMap) {
		
		List<MapDateVo> mapDateVos = null;
		
		try {
			if (msgMap.get("plate") == null)
				mapDateVos = mapMapper.selectMonth(msgMap.get("year"));
			
			else if (msgMap.get("plate") != null)
				mapDateVos = mapMapper.selectPMonth(msgMap.get("year"), msgMap.get("plate"));
			
		} catch (Exception e) {
			e.printStackTrace();
			
		}
		
		return mapDateVos;
		
	}
	
	/* DB에 검출된 일 찾기 */
	public List<MapDateVo> daySelect(Map<String, String> msgMap) {
		
		List<MapDateVo> mapDateVos = null;
		
		try {
			
			if (msgMap.get("plate") == null)
				mapDateVos = mapMapper.selectDay(msgMap.get("year"), msgMap.get("month"));
			
			else if (msgMap.get("plate") != null) 
				mapDateVos = mapMapper.selectPDay(msgMap.get("year"), msgMap.get("month"), msgMap.get("plate"));
			
		} catch (Exception e) {
			e.printStackTrace();
			
		}
		
		return mapDateVos;
		
	}
	
	/* 월 클릭시 */
	
	public List<MapVo> getMonthItems(Map<String, String> msgMap) {
		
		List<MapVo> mapVo = new ArrayList<MapVo>();
		
		mapVo = null;
		
		if (msgMap.get("plate") == null) {
			// 번호판 정보가 없을시
			mapVo = mapMapper.getMonthItems(msgMap.get("year"), msgMap.get("month"));
			
		} else if (msgMap.get("plate") != null) {
			// 번호판 정보와 년도 정보가 있을시
			mapVo = mapMapper.getPlateYMonth(msgMap.get("plate"), msgMap.get("year"), msgMap.get("month"));
			
		}
		
		return mapVo;
	}
	
	/* 일 클릭시 */
	public List<MapVo> getDayItems(Map<String, String> msgMap) {
		
		List<MapVo> mapVo = new ArrayList<MapVo>();
		
		mapVo = null;
		
		if (msgMap.get("plate") == null) {
			// 번호판 정보가 없을시
			mapVo = mapMapper.getDayItems(msgMap.get("year"), msgMap.get("month"), msgMap.get("day"));
			
		} else if (msgMap.get("plate") != null) {
			// 번호판 정보와 년도 정보가 있을시
			mapVo = mapMapper.getPlateYMDay(msgMap.get("plate"), msgMap.get("year"), msgMap.get("month"), msgMap.get("day"));
			
		}
		
		return mapVo;
	}

	public List<MapVo> getPlateItems(Map<String, String> msgMap) {
		
		List<MapVo> mapVo = mapMapper.getPlates(msgMap.get("year"), msgMap.get("month"), msgMap.get("day"), msgMap.get("plate"));
		
		return mapVo;
	}

	public List<MapVo> getPlateItem(Map<String, String> msgMap) {
		
		List<MapVo> mapVo = mapMapper.getPlate(msgMap.get("plate"));
		
		return mapVo;
	}


	public Map<String, MapVo> getDetailItems(MapVo mapVo) {
		
		Map<String, MapVo> map = 
				mapMapper.getDetailItems(mapVo.getL_no(), mapVo.getC_no());
		
		return map;
	}
	
	/* DB에 검출된 년도 찾기 */
	public List<MapDateVo> getDate(String plate) {

		List<MapDateVo> mapDateVos = null;
		
		try {
			if (plate != null) {
			
				mapDateVos = mapMapper.selectPlateYear(plate);                                                                                                                                              
				
				System.out.println("mapDateVos: \n" + mapDateVos);
				
			}else if (plate == null) 
				mapDateVos = mapMapper.selectYear();
			
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		return mapDateVos;
	}
	
	/* 전체 정보 리스트 출력 */
	public List<MapVo> getPlatesAll(Map<String, String> msgMap) {
		
		List<MapVo> mapVo = new ArrayList<MapVo>();
		
		mapVo = null;
		if (msgMap.get("plate") == null) 
			mapVo = mapMapper.getListAll(msgMap.get("c_no"));
		
		else if (msgMap.get("plate") != null)
			mapVo = mapMapper.getListPlate(msgMap.get("c_no"), msgMap.get("plate"));
		
		return mapVo;
	}
	
	/* 년도 정보 있을때 리스트 출력 */
	public List<MapVo> getPlatesYear(Map<String, String> msgMap) {
		List<MapVo> mapVo = new ArrayList<MapVo>();

		mapVo = null;
		if (msgMap.get("plate") == null) 
			mapVo = mapMapper.getListYear(msgMap.get("year"), msgMap.get("c_no"));
		
		else if (msgMap.get("plate") != null)
			mapVo = mapMapper.getListPYear(msgMap.get("year"), msgMap.get("c_no"), msgMap.get("plate"));
		
		return mapVo;
	}
	
	/* 년월 정보 있을때 리스트 출력 */
	public List<MapVo> getPlatesYMonth(Map<String, String> msgMap) {
		List<MapVo> mapVo = new ArrayList<MapVo>();

		mapVo = null;
		if (msgMap.get("plate") == null) 
			mapVo = mapMapper.getListYMonth(msgMap.get("year"), msgMap.get("month"), msgMap.get("c_no"));
		
		else if (msgMap.get("plate") != null)
			mapVo = mapMapper.getListPYMonth(msgMap.get("year"), msgMap.get("month"), msgMap.get("c_no"), msgMap.get("plate"));
		
		return mapVo;
	}

	/* 날짜 정보 있을때 리스트 출력 */
	public List<MapVo> getPlatesYMDay(Map<String, String> msgMap) {
		List<MapVo> mapVo = new ArrayList<MapVo>();

		mapVo = null;
		if (msgMap.get("plate") == null) 
			mapVo = mapMapper.getListYMDay(msgMap.get("year"), msgMap.get("month"), msgMap.get("day"), msgMap.get("c_no"));
		
		else if (msgMap.get("plate") != null)
			mapVo = mapMapper.getListPYMDay(msgMap.get("year"), msgMap.get("month"), msgMap.get("day"), msgMap.get("c_no"), msgMap.get("plate"));
		
		return mapVo;
	}
	
	/* DB에 등록된 번호판 조회 */
	public List<MapVo> dbPlateInfos() {
		log.debug("");
		
		List<MapVo> mapVos = new ArrayList<MapVo>();
		
		mapVos = null;
		try {
			
			mapVos = mapMapper.dbPlateInfos();
			
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		return mapVos;
	}
	
	/* 번호판이 있나 없나 확인 */
	public List<MapVo> getPlateDB(String plate) {
		log.debug("");
		
		List<MapVo> mapVos = new ArrayList<MapVo>();
		
		try {
			
			mapVos = mapMapper.getPlateDB(plate);
			
		} catch (Exception e) {
			e.printStackTrace();
		}
	
		return mapVos.size() >= 0 ? mapVos : null;
	}
	
	/* 번호판의 검출 데이터가 있나 없나 확인 */
	public int getPlateSearched(String plate) {
		log.debug("");
		
		int result = -1;
		try {
			
			result = mapMapper.getPlateSearched(plate);
			
		} catch (Exception e) {
			e.printStackTrace();
		}
		
		return result <= 0 ? -1 : result;
	}
	
}
