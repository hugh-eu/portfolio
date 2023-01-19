package com.group1.licensePlateTrace.userMapper;

import java.util.List;

import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

import com.group1.licensePlateTrace.vo.MapDateVo;
import com.group1.licensePlateTrace.vo.MapVo;

@Mapper
public interface MapMapper {
	
	/* 전체정보 조회 */
	@Select("SELECT * FROM tbl_license_plate_search s "
			+ "JOIN tbl_license_plate_info l "
			+ "ON l.l_info = s.s_name "
			+ "JOIN tbl_camera c "
			+ "ON c.c_no = l.c_no "
			+ "ORDER BY l.l_info_reg_date DESC LIMIT 100")
	public List<MapVo> selectItems();
	
	/* 카메라 정보 이용해서 조회 */
	@Select("SELECT "
			+ "l.l_no l_no, "
			+ "l.l_info l_info, "
			+ "l.l_info_reg_date l_info_reg_date, "
			+ "l.l_img_name l_img_name, "
			+ "l.c_no c_no, "
			+ "s.s_no s_no, "
			+ "s.s_name s_name, "
			+ "s.s_info s_info, "
			+ "s.s_reg_date s_reg_date, "
			+ "s.s_mod_date s_mod_date "
			+ "FROM tbl_license_plate_info l "
			+ "JOIN tbl_license_plate_search s "
			+ "ON l.l_info = s.s_name "
			+ "WHERE c_no = #{c_no}")
	public List<MapVo> selectCnoItems(@Param("c_no") String c_no);
	
	/* 날짜 정보 이용해서 조회 */
	@Select("SELECT "
			+ "l.l_no l_no, "
			+ "l.l_info l_info, "
			+ "l.l_info_reg_date l_info_reg_date, "
			+ "l.l_img_name l_img_name, "
			+ "l.c_no c_no, "
			+ "s.s_no s_no, "
			+ "s.s_name s_name, "
			+ "s.s_info s_info, "
			+ "s.s_reg_date s_reg_date, "
			+ "s.s_mod_date s_mod_date "
			+ "FROM tbl_license_plate_info l "
			+ "JOIN tbl_license_plate_search s "
			+ "ON l.l_info = s.s_name "
			+ "WHERE DATE(l_info_reg_date) = #{l_info_reg_date}")
	public List<MapVo> getItemDate(@Param("l_info_reg_date") String l_info_reg_date);
	
	/* 년도를 클릭 했을때 */
	@Select("SELECT * FROM tbl_license_plate_search s "
			+ "JOIN tbl_license_plate_info l "
			+ "ON l.l_info = s.s_name "
			+ "JOIN tbl_camera c "
			+ "ON c.c_no = l.c_no "
			+ "WHERE year(l_info_reg_date) = #{year} "
			+ "ORDER BY l_info_reg_date DESC")
	public List<MapVo> getYearItems(@Param("year") String year);
	
	/* 번호판정보가 있고 년도를 클릭했을시 */
	@Select("SELECT * FROM tbl_license_plate_search s "
			+ "JOIN tbl_license_plate_info l "
			+ "ON l.l_info = s.s_name "
			+ "JOIN tbl_camera c "
			+ "ON c.c_no = l.c_no "
			+ "WHERE l.l_info = #{plate} "
			+ "AND year(l_info_reg_date) = #{year} "
			+ "ORDER BY l_info_reg_date DESC")
	public List<MapVo> getYearPlateItems(@Param("plate") String plate,
										 @Param("year") String year);
	
	/* 월 클릭했을때 */
	@Select("SELECT * FROM tbl_license_plate_search s "
			+ "JOIN tbl_license_plate_info l "
			+ "ON l.l_info = s.s_name "
			+ "JOIN tbl_camera c "
			+ "ON c.c_no = l.c_no "
			+ "AND DATE(l.l_info_reg_date) "
			+ "WHERE year(l_info_reg_date) = #{year} "
			+ "AND month(l_info_reg_date) = #{month} "
			+ "ORDER BY l_info_reg_date DESC")
	public List<MapVo> getMonthItems(@Param("year") String year,
									 @Param("month") String month);
	
