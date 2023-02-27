CREATE DATABASE db_tripist;
USE db_tripist;

CREATE TABLE tbl_user (
	u_no INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
    u_id VARCHAR(20) NOT NULL,
    u_pw VARCHAR(50) NOT NULL,
    u_email VARCHAR(30),
    u_reg_date DATETIME,
    u_mod_date DATETIME
);

CREATE TABLE tbl_marker (
	m_no INT PRIMARY KEY AUTO_INCREMENT NOT NULL,
    u_no INT,
    m_lat VARCHAR(30),
    m_lng VARCHAR(30),
    m_location VARCHAR(20),
    m_period VARCHAR(20),
    m_cost VARCHAR(20),
    m_contents VARCHAR(1000),
    m_img_name VARCHAR(1000),
    m_reg_date DATETIME,
    m_mod_date DATETIME,
    FOREIGN KEY (u_no) REFERENCES tbl_user(u_no) ON DELETE SET NULL
);

SELECT * FROM tbl_user;
SELECT * FROM tbl_marker;

DELETE FROM tbl_user WHERE u_no = 1;

DROP TABLE tbl_user;
DROP TABLE tbl_marker;