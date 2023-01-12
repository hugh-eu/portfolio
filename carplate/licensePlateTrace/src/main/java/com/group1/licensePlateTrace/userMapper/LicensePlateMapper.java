package com.group1.licensePlateTrace.userMapper;

import java.util.List;

import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;

import com.group1.licensePlateTrace.vo.LicensePlateVo;

@Mapper
public interface LicensePlateMapper {

	@Insert("INSERT INTO tbl_license_plate_search ("
			+ "u_no, "
			+ "s_name, "
			+ "s_info, "
			+ "s_reg_date, "
			+ "s_mod_date "
			+ ") VALUES ( "
			+ "#{u_no}, "
			+ "#{s_name}, "
			+ "#{s_info}, "
			+ "NOW(), "
			+ "NOW()"
			+ ")")
	int insertLicensePlate(@Param("s_name") String s_name, 
						   @Param("s_info") String s_info,
						   @Param("u_no") int u_no);

	@Select("SELECT COUNT(*) FROM tbl_license_plate_search WHERE u_no = #{u_no}")
	int selectAllLicensePlateCnt(@Param("u_no") int u_no);

	@Select("SELECT COUNT(*) FROM tbl_license_plate_search WHERE u_no = #{u_no} AND s_name = #{licensePlateName}")
	int selectAllLicensePlateCntByName(int u_no, String licensePlateName);
	
	@Select("SELECT * FROM tbl_license_plate_search WHERE u_no = #{u_no} ORDER BY s_reg_date DESC LIMIT #{skip}, #{amount}")
	List<LicensePlateVo> selectAllLicensePlateDESC(@Param("skip") int skip, 
												   @Param("amount") int amount,
												   @Param("u_no") int u_no);
	
	@Select("SELECT * FROM tbl_license_plate_search WHERE u_no = #{u_no} ORDER BY s_reg_date ASC LIMIT #{skip}, #{amount}")
	List<LicensePlateVo> selectAllLicensePlateASC(@Param("skip") int skip, 
												  @Param("amount") int amount,
												  @Param("u_no") int u_no);

	@Select("SELECT * FROM tbl_license_plate_search WHERE u_no = #{u_no} AND s_name = #{licensePlateName} ORDER BY s_reg_date DESC LIMIT #{skip}, #{amount}")
	List<LicensePlateVo> selectAllLicensePlateDESCByName(@Param("skip") int skip, 
														 @Param("amount") int amount, 
														 @Param("u_no") int u_no, 
														 @Param("licensePlateName") String licensePlateName);
	
	@Select("SELECT * FROM tbl_license_plate_search WHERE u_no = #{u_no} AND s_name = #{licensePlateName} ORDER BY s_reg_date ASC LIMIT #{skip}, #{amount}")
	List<LicensePlateVo> selectAllLicensePlateASCByName(@Param("skip") int skip, 
														@Param("amount") int amount, 
														@Param("u_no") int u_no, 
														@Param("licensePlateName") String licensePlateName);
	
	@Delete("DELETE FROM tbl_license_plate_search WHERE s_no = #{s_no}")
	int deleteLicensePlate(@Param("s_no") int s_no);

	@Update("UPDATE tbl_license_plate_search SET s_info = #{s_info}, s_mod_date = NOW() WHERE s_no = #{s_no}")
	int updateLicensePlateInfo(@Param("s_no") int s_no, 
							   @Param("s_info") String s_info);



}
