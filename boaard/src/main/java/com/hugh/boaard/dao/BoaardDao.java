package com.hugh.boaard.dao;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.RowMapper;
import org.springframework.stereotype.Component;

import com.hugh.boaard.vo.BoaardVo;

@Component
public class BoaardDao {

	@Autowired
	JdbcTemplate jdbcTemplate;
	
	public int confirmSignUp(BoaardVo boaardVo) {
		System.out.println("[Dao] confirmSignUp() called.");
		
		String sql = "SELECT * FROM tbl_user WHERE u_id = ?";
		
		List<BoaardVo> boaardVos = jdbcTemplate.query(sql, new RowMapper<BoaardVo>() {
			
			@Override
			public BoaardVo mapRow(ResultSet rs, int rowNum) throws SQLException {
				BoaardVo boaardVo = new BoaardVo();
				
				boaardVo.setU_no(rs.getInt("u_no"));
				boaardVo.setU_id(rs.getString("u_id"));
				boaardVo.setU_pw(rs.getString("u_pw"));
				boaardVo.setU_email(rs.getString("u_email"));
				boaardVo.setU_reg_date(rs.getString("u_reg_date"));
				boaardVo.setU_mod_date(rs.getString("u_mod_date"));
				
				return boaardVo;
				
			}
			
		}, boaardVo.getU_id());
		
		if (boaardVos.size() == 0) {
			
			sql = "INSERT INTO tbl_user (u_id, u_pw, u_email, u_reg_date, u_mod_date) VALUES (?, ?, ?, NOW(), NOW())";
			
			return jdbcTemplate.update(sql, boaardVo.getU_id(), boaardVo.getU_pw(), boaardVo.getU_email());
			
		} else {
			
			return -1;
			
		}
		
	}

	public List<BoaardVo> confirmSignIn(BoaardVo boaardVo) {
		System.out.println("[Dao] confirmSignIn() called.");
		
		String sql = "SELECT * FROM tbl_user WHERE u_id = ?";
		
		return jdbcTemplate.query(sql, new RowMapper<BoaardVo>() {

			@Override
			public BoaardVo mapRow(ResultSet rs, int rowNum) throws SQLException {
				BoaardVo boaardVo = new BoaardVo();
				
				boaardVo.setU_no(rs.getInt("u_no"));
				boaardVo.setU_id(rs.getString("u_id"));
				boaardVo.setU_pw(rs.getString("u_pw"));
				boaardVo.setU_email(rs.getString("u_email"));
				boaardVo.setU_reg_date(rs.getString("u_reg_date"));
				boaardVo.setU_mod_date(rs.getString("u_mod_date"));
				
				return boaardVo;
				
			}
			
		}, boaardVo.getU_id());
		
	}
	
	public List<BoaardVo> insertNoteInfo(int u_no, String name_note) {
		System.out.println("[Dao] insertNoteInfo() called.");
		
		String sql = "INSERT INTO tbl_note (u_no, n_name, n_reg_date) VALUES (?, ?, NOW())";
		
		int result = jdbcTemplate.update(sql, u_no, name_note);
		
		if (result > 0) {
			
			sql = "SELECT * FROM tbl_note WHERE u_no = ? ORDER BY n_no DESC";
			
			return jdbcTemplate.query(sql, new RowMapper<BoaardVo>() {
				
				@Override
				public BoaardVo mapRow(ResultSet rs, int rowNum) throws SQLException {
					BoaardVo boaardVo = new BoaardVo();
					
					boaardVo.setN_no(rs.getInt("n_no"));
					boaardVo.setU_no(rs.getInt("u_no"));
					boaardVo.setN_name(rs.getString("n_name"));
					boaardVo.setN_reg_date(rs.getString("n_reg_date"));
					
					return boaardVo;
					
				}
				
			}, u_no);
			
		} else {
			
			return null;
			
		}
	}
	
	public int insertNoteText(BoaardVo boaardVo) {
		System.out.println("[Dao] insertNoteText() called.");
		
		String sql = "INSERT INTO tbl_conversion (n_no, c_text, c_reg_date, c_mod_date) VALUES (?, ?, NOW(), NOW())";
		
		return jdbcTemplate.update(sql, boaardVo.getN_no(), boaardVo.getC_text());
		
	}

	public List<BoaardVo> getNotes(int u_no) {
		System.out.println("[Dao] getNotes() called.");
		
		String sql = "SELECT * FROM tbl_note WHERE u_no = ? ORDER BY n_no ASC";
		
		return jdbcTemplate.query(sql, new RowMapper<BoaardVo>() {
			
			@Override
			public BoaardVo mapRow(ResultSet rs, int rowNum) throws SQLException {
				BoaardVo boaardVo = new BoaardVo();
				
				boaardVo.setN_no(rs.getInt("n_no"));
				boaardVo.setU_no(rs.getInt("u_no"));
				boaardVo.setN_name(rs.getString("n_name"));
				boaardVo.setN_reg_date(rs.getString("n_reg_date"));
				
				return boaardVo;
				
			}
			
		}, u_no);
		
	}