	/* 번호판 정보가 있고 년도 월을 선택 했을때 */
	@Select("SELECT * FROM tbl_license_plate_search s "
			+ "JOIN tbl_license_plate_info l "
			+ "ON l.l_info = s.s_name "
			+ "JOIN tbl_camera c ON c.c_no = l.c_no "
			+ "AND DATE(l.l_info_reg_date) "
			+ "WHERE l.l_info = #{plate} "
			+ "AND year(l_info_reg_date) = #{year} "
			+ "AND month(l_info_reg_date) = #{month} "
			+ "ORDER BY l_info_reg_date DESC")
	public List<MapVo> getPlateYMonth(@Param("plate") String plate,
									 @Param("year") String year,
									 @Param("month") String month);
	
	
	/* 일 클릭했을때 */
	@Select("SELECT * FROM tbl_license_plate_search s "
			+ "JOIN tbl_license_plate_info l "
			+ "ON l.l_info = s.s_name "
			+ "JOIN tbl_camera c "
			+ "ON c.c_no = l.c_no AND "
			+ "DATE(l.l_info_reg_date) "
			+ "WHERE year(l_info_reg_date) = #{year} "
			+ "AND month(l_info_reg_date) = #{month} "
			+ "AND day(l_info_reg_date) = #{day} "
			+ "ORDER BY l_info_reg_date DESC")
	public List<MapVo> getDayItems(@Param("year") String year,
			 					   @Param("month") String month,
			 					   @Param("day") String day);
	
	/* 번호판 정보가 있고 년도 월 일 설정했을때 */
	@Select("SELECT * FROM tbl_license_plate_search s "
			+ "JOIN tbl_license_plate_info l "
			+ "ON l.l_info = s.s_name "
			+ "JOIN tbl_camera c "
			+ "ON c.c_no = l.c_no "
			+ "AND DATE(l.l_info_reg_date) "
			+ "WHERE l.l_info = #{plate} "
			+ "AND year(l_info_reg_date) = #{year} "
			+ "AND MONTH(l_info_reg_date) = #{month} "
			+ "AND DAY(l_info_reg_date) = #{day} "
			+ "ORDER BY l_info_reg_date DESC;")
	public List<MapVo> getPlateYMDay(@Param("plate") String plate,
									 @Param("year") String year,
				 					 @Param("month") String month,
				 					 @Param("day") String day);
	
	/* 카메라 정보 날짜 정보를 이용해서 조회 */
	@Select("SELECT "
			+ "l.l_no l_no, "
			+ "l.l_info l_info, "
			+ "l.l_info_reg_date l_info_reg_date, "
			+ "l.l_img_name l_img_name, "
			+ "l.c_no c_no, "
			+ "s.s_no s_no, "
			+ "s.s_name s_name, "
			+ "s.s_info s_info, "
			+ "s.s_reg_date s_reg_date, "
			+ "s.s_mod_date s_mod_date "
			+ "FROM tbl_license_plate_info l "
			+ "JOIN tbl_license_plate_search s "
			+ "ON l.l_info = s.s_name "
			+ "WHERE c_no = #{c_no} AND DATE(l_info_reg_date) = #{l_info_reg_date}")
	public List<MapVo> selectCnoRegDateItems(@Param("c_no") String c_no, @Param("l_info_reg_date") String l_info_reg_date);
	
	/* 년도 구하기 */
	@Select("SELECT s.s_reg_date, "
			+ "l.l_info_reg_date, "
			+ "l.l_info, s.s_name "
			+ "FROM tbl_license_plate_search s JOIN tbl_license_plate_info l "
			+ "WHERE l.l_info = s.s_name "
			+ "AND YEAR(l.l_info_reg_date) = l.l_info_reg_date ORDER BY l.l_info_reg_date DESC")
	public List<MapDateVo> selectYear();
	
	/* 번호에 따른 년도 구하기 */
	@Select("SELECT s.s_reg_date, l.l_info_reg_date, l.l_info, s.s_name "
			+ "FROM tbl_license_plate_search s "
			+ "JOIN tbl_license_plate_info l "
			+ "WHERE l.l_info = s.s_name "
			+ "AND l.l_info = #{plate} "
			+ "AND YEAR(l.l_info_reg_date) = l.l_info_reg_date "
			+ "ORDER BY l.l_info_reg_date DESC")
	public List<MapDateVo> selectPlateYear(@Param("plate") String plate);
	
	/* 달 구하기 */
	@Select("SELECT s.s_reg_date, l.l_info_reg_date, l.l_info, s.s_name "
			+ "FROM tbl_license_plate_search s "
			+ "JOIN tbl_license_plate_info l "
			+ "WHERE l.l_info = s.s_name "
			+ "AND YEAR(l.l_info_reg_date) = #{year} "
			+ "ORDER BY l.l_info_reg_date DESC")
	public List<MapDateVo> selectMonth(@Param("year") String year);
	
