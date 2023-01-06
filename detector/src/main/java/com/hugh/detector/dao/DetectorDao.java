package com.hugh.detector.dao;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.RowMapper;
import org.springframework.stereotype.Component;

import com.hugh.detector.service.DetectorService;
import com.hugh.detector.vo.DetectorVo;

@Component
public class DetectorDao {
	
	@Autowired
	private JdbcTemplate jdbcTemplate;
	

	public DetectorVo confirmLogin(DetectorVo detectorVo) {
		System.out.println("[DetectorDao] confirmLogin() called.");
		
		String sql = "SELECT * FROM tbl_users WHERE u_id=? AND u_pw=?";
		
		List<DetectorVo> detectorVos = jdbcTemplate.query(sql, new RowMapper<DetectorVo> () {

			@Override
			public DetectorVo mapRow(ResultSet rs, int rowNum) throws SQLException {
				
				DetectorVo detectorVo = new DetectorVo();
				detectorVo.setU_no(rs.getInt("u_no"));
				detectorVo.setU_id(rs.getString("u_id"));
				detectorVo.setU_pw(rs.getString("u_pw"));
				detectorVo.setU_auth(rs.getString("u_auth"));
				detectorVo.setU_reg_date(rs.getString("u_reg_date"));
				detectorVo.setU_mod_date(rs.getString("u_mod_date"));
				
				return detectorVo;
			}
			
		}, detectorVo.getU_id(), detectorVo.getU_pw());
		
		return detectorVos.size() > 0 ? detectorVos.get(0) : null;
	}


	public int confirmSignUp(DetectorVo detectorVo) {
		System.out.println("[DetectorDao] confirmSignUp() called.");
		
		String sql = "SELECT * FROM tbl_users WHERE u_id=?";
		
		List<DetectorVo> detectorVos = jdbcTemplate.query(sql, new RowMapper<DetectorVo> () {

			@Override
			public DetectorVo mapRow(ResultSet rs, int rowNum) throws SQLException {
				
				DetectorVo detectorVo = new DetectorVo();
				detectorVo.setU_no(rs.getInt("u_no"));
				detectorVo.setU_id(rs.getString("u_id"));
				detectorVo.setU_pw(rs.getString("u_pw"));
				detectorVo.setU_auth(rs.getString("u_auth"));
				detectorVo.setU_reg_date(rs.getString("u_reg_date"));
				detectorVo.setU_mod_date(rs.getString("u_mod_date"));
				
				return detectorVo;
			}
			
		}, detectorVo.getU_id());

		if (detectorVos.size() == 0) {
			sql = "INSERT INTO tbl_users (u_id, u_pw, u_auth, u_reg_date, u_mod_date) VALUES (?, ?, 'X', NOW(), NOW())";
			int result = jdbcTemplate.update(sql, detectorVo.getU_id(), detectorVo.getU_pw());
			
			return result;
		} else {
			
			return DetectorService.SIGNUP_DUPLICATE;
		}
	}


	public List<DetectorVo> getDetectedList() {
		System.out.println("[DetectorDao] confirmSignUp() called.");
		
		String sql = "SELECT * FROM tbl_imgs ORDER BY i_no DESC";
		
		List<DetectorVo> detectorVos = jdbcTemplate.query(sql, new RowMapper<DetectorVo> () {

			@Override
			public DetectorVo mapRow(ResultSet rs, int rowNum) throws SQLException {
				
				DetectorVo detectorVo = new DetectorVo();
				detectorVo.setI_no(rs.getInt("i_no"));
				detectorVo.setI_device(rs.getString("i_device"));
				detectorVo.setI_img_name(rs.getString("i_img_name"));
				detectorVo.setI_reg_date(rs.getString("i_reg_date"));
				
				return detectorVo;
			}
			
		});
		
		return detectorVos;
	}


