-- 대소문자 ctrl+shift+l,u, 쿼리는 대소문자 구분안함, 다른코드와 구분하기 위해 잘 혼용
CREATE DATABASE db_students;  -- db 생성
DROP DATABASE db_students;  -- db 제거
USE db_students;  -- db 선택
CREATE TABLE tbl_students_info(  -- columns 생성
	s_no INT AUTO_INCREMENT PRIMARY KEY,  -- 자동증가, 대표값pk
    s_name VARCHAR(50),  -- 문자열, 길이, varchar는 동적으로 변함
    s_grade INT,
    s_mail VARCHAR(50),
    s_phone VARCHAR(50)
);

SHOW TABLES;  -- table 보기
SHOW DATABASES;  -- db 보기
DROP TABLE tbl_students_info;  -- table 삭제

-- C생성R조회U수정D삭제, crud
INSERT INTO tbl_students_info(
	s_name, 
	s_grade, 
	s_mail, 
	s_phone
)   -- 개행전에 공백있음, 개행시 띄어쓰기등
VALUES(
	"홍길동", 
	1, 
	"gildong@gmail.com", 
	"010-1234-5678"
);  -- 데이터 삽입, insert

INSERT INTO tbl_students_info(
	s_name, 
	s_grade, 
	s_mail, 
	s_phone
)   -- 개행전에 공백있음, 개행시 띄어쓰기등
VALUES(
	"홍길자", 
	2, 
	"gilja@gmail.com", 
	"010-0000-2222"
);

INSERT INTO tbl_students_info(
	s_name, 
	s_grade, 
	s_mail, 
	s_phone
)   -- 개행전에 공백있음, 개행시 띄어쓰기등
VALUES(
	"홍길순", 
	3, 
	"gilsoon@gmail.com", 
	"010-3214-2222"
);

SELECT s_no, s_grade, s_mail FROM tbl_students_info;  -- 데이터 조회
SELECT s_no, s_name, s_grade, s_mail, s_phone FROM tbl_students_info;  -- 데이터 조회
SELECT * FROM tbl_students_info;  -- 데이터 조회

DELETE FROM tbl_students_info;  -- !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 전체 데이터 삭제, 조심해서 사용해야함, 현재 학습을 위해 설정에서 제한 풀어놈
ALTER TABLE tbl_students_info AUTO_INCREMENT=1;  -- auto_increment 초기화
DELETE FROM tbl_students_info WHERE s_no = 9;  -- 데이터 삭제
DELETE FROM tbl_students_info WHERE s_no >= 2;  -- 데이터 삭제

UPDATE tbl_students_info SET s_name = "길동";  -- !!!!!!!!!!!!!!!!변경, 삭제 할 경우 특별한 경우를 제외하곤 꼭 WHERE 사용
UPDATE tbl_students_info SET s_name = "길동" WHERE s_no = 6;

ALTER TABLE tbl_students_info ADD COLUMN s_gender CHAR(1);  -- 컬럼 추가, char는 고정길이
ALTER TABLE tbl_students_info DROP COLUMN s_gender;  -- 컬럼 삭제
ALTER TABLE tbl_students_info MODIFY COLUMN s_gender CHAR(2);  -- 컬럼 길이 변경
ALTER TABLE tbl_students_info CHANGE COLUMN s_gender s_gen CHAR(3);  -- 컬럼명, 타입 변경
ALTER TABLE tbl_students_info RENAME tbl_students_infomation;  -- 테이블명 변경
ALTER TABLE tbl_students_infomation RENAME tbl_students_info;  -- 테이블명 변경