	/* 달 구하기 번호판 정보가 있을때 */
	@Select("SELECT s.s_reg_date, l.l_info_reg_date, l.l_info, s.s_name "
			+ "FROM tbl_license_plate_search s "
			+ "JOIN tbl_license_plate_info l "
			+ "WHERE l.l_info = s.s_name "
			+ "AND YEAR(l.l_info_reg_date) = #{year} "
			+ "AND l.l_info = #{plate} "
			+ "ORDER BY l.l_info_reg_date DESC")
	public List<MapDateVo> selectPMonth(@Param("year") String year,
										@Param("plate") String plate);
	
	/* 일 구하기 */
	@Select("SELECT s.s_reg_date, l.l_info_reg_date, l.l_info, s.s_name "
			+ "FROM tbl_license_plate_search s "
			+ "JOIN tbl_license_plate_info l "
			+ "WHERE l.l_info = s.s_name "
			+ "AND YEAR(l.l_info_reg_date) = #{year} "
			+ "AND month(l.l_info_reg_date) = #{month} "
			+ "ORDER BY l.l_info_reg_date DESC")
	public List<MapDateVo> selectDay(@Param("year") String year,
									 @Param("month") String month);
	
	/* 일 구하기 번호판 있을시 */
	@Select("SELECT s.s_reg_date, l.l_info_reg_date, l.l_info, s.s_name "
			+ "FROM tbl_license_plate_search s "
			+ "JOIN tbl_license_plate_info l "
			+ "WHERE l.l_info = s.s_name "
			+ "AND YEAR(l.l_info_reg_date) = #{year} "
			+ "AND month(l.l_info_reg_date) = #{month} "
			+ "AND l.l_info = #{plate} "
			+ "ORDER BY l.l_info_reg_date DESC")
	public List<MapDateVo> selectPDay(@Param("year") String year,
									  @Param("month") String month,
									  @Param("plate") String plate);
	
	/* 차량번호로 검색하기 */
	@Select("SELECT * FROM tbl_license_plate_search s "
			+ "JOIN tbl_license_plate_info l "
			+ "ON l.l_info = s.s_name "
			+ "JOIN tbl_camera c ON c.c_no = l.c_no "
			+ "AND DATE(l.l_info_reg_date) "
			+ "WHERE year(l_info_reg_date) = #{year} "
			+ "AND month(l_info_reg_date) = #{month} "
			+ "AND day(l_info_reg_date) = #{day} "
			+ "AND l_info = #{plate} "
			+ "ORDER BY l_info_reg_date DESC")
	public List<MapVo> getPlates(@Param("year") String year,
								@Param("month") String month,
								@Param("day") String day,
								@Param("plate") String plate);
	
	/* 번호판 정보는 있고 날짜 정보가 없을때 */
	@Select("SELECT * FROM tbl_license_plate_search s "
			+ "JOIN tbl_license_plate_info l "
			+ "ON l.l_info = s.s_name "
			+ "JOIN tbl_camera c "
			+ "ON c.c_no = l.c_no "
			+ "WHERE l_info = #{plate} "
			+ "ORDER BY l_info_reg_date DESC")
	public List<MapVo> getPlate(@Param("plate") String plate);
	
	
	/* 날짜 정보가 없을때 */
	@Select("SELECT * FROM tbl_license_plate_search s "
			+ "JOIN tbl_license_plate_info l "
			+ "ON l.l_info = s.s_name "
			+ "JOIN tbl_camera c "
			+ "ON c.c_no = l.c_no "
			+ "AND DATE(l.l_info_reg_date) "
			+ "WHERE l.c_no = #{c_no} "
			+ "ORDER BY l_info_reg_date DESC "
			+ "LIMIT #{skip}, #{amount}")
	public List<MapVo> getListAll(@Param("c_no") String c_no,
								  @Param("skip") int skip,
								  @Param("amount") int amount);
	
