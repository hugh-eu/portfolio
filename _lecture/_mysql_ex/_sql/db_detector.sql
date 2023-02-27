CREATE DATABASE db_detector;

USE db_detector;

CREATE TABLE tbl_imgs (
	i_no INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
    i_img_name VARCHAR(100),
    i_reg_date DATETIME
);
DROP TABLE tbl_imgs;
SELECT * FROM tbl_imgs;
SELECT * FROM tbl_imgs ORDER BY i_no DESC;
SELECT i_no, i_img_name, DATE_FORMAT(i_reg_date, '%Y-%m-%d %H:%i:%S') AS i_reg_date FROM tbl_imgs WHERE DATE_FORMAT(i_reg_date, '%Y-%m') = "2022-11" ORDER BY i_no DESC;
INSERT INTO tbl_imgs (i_img_name, i_reg_date) VALUES ('20221103134357-02.jpg', NOW());
DELETE FROM tbl_imgs;




CREATE TABLE tbl_users (
	u_no INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
    u_id VARCHAR(20) NOT NULL,
    u_pw VARCHAR(20) NOT NULL,
    u_auth CHAR(1) NOT NULL,
    u_reg_date DATETIME,
    u_mod_date DATETIME
);
DROP TABLE tbl_users;
INSERT INTO tbl_users (u_id, u_pw, u_auth, u_reg_date, u_mod_date) VALUES ("admin", "admin", "O", NOW(), NOW());
SELECT * FROM tbl_users;
UPDATE tbl_users SET u_login = "0" WHERE u_no = 1;

CREATE TABLE tbl_login_log (
	l_no INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
    u_no INT NOT NULL,
    l_login_date DATETIME,
    l_logout_date DATETIME,
    FOREIGN KEY (u_no) REFERENCES tbl_users (u_no)
);
DROP TABLE tbl_login_log;
SELECT * FROM tbl_login_log;