	public List<BoaardVo> getText(int n_no) {
		System.out.println("[Dao] getText() called.");
		
		String sql = "SELECT * FROM tbl_conversion WHERE n_no = ? ORDER BY c_no DESC";
		
		return jdbcTemplate.query(sql, new RowMapper<BoaardVo>() {

			@Override
			public BoaardVo mapRow(ResultSet rs, int rowNum) throws SQLException {
				BoaardVo boaardVo = new BoaardVo();
				
				boaardVo.setC_no(rs.getInt("c_no"));
				boaardVo.setN_no(rs.getInt("n_no"));
				boaardVo.setC_text(rs.getString("c_text"));
				boaardVo.setC_reg_date(rs.getString("c_reg_date"));
				boaardVo.setC_mod_date(rs.getString("c_mod_date"));
				
				return boaardVo;
				
			}
			
		}, n_no);
		
	}

	public int modifyText(int c_no, String c_text) {
		System.out.println("[Dao] modifyText() called.");
		
		String sql = "UPDATE tbl_conversion SET c_text = ?, c_mod_date = NOW() WHERE c_no = ?";
		
		return jdbcTemplate.update(sql, c_text, c_no);
		
	}

	public int deleteNote(int n_no) {
		System.out.println("[Dao] deleteNote() called.");
		
		String sql = "DELETE FROM tbl_note WHERE n_no = ?";
		
		return jdbcTemplate.update(sql, n_no);

	}

	public List<BoaardVo> getMyPage(int u_no) {
		System.out.println("[Dao] getMyPage() called.");
		
		String sql = "SELECT * FROM tbl_user WHERE u_no = ?";
		
		return jdbcTemplate.query(sql, new RowMapper<BoaardVo>() {

			@Override
			public BoaardVo mapRow(ResultSet rs, int rowNum) throws SQLException {
				BoaardVo boaardVo =  new BoaardVo();
				
				boaardVo.setU_no(rs.getInt("u_no"));
				boaardVo.setU_id(rs.getString("u_id"));
				boaardVo.setU_pw(rs.getString("u_pw"));
				boaardVo.setU_email(rs.getString("u_email"));
				boaardVo.setU_reg_date(rs.getString("u_reg_date"));
				boaardVo.setU_mod_date(rs.getString("u_mod_date"));
				
				return boaardVo;
				
			}
			
		}, u_no);
		
	}

	public List<BoaardVo> confirmPwForModify(BoaardVo boaardVo) {
		System.out.println("[Dao] confirmPwForModify() called.");
		
		String sql = "SELECT * FROM tbl_user WHERE u_no = ?";
		
		return jdbcTemplate.query(sql, new RowMapper<BoaardVo>() {

			@Override
			public BoaardVo mapRow(ResultSet rs, int rowNum) throws SQLException {
				BoaardVo boaardVo =  new BoaardVo();
				
				boaardVo.setU_no(rs.getInt("u_no"));
				boaardVo.setU_id(rs.getString("u_id"));
				boaardVo.setU_pw(rs.getString("u_pw"));
				boaardVo.setU_email(rs.getString("u_email"));
				boaardVo.setU_reg_date(rs.getString("u_reg_date"));
				boaardVo.setU_mod_date(rs.getString("u_mod_date"));
				
				return boaardVo;
				
			}
			
		}, boaardVo.getU_no());
	}

	public int modifyMyPage(BoaardVo boaardVo) {
		System.out.println("[Dao] modifyMyPage() called.");
		
		if (!boaardVo.getNew_pw().equals("")) {
			String sql = "UPDATE tbl_user SET u_pw = ?, u_email = ?, u_mod_date = NOW() WHERE u_no = ?";
			
			return jdbcTemplate.update(sql, boaardVo.getNew_pw(), boaardVo.getU_email(), boaardVo.getU_no());
			
		} else {
			String sql = "UPDATE tbl_user SET u_email = ?, u_mod_date = NOW() WHERE u_no = ?";
			
			return jdbcTemplate.update(sql, boaardVo.getU_email(), boaardVo.getU_no());
			
		}
	}

	public List<BoaardVo> confirmPwForWithdrawal(int u_no) {
		System.out.println("[Dao] confirmPwForWithdrawal() called.");
		
		String sql = "SELECT * FROM tbl_user WHERE u_no = ?";
		
		return jdbcTemplate.query(sql, new RowMapper<BoaardVo>() {

			@Override
			public BoaardVo mapRow(ResultSet rs, int rowNum) throws SQLException {
				BoaardVo boaardVo =  new BoaardVo();
				
				boaardVo.setU_no(rs.getInt("u_no"));
				boaardVo.setU_id(rs.getString("u_id"));
				boaardVo.setU_pw(rs.getString("u_pw"));
				boaardVo.setU_email(rs.getString("u_email"));
				boaardVo.setU_reg_date(rs.getString("u_reg_date"));
				boaardVo.setU_mod_date(rs.getString("u_mod_date"));
				
				return boaardVo;
				
			}
			
		}, u_no);

	}

	public int withdrawal(int u_no) {
		System.out.println("[Dao] withdrawal() called.");
		
		String sql = "DELETE FROM tbl_user WHERE u_no = ?";
		
		return jdbcTemplate.update(sql, u_no);
		
	}

}