	/* 날짜 정보가 없을때 전체 숫자*/
	@Select("SELECT COUNT(*) FROM tbl_license_plate_search s "
			+ "JOIN tbl_license_plate_info l "
			+ "ON l.l_info = s.s_name "
			+ "JOIN tbl_camera c "
			+ "ON c.c_no = l.c_no "
			+ "AND DATE(l.l_info_reg_date) "
			+ "WHERE l.c_no = #{c_no} "
			+ "ORDER BY l_info_reg_date DESC ")
	public int getListAlls(@Param("c_no") String c_no);
	
	
	/* 번호판 정보는 있고 날짜 정보는 없을때 */
	@Select("SELECT * FROM tbl_license_plate_search s "
			+ "JOIN tbl_license_plate_info l "
			+ "ON l.l_info = s.s_name "
			+ "JOIN tbl_camera c "
			+ "ON c.c_no = l.c_no "
			+ "AND DATE(l.l_info_reg_date) "
			+ "WHERE l.c_no = #{c_no} "
			+ "AND l.l_info = #{plate} "
			+ "ORDER BY l_info_reg_date DESC "
			+ "LIMIT #{skip}, #{amount}")
	public List<MapVo> getListPlate(@Param("c_no") String c_no,
									@Param("plate") String plate,
									@Param("skip") int skip,
									@Param("amount") int amount);
	
	/* 번호판 정보는 있고 날짜 정보는 없을때 전체 숫자*/
	@Select("SELECT count(*) FROM "
			+ "tbl_license_plate_search s "
			+ "JOIN tbl_license_plate_info l "
			+ "ON l.l_info = s.s_name "
			+ "JOIN tbl_camera c ON "
			+ "c.c_no = l.c_no "
			+ "AND DATE(l.l_info_reg_date) "
			+ "WHERE l.c_no = #{c_no} "
			+ "AND l.l_info = #{plate} "
			+ "ORDER BY l_info_reg_date DESC")
	public int getPlateCount(@Param("c_no") String c_no,
							 @Param("plate") String plate);
	
	/* 년도 정보만 있을때 */
	@Select("SELECT * FROM tbl_license_plate_search s "
			+ "JOIN tbl_license_plate_info l "
			+ "ON l.l_info = s.s_name "
			+ "JOIN tbl_camera c "
			+ "ON c.c_no = l.c_no "
			+ "AND DATE(l.l_info_reg_date) "
			+ "WHERE YEAR(l_info_reg_date) = #{year} "
			+ "AND l.c_no = #{c_no} "
			+ "ORDER BY l_info_reg_date DESC "
			+ "LIMIT #{skip}, #{amount}")
	public List<MapVo> getListYear(@Param("year") String year,
								   @Param("c_no") String c_no,
								   @Param("skip") int skip,
								   @Param("amount") int amount);
	
	/* 년도 정보만 있을때 전체 숫자 */
	@Select("SELECT count(*) FROM tbl_license_plate_search s "
			+ "JOIN tbl_license_plate_info l "
			+ "ON l.l_info = s.s_name "
			+ "JOIN tbl_camera c "
			+ "ON c.c_no = l.c_no "
			+ "AND DATE(l.l_info_reg_date) "
			+ "WHERE YEAR(l_info_reg_date) = #{year} "
			+ "AND l.c_no = #{c_no} "
			+ "ORDER BY l_info_reg_date DESC")
	public int getCountYear(@Param("year") String year,
								 @Param("c_no") String c_no);
	
	/* 년도 정보 AND 번호판 정보 있을때 */
	@Select("SELECT * FROM tbl_license_plate_search s "
			+ "JOIN tbl_license_plate_info l "
			+ "ON l.l_info = s.s_name "
			+ "JOIN tbl_camera c "
			+ "ON c.c_no = l.c_no "
			+ "WHERE YEAR(l_info_reg_date) = #{year} "
			+ "AND l.c_no = #{c_no} "
			+ "AND l.l_info = #{plate} "
			+ "ORDER BY l_info_reg_date DESC "
			+ "LIMIT #{skip}, #{amount}")
	public List<MapVo> getListPYear(@Param("year") String year,
									@Param("c_no") String c_no,
									@Param("plate") String plate,
									@Param("skip") int skip,
									@Param("amount") int amount);
	
	/* 년도 정보 AND 번호판 정보 있을때 전체 숫자 */
	@Select("SELECT count(*) FROM tbl_license_plate_search s "
			+ "JOIN tbl_license_plate_info l "
			+ "ON l.l_info = s.s_name "
			+ "JOIN tbl_camera c "
			+ "ON c.c_no = l.c_no "
			+ "WHERE YEAR(l_info_reg_date) = #{year} "
			+ "AND l.c_no = #{c_no} "
			+ "AND l.l_info = #{plate} "
			+ "ORDER BY l_info_reg_date DESC ")
	public int getPlateCountYear(@Param("year") String year,
										 @Param("c_no") String c_no,
										 @Param("plate") String plate);
	
