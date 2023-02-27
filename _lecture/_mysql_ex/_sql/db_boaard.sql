CREATE DATABASE db_boaard;
USE db_boaard;

CREATE TABLE tbl_user (
	u_no INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
    u_id VARCHAR(10) NOT NULL,
    u_pw VARCHAR(100) NOT NULL,
    u_email VARCHAR(30),
    u_reg_date DATETIME,
    u_mod_date DATETIME
);

CREATE TABLE tbl_note (
	n_no INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
    u_no INT,
    n_name VARCHAR(50) NOT NULL,
    n_reg_date DATETIME,
    FOREIGN KEY (u_no) REFERENCES tbl_user(u_no) ON DELETE SET NULL
);

CREATE TABLE tbl_conversion (
	c_no INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
    n_no INT,
    c_text VARCHAR(1000) NOT NULL,
    c_reg_date DATETIME,
    c_mod_date DATETIME,
    FOREIGN KEY (n_no) REFERENCES tbl_note(n_no) ON DELETE CASCADE
);

SELECT * FROM tbl_user;
SELECT * FROM tbl_note;
SELECT * FROM tbl_conversion;

DROP TABLE tbl_user;
DROP TABLE tbl_note;
DROP TABLE tbl_conversion;
