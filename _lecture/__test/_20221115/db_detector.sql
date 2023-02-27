CREATE DATABASE db_detector;
USE db_detector;


CREATE TABLE tbl_users (
	u_no INT AUTO_INCREMENT NOT NULL PRIMARY KEY,
    u_id VARCHAR(20) NOT NULL,
    u_pw VARCHAR(20) NOT NULL,
    u_auth CHAR(1) NOT NULL,
    u_reg_date DATETIME,
    u_mod_date DATETIME
);

INSERT INTO tbl_users (u_id, u_pw, u_auth, u_reg_date, u_mod_date) VALUES ("admin", "admin", "O", NOW(), NOW());

SELECT * FROM tbl_users;

CREATE TABLE tbl_imgs (
	i_no INT AUTO_INCREMENT NOT NULL PRIMARY KEY,
    i_device VARCHAR(20),
    i_img_name VARCHAR(100) NOT NULL,
    i_reg_date DATETIME
);

INSERT INTO tbl_imgs (i_device, i_img_name, i_reg_date) VALUES("ajax_test", "20221115130651-00.jpg", NOW());

SELECT * FROM tbl_imgs;