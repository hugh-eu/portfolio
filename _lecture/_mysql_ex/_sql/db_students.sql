CREATE DATABASE db_students;
USE db_students;

CREATE TABLE tbl_students(
	s_no INT NOT NULL PRIMARY KEY AUTO_INCREMENT, 
	s_name CHAR(10) NOT NULL, 
    s_age INT NOT NULL, 
    s_grade INT NOT NULL, 
    s_major CHAR(10) NOT NULL
);

DROP TABLE tbl_students;

SHOW TABLES;

SELECT * FROM tbl_students;

SELECT * FROM tbl_students WHERE s_no = 1 AND s_name = "길동";

INSERT INTO tbl_students(s_name, s_age, s_grade, s_major) VALUES ("홍길동", 10, 1, "컴공");

DELETE FROM tbl_students WHERE s_no = 10;

UPDATE tbl_students SET s_name = "김대감", s_age = 10, s_grade = 1, s_major = "디자인" WHERE s_no = 12;