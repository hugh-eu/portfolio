CREATE DATABASE db_injection;
SHOW DATABASES;
USE db_injection;

CREATE TABLE tbl_injection (
	i_no INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
	sn_no CHAR(14) NOT NULL, 
	il_no INT NOT NULL, 
	i_vaccine_type CHAR(2) NOT NULL, 
	i_vaccine_confirm CHAR(1) NOT NULL, 
	i_reg_date DATETIME, 
	i_mod_date DATETIME
);

SELECT * FROM tbl_injection;

UPDATE tbl_injection SET il_no = 2, i_vaccine_type = "V2", i_vaccine_confirm = "X" WHERE i_no = 1;

CREATE TABLE tbl_social_number (
	sn_no CHAR(14) PRIMARY KEY NOT NULL, 
	sn_name CHAR(5) NOT NULL, 
	sn_addr	CHAR(50) NOT NULL, 
	sn_phone CHAR(15) NOT NULL, 
	sn_reg_date	DATETIME, 
	sn_mod_date	DATETIME
);

INSERT INTO tbl_social_number VALUES ('710615-1018524', '홍길동', '서울시 광진구 구의동 13-10', '010-1234-5678', now(), now());
INSERT INTO tbl_social_number VALUES ('720920-1056241', '박찬호', '서울시 강남구 대치동 70-02', '010-9012-3456', now(), now());
INSERT INTO tbl_social_number VALUES ('651212-2085214', '박세리', '서울시 노원구 공릉동 61-07', '010-7890-1234', now(), now());
INSERT INTO tbl_social_number VALUES ('990212-2587462', '박지성', '서울시 도봉구 우의동 15-21', '010-5678-9012', now(), now());
INSERT INTO tbl_social_number VALUES ('910201-1596214', '윤석민', '서울시 중구 무악동 220-1', '010-3456-7890', now(), now());

SELECT * FROM tbl_social_number;

CREATE TABLE tbl_injection_location (
	il_no INT PRIMARY KEY AUTO_INCREMENT NOT NULL, 
	il_name	CHAR(10) NOT NULL, 
	il_addr	CHAR(50) NOT NULL, 
	il_phone CHAR(15) NOT NULL, 
	il_reg_date	DATETIME, 
	il_mod_date	DATETIME
);

SELECT * FROM tbl_injection_location;

SELECT * FROM tbl_injection ij INNER JOIN tbl_social_number sn ON ij.sn_no = sn.sn_no INNER JOIN tbl_injection_location il ON ij.il_no = il.il_no;

SELECT * FROM tbl_injection ij INNER JOIN tbl_social_number sn ON ij.sn_no = sn.sn_no INNER JOIN tbl_injection_location il ON ij.il_no = il.il_no WHERE ij.sn_no LIKE "720920%" AND sn.sn_name = "박찬호" ORDER BY i_no DESC;