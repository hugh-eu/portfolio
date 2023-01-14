package com.group1.licensePlateTrace.userMapper;

import java.util.List;

import org.apache.ibatis.annotations.Delete;
import org.apache.ibatis.annotations.Insert;
import org.apache.ibatis.annotations.Mapper;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;
import org.apache.ibatis.annotations.Update;

import com.group1.licensePlateTrace.vo.UserVo;

@Mapper
public interface UserMapper {

	@Insert("INSERT INTO tbl_user ("
			+ "u_id, "
			+ "u_pw, "
			+ "u_name, "
			+ "u_mail, "
			+ "u_phone, "
			+ "u_reg_date, "
			+ "u_mod_date, "
			+ "a_no "
			+ ") VALUES ( "
			+ "#{u_id}, "
			+ "#{u_pw}, "
			+ "#{u_name}, "
			+ "#{u_mail}, "
			+ "#{u_phone}, "
			+ "NOW(), "
			+ "NOW(), "
			+ "3"
			+ ")")
	public int insertUserInfo(@Param("u_id") String u_id, 
							  @Param("u_pw") String u_pw, 
							  @Param("u_name") String u_name, 
							  @Param("u_mail") String u_mail, 
							  @Param("u_phone") String u_phone);

	@Select("SELECT "
			+ "u.u_no u_no, "
			+ "u.u_id u_id, "
			+ "u.u_pw u_pw, "
			+ "u.u_name u_name, "
			+ "u.u_mail u_mail, "
			+ "u.u_phone u_phone, "
			+ "u.u_reg_date u_reg_date, "
			+ "u.u_mod_date u_mod_date, "
			+ "a.a_no a_no, "
			+ "a.a_auth_info a_auth_info, "
			+ "a.a_reg_date a_reg_date, "
			+ "a.a_mod_date a_mod_date "
			+ "FROM tbl_user u "
			+ "JOIN tbl_auth a "
			+ "ON u.a_no = a.a_no "
			+ "WHERE u_id = #{u_id}")
	public UserVo selectUserById(@Param("u_id") String u_id);

	@Select("SELECT "
			+ "u.u_no u_no, "
			+ "u.u_id u_id, "
			+ "u.u_pw u_pw, "
			+ "u.u_name u_name, "
			+ "u.u_mail u_mail, "
			+ "u.u_phone u_phone, "
			+ "u.u_reg_date u_reg_date, "
			+ "u.u_mod_date u_mod_date, "
			+ "a.a_no a_no, "
			+ "a.a_auth_info a_auth_info, "
			+ "a.a_reg_date a_reg_date, "
			+ "a.a_mod_date a_mod_date "
			+ "FROM tbl_user u "
			+ "JOIN tbl_auth a "
			+ "ON u.a_no = a.a_no "
			+ "ORDER BY u_no ASC "
			+ "LIMIT #{skip}, #{amount}")
	public List<UserVo> selectAllUsers(@Param("skip") int skip, 
									   @Param("amount") int amount);

	@Select("SELECT "
			+ "u.u_no u_no, "
			+ "u.u_id u_id, "
			+ "u.u_pw u_pw, "
			+ "u.u_name u_name, "
			+ "u.u_mail u_mail, "
			+ "u.u_phone u_phone, "
			+ "u.u_reg_date u_reg_date, "
			+ "u.u_mod_date u_mod_date, "
			+ "a.a_no a_no, "
			+ "a.a_auth_info a_auth_info, "
			+ "a.a_reg_date a_reg_date, "
			+ "a.a_mod_date a_mod_date "
			+ "FROM tbl_user u "
			+ "JOIN tbl_auth a "
			+ "ON u.a_no = a.a_no "
			+ "WHERE u_name = #{u_name} "
			+ "ORDER BY u_no ASC "
			+ "LIMIT #{skip}, #{amount}")
	public List<UserVo> selectUsersByName(@Param("skip") int skip, 
										  @Param("amount") int amount, 
										  @Param("u_name") String u_name);
	
	@Select("SELECT COUNT(*) FROM tbl_user")
	public int selectAllUsersCnt();

	@Select("SELECT COUNT(*) FROM tbl_user WHERE u_name = #{u_name}")
	public int selectAllUsersCntByName(@Param("u_name") String u_name);

	@Update("UPDATE tbl_user SET u_pw = #{u_pw}, u_mod_date = NOW() WHERE u_no = #{u_no}")
	public int updateUserPw(@Param("u_no") int u_no, @Param("u_pw") String u_pw);

	@Update("UPDATE tbl_user SET u_name = #{u_name}, u_mod_date = NOW() WHERE u_no = #{u_no}")
	public int updateUserName(@Param("u_no") int u_no, @Param("u_name") String u_name);
	
	@Update("UPDATE tbl_user SET u_mail = #{u_mail}, u_mod_date = NOW() WHERE u_no = #{u_no}")
	public int updateUserEmail(@Param("u_no") int u_no, @Param("u_mail") String u_mail);
	
	@Update("UPDATE tbl_user SET u_phone = #{u_phone}, u_mod_date = NOW() WHERE u_no = #{u_no}")
	public int updateUserPhone(@Param("u_no") int u_no, @Param("u_phone") String u_phone);
	
	@Update("UPDATE tbl_user SET a_no = #{a_no}, u_mod_date = NOW() WHERE u_no = #{u_no}")
	public int updateUserAuth(@Param("u_no") int u_no, @Param("a_no") int a_no);

	@Delete("DELETE FROM tbl_user WHERE u_no = #{u_no}")
	public int deleteUser(@Param("u_no") int u_no);

}