	/* 년월 정보만 있을때 */
	@Select("SELECT * FROM tbl_license_plate_search s "
			+ "JOIN tbl_license_plate_info l "
			+ "ON l.l_info = s.s_name "
			+ "JOIN tbl_camera c "
			+ "ON c.c_no = l.c_no "
			+ "WHERE YEAR(l_info_reg_date) = #{year} "
			+ "AND MONTH(l_info_reg_date) = #{month} "
			+ "AND l.c_no = #{c_no} "
			+ "ORDER BY l_info_reg_date DESC "
			+ "LIMIT #{skip}, #{amount}")
	public List<MapVo> getListYMonth(@Param("year") String year,
			   						 @Param("month") String month,
			   						 @Param("c_no") String c_no,
			   						 @Param("skip") int skip,
			   						 @Param("amount") int amount);
	
	/* 년월 정보만 있을때  전체 숫자*/
	@Select("SELECT count(*) FROM tbl_license_plate_search s "
			+ "JOIN tbl_license_plate_info l "
			+ "ON l.l_info = s.s_name "
			+ "JOIN tbl_camera c "
			+ "ON c.c_no = l.c_no "
			+ "WHERE YEAR(l_info_reg_date) = #{year} "
			+ "AND MONTH(l_info_reg_date) = #{month} "
			+ "AND l.c_no = #{c_no} "
			+ "ORDER BY l_info_reg_date DESC ")
	public int getCountYMonth(@Param("year") String year,
							  @Param("month") String month,
							  @Param("c_no") String c_no);
	
	/* 년월 정보 번호판 정보 있을때 */
	@Select("SELECT * FROM tbl_license_plate_search s "
			+ "JOIN tbl_license_plate_info l "
			+ "ON l.l_info = s.s_name "
			+ "JOIN tbl_camera c "
			+ "ON c.c_no = l.c_no "
			+ "WHERE YEAR(l_info_reg_date) = #{year} "
			+ "AND MONTH(l_info_reg_date) = #{month} "
			+ "AND l.c_no = #{c_no} "
			+ "AND l.l_info = #{plate} "
			+ "ORDER BY l_info_reg_date DESC "
			+ "LIMIT #{skip}, #{amount}")
	public List<MapVo> getListPYMonth(@Param("year") String year,
									  @Param("month") String month,
									  @Param("c_no") String c_no,
									  @Param("plate") String plate,
									  @Param("skip") int skip,
				   					  @Param("amount") int amount);
	
	/* 년월 정보 번호판 정보 있을때 전체 번호 출력 */
	@Select("SELECT count(*) FROM tbl_license_plate_search s "
			+ "JOIN tbl_license_plate_info l "
			+ "ON l.l_info = s.s_name "
			+ "JOIN tbl_camera c "
			+ "ON c.c_no = l.c_no "
			+ "WHERE YEAR(l_info_reg_date) = #{year} "
			+ "AND MONTH(l_info_reg_date) = #{month} "
			+ "AND l.c_no = #{c_no} "
			+ "AND l.l_info = #{plate} "
			+ "ORDER BY l_info_reg_date DESC ")
	public int getPlateCountYMonth(@Param("year") String year,
								   @Param("month") String month,
								   @Param("c_no") String c_no,
								   @Param("plate") String plate);

	/* 카메라 정보, 날짜로 리스트 뿌려주기 */
	@Select("SELECT * FROM tbl_license_plate_search s "
			+ "JOIN tbl_license_plate_info l "
			+ "ON l.l_info = s.s_name "
			+ "JOIN tbl_camera c "
			+ "ON c.c_no = l.c_no "
			+ "AND DATE(l.l_info_reg_date) "
			+ "WHERE YEAR(l_info_reg_date) = #{year} "
			+ "AND MONTH(l_info_reg_date) = #{month} "
			+ "AND DAY(l_info_reg_date) = #{day} "
			+ "AND l.c_no = #{c_no} "
			+ "ORDER BY l_info_reg_date DESC "
			+ "LIMIT #{skip}, #{amount}")
	public List<MapVo> getListYMDay(@Param("year") String year,
									@Param("month") String month,
									@Param("day") String day,
									@Param("c_no") String c_no,
									@Param("skip") int skip,
				   					@Param("amount") int amount);
	
