CREATE DATABASE db_temp_mnt;
USE db_temp_mnt;
CREATE TABLE tbl_temp_mnt (
	t_no INT AUTO_INCREMENT NOT NULL PRIMARY KEY,
    t_temp FLOAT NOT NULL,
    t_reg_date DATETIME
);
DROP TABLE tbl_temp_mnt;
SELECT * FROM tbl_temp_mnt;

SELECT DATE_FORMAT(t_reg_date, '%Y-%m-%d %H'), round(avg(t_temp), 2) FROM tbl_temp_mnt GROUP BY DATE_FORMAT(t_reg_date, '%Y-%m-%d %H') ORDER BY DATE_FORMAT(t_reg_date, '%Y-%m-%d %H') DESC LIMIT 12;
SELECT DATE_FORMAT(t_reg_date, '%Y-%m-%d'), round(avg(t_temp), 2) FROM tbl_temp_mnt GROUP BY DATE_FORMAT(t_reg_date, '%Y-%m-%d') ORDER BY DATE_FORMAT(t_reg_date, '%Y-%m-%d') DESC LIMIT 12;
SELECT DATE_FORMAT(t_reg_date, '%Y-%m'), round(avg(t_temp), 2) FROM tbl_temp_mnt GROUP BY DATE_FORMAT(t_reg_date, '%Y-%m') ORDER BY DATE_FORMAT(t_reg_date, '%Y-%m') DESC LIMIT 12;