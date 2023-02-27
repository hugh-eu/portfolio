USE shopdb;
SELECT * FROM memberTBL;
SELECT memberName, memberAddress FROM memberTBL LIMIT 2;  -- 상위 2개
SELECT memberName, memberAddress FROM memberTBL LIMIT 2, 1;  -- 인덱스2부터 1개
SELECT memberName, memberAddress FROM memberTBL WHERE memberID = "Dang";  -- where 조건절
SELECT memberName, memberAddress FROM memberTBL WHERE memberID = "Dang" AND memberName = "sdfe";
SELECT memberName, memberAddress FROM memberTBL WHERE memberID = "Dang" OR memberName = "sdfe";
SELECT memberName, memberAddress FROM memberTBL WHERE NOT memberID = "Dang";
SELECT * FROM memberTBL WHERE memberID = "Jee";

CREATE DATABASE `my testTBL`;  -- 공백포함 안되는데 `` 사용하여 강제로 생성, 하지말자
DROP DATABASE `my testTBL`;  -- 삭제

INSERT INTO membertbl(memberID, memberName, memberAddress) VALUES ("Hong", "홍길동", "대전시 서구 둔산동");
UPDATE membertbl SET memberID = "Gildong" WHERE memberID = "Hong";
DELETE FROM membertbl WHERE memberID = "Gildong";

CREATE TABLE indexTBL (
	first_name VARCHAR(14), 
    last_name VARCHAR(16), 
    hire_date DATE
);
INSERT INTO indexTBL 
	SELECT first_name, last_name, hire_date 
    FROM employees.employees 
    LIMIT 500;
SELECT * FROM indexTBL;
SELECT COUNT(*) FROM indexTBL;  -- rows 개수
SELECT * FROM indexTBL WHERE first_name = "Mary";

CREATE INDEX idx_indexTBL_firstname ON indexTBL(first_name);  -- idx_테이블_컬럼

CREATE VIEW uv_memberTBL AS SELECT memberName, memberAddress FROM membertbl;  -- SELECT 를 VIEW로 만들어놈
SELECT * FROM uv_memberTBL;


-- 구분자를 // 로 만들었다가 ; 로 돌려놈
DELIMITER //
CREATE PROCEDURE myProc()
BEGIN
	SELECT * FROM membertbl WHERE memberName = "당탕이";
	SELECT * FROM producttbl WHERE productName = "냉장고";
END//
DELIMITER ;

CALL myProc();

SELECT * FROM memberTBL;
INSERT INTO membertbl VALUES("Figure", "연아", "경기도 군포시 당정동");
UPDATE membertbl SET membertbl.memberAddress = "서울시 강남구 역삼동" WHERE membertbl.memberName = "연아";
DELETE FROM membertbl WHERE memberName = "연아";

CREATE TABLE deletedMemberTbl (
	memberId CHAR(8),
    memberName CHAR(5),
    memberAddress CHAR(20),
    deletedDate DATETIME,
    userId CHAR(20)
);

DELIMITER //
CREATE TRIGGER trg_deletedMemberTBL 
	AFTER DELETE 
    ON membertbl 
    FOR EACH ROW
BEGIN 
	INSERT INTO deletedMemberTBL 
	VALUES (OLD.memberID, OLD.memberName, OLD.memberAddress, now(), user());
END//
DELIMITER ;

SHOW TRIGGERS;
DROP TRIGGER trg_deletedMemberTBL;
SELECT * FROM deletedmembertbl;

DELETE FROM producttbl;
SELECT * FROM producttbl;
USE sys;
USE shopdb;