	/* 카메라 정보, 날짜로 리스트 뿌려주기 전체 숫자 */
	@Select("SELECT count(*) FROM tbl_license_plate_search s "
			+ "JOIN tbl_license_plate_info l "
			+ "ON l.l_info = s.s_name "
			+ "JOIN tbl_camera c "
			+ "ON c.c_no = l.c_no "
			+ "AND DATE(l.l_info_reg_date) "
			+ "WHERE YEAR(l_info_reg_date) = #{year} "
			+ "AND MONTH(l_info_reg_date) = #{month} "
			+ "AND DAY(l_info_reg_date) = #{day} "
			+ "AND l.c_no = #{c_no} "
			+ "ORDER BY l_info_reg_date DESC ")
	public int getCountYMDay(@Param("year") String year,
							 @Param("month") String month,
							 @Param("day") String day,
							 @Param("c_no") String c_no);
	
	/* 카메라 정보, 날짜로 번호판 있을때 리스트 뿌려주기 */
	@Select("SELECT * FROM tbl_license_plate_search s "
			+ "JOIN tbl_license_plate_info l "
			+ "ON l.l_info = s.s_name "
			+ "JOIN tbl_camera c "
			+ "ON c.c_no = l.c_no "
			+ "AND DATE(l.l_info_reg_date) "
			+ "WHERE YEAR(l_info_reg_date) = #{year} "
			+ "AND MONTH(l_info_reg_date) = #{month} "
			+ "AND DAY(l_info_reg_date) = #{day} "
			+ "AND l.c_no = #{c_no} "
			+ "AND l.l_info = #{plate} "
			+ "ORDER BY l_info_reg_date DESC "
			+ "LIMIT #{skip}, #{amount}")
	public List<MapVo> getListPYMDay(@Param("year") String year,
									 @Param("month") String month,
									 @Param("day") String day,
									 @Param("c_no") String c_no,
									 @Param("plate") String plate,
									 @Param("skip") int skip,
					   				 @Param("amount") int amount);
	
	/* 카메라 정보, 날짜로 번호판 있을때 리스트 뿌려주기 전체 숫자 */
	@Select("SELECT count(*) FROM tbl_license_plate_search s "
			+ "JOIN tbl_license_plate_info l "
			+ "ON l.l_info = s.s_name "
			+ "JOIN tbl_camera c "
			+ "ON c.c_no = l.c_no "
			+ "AND DATE(l.l_info_reg_date) "
			+ "WHERE YEAR(l_info_reg_date) = #{year} "
			+ "AND MONTH(l_info_reg_date) = #{month} "
			+ "AND DAY(l_info_reg_date) = #{day} "
			+ "AND l.c_no = #{c_no} "
			+ "AND l.l_info = #{plate} "
			+ "ORDER BY l_info_reg_date DESC ")
	public int getPlateCountYMDay(@Param("year") String year,
								  @Param("month") String month,
								  @Param("day") String day,
								  @Param("c_no") String c_no,
								  @Param("plate") String plate);
	
	/* 디테일 뷰 정보들 넣어줄때 */
	@Select("SELECT  * FROM tbl_license_plate_search s "
			+ "JOIN tbl_license_plate_info l "
			+ "ON l.l_info = s.s_name "
			+ "JOIN tbl_camera c "
			+ "ON c.c_no = l.c_no "
			+ "AND DATE(l.l_info_reg_date) "
			+ "WHERE l.l_no = #{l_no} "
			+ "AND l.c_no = #{c_no} "
			+ "ORDER BY l_info_reg_date DESC")
	public MapVo getDetailItems(@Param("l_no") int l,
								@Param("c_no") int j);
	
	/* DB에 등록된 번호판 조회 */
	@Select("SELECT * FROM tbl_license_plate_search")
	public List<MapVo> dbPlateInfos();

	/* 번호판 체크 */
	@Select("SELECT * FROM tbl_license_plate_search WHERE s_name = #{plate}")
	public List<MapVo> getPlateDB(@Param("plate") String plate);
	
	/* 번호판의 검출 데이터 확인 */
	@Select("SELECT COUNT(*) FROM  tbl_license_plate_search s "
			+ "JOIN tbl_license_plate_info l "
			+ "ON l.l_info = s.s_name "
			+ "JOIN tbl_camera c "
			+ "WHERE s.s_name = #{plate} "
			+ "ORDER BY l.l_info_reg_date DESC")
	public int getPlateSearched(@Param("plate") String plate);
	
	
}
