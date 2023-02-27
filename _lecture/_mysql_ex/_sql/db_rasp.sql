CREATE DATABASE db_smart_plug;

USE db_smart_plug;

CREATE TABLE tbl_smart_plug (
	p_no INT NOT NULL AUTO_INCREMENT PRIMARY KEY, 
	p_id VARCHAR(20) NOT NULL,   -- 공장 출고시 정해지는 아이디
	p_name VARCHAR(20) NOT NULL,  -- 사용자 지정 이름
    p_power_status CHAR(1) NOT NULL,
    p_power_on_date DATETIME,
    p_power_off_date DATETIME,
    p_reg_date DATETIME,
    p_mod_date DATETIME
);

SELECT * FROM tbl_smart_plug;

CREATE TABLE tbl_led(
	l_no int PRIMARY KEY AUTO_INCREMENT NOT NULL,
    l_status CHAR(1),
    l_reg_date DATETIME,
    l_mod_date DATETIME
);

SELECT * FROM tbl_led;

INSERT INTO tbl_led(l_status, l_reg_date, l_mod_date) VALUES ('0', NOW(), NOW());

SELECT l_status FROM tbl_led ORDER BY l_mod_date DESC LIMIT 1;