	public List<DetectorVo> getUserList() {
		System.out.println("[DetectorDao] getUserList() called.");
		
		String sql = "SELECT * FROM tbl_users";
		
		List<DetectorVo> detectorVos = jdbcTemplate.query(sql, new RowMapper<DetectorVo> () {

			@Override
			public DetectorVo mapRow(ResultSet rs, int rowNum) throws SQLException {
				
				DetectorVo detectorVo = new DetectorVo();
				detectorVo.setU_no(rs.getInt("u_no"));
				detectorVo.setU_id(rs.getString("u_id"));
				detectorVo.setU_pw(rs.getString("u_pw"));
				detectorVo.setU_auth(rs.getString("u_auth"));
				detectorVo.setU_reg_date(rs.getString("u_reg_date"));
				detectorVo.setU_mod_date(rs.getString("u_mod_date"));
				
				return detectorVo;
			}
			
		});
		
		return detectorVos;
	}


	public List<DetectorVo> changeAuth(int u_no, String u_auth) {
		System.out.println("[DetectorDao] changeAuth() called.");
		
		String sql = "UPDATE tbl_users SET u_auth = ?, u_mod_date = NOW() WHERE u_no = ?";
		int result = jdbcTemplate.update(sql, u_auth, u_no);
		if (result > 0) {
			sql = "SELECT * FROM tbl_users";
			
			List<DetectorVo> detectorVos = jdbcTemplate.query(sql, new RowMapper<DetectorVo> () {

				@Override
				public DetectorVo mapRow(ResultSet rs, int rowNum) throws SQLException {
					
					DetectorVo detectorVo = new DetectorVo();
					detectorVo.setU_no(rs.getInt("u_no"));
					detectorVo.setU_id(rs.getString("u_id"));
					detectorVo.setU_pw(rs.getString("u_pw"));
					detectorVo.setU_auth(rs.getString("u_auth"));
					detectorVo.setU_reg_date(rs.getString("u_reg_date"));
					detectorVo.setU_mod_date(rs.getString("u_mod_date"));
					
					return detectorVo;
				}
				
			});
			
			return detectorVos;
		} else {
			
			return null;
		}
		
	}


	public List<DetectorVo> getDetectedListMonthly(String month) {
		System.out.println("[DetectorDao] getDetectedListMonthly() called.");
		
		String sql = "SELECT * FROM tbl_imgs WHERE DATE_FORMAT(i_reg_date, '%Y-%m') = ? ORDER BY i_no DESC";
		
		List<DetectorVo> detectorVos = jdbcTemplate.query(sql, new RowMapper<DetectorVo> () {

			@Override
			public DetectorVo mapRow(ResultSet rs, int rowNum) throws SQLException {
				
				DetectorVo detectorVo = new DetectorVo();
				detectorVo.setI_no(rs.getInt("i_no"));
				detectorVo.setI_device(rs.getString("i_device"));
				detectorVo.setI_img_name(rs.getString("i_img_name"));
				detectorVo.setI_reg_date(rs.getString("i_reg_date"));
				
				return detectorVo;
			}
			
		}, month);
		
		return detectorVos;
	}


	public List<DetectorVo> getDetectedListDaily(String day) {
		System.out.println("[DetectorDao] getDetectedListDaily() called.");
		
		String sql = "SELECT * FROM tbl_imgs WHERE DATE_FORMAT(i_reg_date, '%Y-%m-%d') = ? ORDER BY i_no DESC";
		
		List<DetectorVo> detectorVos = jdbcTemplate.query(sql, new RowMapper<DetectorVo> () {

			@Override
			public DetectorVo mapRow(ResultSet rs, int rowNum) throws SQLException {
				
				DetectorVo detectorVo = new DetectorVo();
				detectorVo.setI_no(rs.getInt("i_no"));
				detectorVo.setI_device(rs.getString("i_device"));
				detectorVo.setI_img_name(rs.getString("i_img_name"));
				detectorVo.setI_reg_date(rs.getString("i_reg_date"));
				
				return detectorVo;
			}
			
		}, day);
		
		return detectorVos;
	}

}
