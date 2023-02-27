DROP DATABASE IF EXISTS sqldb;
CREATE DATABASE sqldb;
USE sqldb;
CREATE TABLE usertbl(
	userID CHAR(8) NOT NULL PRIMARY KEY, 
    name VARCHAR(10) NOT NULL, 
    birthYear INT NOT NULL, 
    addr CHAR(2) NOT NULL, 
    mobile1 CHAR(3), 
    mobile2 CHAR(8), 
    height SMALLINT, 
    mDate DATE
);
CREATE TABLE buytbl(
	num INT AUTO_INCREMENT NOT NULL PRIMARY KEY, 
    userID CHAR(8) NOT NULL, 
    prodName CHAR(6) NOT NULL, 
    groupName CHAR(4), 
    price INT NOT NULL, 
    amount SMALLINT NOT NULL, 
    FOREIGN KEY (userID) REFERENCES usertbl(userID)
);

INSERT INTO usertbl VALUES('LSG', '이승기', 1987, '서울', '011', '1111111', 182, '2008-8-8');
INSERT INTO usertbl VALUES('KBS', '김범수', 1979, '경남', '011', '2222222', 173, '2012-4-4');
INSERT INTO usertbl VALUES('KKH', '김경호', 1971, '전남', '019', '3333333', 177, '2007-7-7');
INSERT INTO usertbl VALUES('JYP', '조용필', 1950, '경기', '011', '4444444', 166, '2009-4-4');
INSERT INTO usertbl VALUES('SSK', '성시경', 1979, '서울', NULL, NULL, 186, '2013-12-12');
INSERT INTO usertbl VALUES('LJB', '임재범', 1963, '서울', '016', '6666666', 182, '2009-9-9');
INSERT INTO usertbl VALUES('YJS', '윤종신', 1969, '경남', NULL, NULL, 170, '2005-5-5');
INSERT INTO usertbl VALUES('EJW', '은지원', 1972, '서울', '011', '8888888', 174, '2014-3-3');
INSERT INTO usertbl VALUES('JKW', '조관우', 1965, '경북', '018', '9999999', 172, '2010-10-10');
INSERT INTO usertbl VALUES('BBK', '바비킴', 1973, '경기', '010', '0000000', 176, '2013-5-5');

INSERT INTO buytbl VALUES(NULL, 'KBS', '운동화', NULL, 30, 2);
INSERT INTO buytbl VALUES(NULL, 'KBS', '노트북','전자', 1000, 1);
INSERT INTO buytbl VALUES(NULL, 'JYP', '모니터', '전자', 200, 1);
INSERT INTO buytbl VALUES(NULL, 'BBK', '모니터', '전자', 200, 5);
INSERT INTO buytbl VALUES(NULL, 'KBS', '청바지', '의류', 50, 3);
INSERT INTO buytbl VALUES(NULL, 'BBK', '메모리', '전자', 80, 10);
INSERT INTO buytbl VALUES(NULL, 'SSK', '책', '서적', 15, 5);
INSERT INTO buytbl VALUES(NULL, 'EJW', '책', '서적', 15, 2);
INSERT INTO buytbl VALUES(NULL, 'EJW', '청바지', '의류', 50, 1);
INSERT INTO buytbl VALUES(NULL, 'BBK', '운동화', NULL, 30, 2);
INSERT INTO buytbl VALUES(NULL, 'EJW', '책', '서적', 15, 1);
INSERT INTO buytbl VALUES(NULL, 'BBK', '운동화', NULL, 30, 2);

USE sqldb;
SELECT * FROM usertbl;
SELECT * FROM usertbl WHERE name = '김경호';
SELECT userID, Name FROM usertbl WHERE birthYear >= 1970 AND height >= 182;
SELECT userID, Name FROM usertbl WHERE birthYear >= 1970 OR height >= 182;
SELECT name, height FROM usertbl WHERE height >= 180 AND height <= 183;
SELECT name, height FROM usertbl WHERE height BETWEEN 180 AND 183;
SELECT name, addr FROM usertbl WHERE addr='경남' OR addr='전남' or addr='경북';
SELECT name, addr FROM usertbl WHERE addr IN ('경남', '전남', '경북');
SELECT name, height FROM usertbl WHERE name LIKE '김%';
SELECT name, height FROM usertbl WHERE name LIKE '_종신';
SELECT name, height FROM usertbl WHERE height > 177;
SELECT name, height FROM usertbl WHERE height > (SELECT height FROM usertbl WHERE name = '김경호');
SELECT name, height FROM usertbl WHERE height >= (SELECT height FROM usertbl WHERE addr = '경남');
SELECT name, height FROM usertbl WHERE height >= ANY (SELECT height FROM usertbl WHERE addr = '경남');
SELECT name, height FROM usertbl WHERE height >= ALL (SELECT height FROM usertbl WHERE addr = '경남');
SELECT name, height FROM usertbl WHERE height = ANY (SELECT height FROM usertbl WHERE addr = '경남');
SELECT name, height FROM usertbl WHERE height IN (SELECT height FROM usertbl WHERE addr = '경남');
SELECT name, mDate FROM usertbl ORDER BY mDate;
SELECT name, mDate FROM usertbl ORDER BY mDate DESC;
SELECT name, height FROM usertbl ORDER BY height DESC, name ASC;
SELECT addr FROM usertbl;
SELECT addr FROM usertbl ORDER BY addr;
SELECT DISTINCT addr FROM usertbl;
USE employees;
SELECT emp_no, hire_date FROM employees ORDER BY emp_no ASC;
SELECT emp_no, hire_date FROM employees ORDER BY emp_no ASC LIMIT 5;
SELECT emp_no, hire_date FROM employees ORDER BY emp_no ASC LIMIT 0, 5;
USE sqldb;
CREATE TABLE buytbl2 (SELECT * FROM buytbl);
SELECT * FROM buytbl;
SELECT * FROM buytbl2;
CREATE TABLE buytbl3 (SELECT userID, prodName FROM buytbl);
SELECT * FROM buytbl3;

SELECT bt.userID id, 
	   SUM(bt.amount) total_amount, 
	   SUM(bt.amount * bt.price) total_price, 
	   ROUND(AVG(bt.amount), 1) avg_buy 
FROM buytbl bt 
GROUP BY userID 
ORDER BY userID;
-- 접근연산자, 컬럼병 닉네임 지정 as, 아이디별로 그룹으로 묶어 합계 계산

SELECT 
	userID id, 
	AVG(amount) avg_amount, 
	min(amount) min, 
	MAX(amount) max, 
	COUNT(amount) buy_cnt 
FROM buytbl 
GROUP BY userID 
ORDER BY userID;

SELECT * FROM usertbl;
SELECT userID, name, height FROM usertbl WHERE height = (SELECT MAX(height) FROM usertbl) OR height = (SELECT MIN(height) FROM usertbl);
SELECT COUNT(mobile1) FROM usertbl;

SELECT 
	userID, 
	SUM(price*amount) sum
FROM 
	buytbl 
GROUP BY 
	userID 
HAVING 
	sum > 1000
ORDER BY
	sum DESC;

SELECT * FROM buytbl;
SELECT num, groupName, SUM(price * amount)
FROM buytbl
GROUP BY groupName, num 
WITH ROLLUP;

CREATE TABLE testTbl1 (
	id INT,
    userName char(3), 
    age INT
);
SELECT * FROM testTbl1;
INSERT INTO testTbl1 (
	id,
    userName,
    age
) 
VALUES (
	1,
    "홍길동",
    19
);
INSERT INTO testTbl1 VALUES (2, '홍길자', 20);  -- 컬럼 순서대로 들어갈 경우 컬럼명 생략 가능, 하나라도 비면 안됨

CREATE TABLE testTbl2 (id INT AUTO_INCREMENT PRIMARY KEY, userName CHAR(3), age INT);
SELECT * FROM testTbl2;
INSERT INTO testTbl2 VALUES (null, '지민', 25);
INSERT INTO testTbl2 VALUES (null, '유나', 22);
INSERT INTO testTbl2 VALUES (null, '유경', 21);
ALTER TABLE testTbl2 AUTO_INCREMENT=4;
INSERT INTO testTbl2 (userName, age) VALUES ('홍길동', 30);
DROP TABLE testTbl2;
ALTER TABLE testTbl2 AUTO_INCREMENT=1000;
SET @@auto_increment_increment=7;
SET @@auto_increment_offset=11;

CREATE TABLE testTbl4(id INT, Fname VARCHAR(50), Lname VARCHAR(50));
INSERT INTO testTbl4 SELECT emp_no, first_name, last_name FROM employees.employees;

UPDATE testTbl4 SET Lname = '없음' WHERE Fname = 'Kyoichi';
SELECT * FROM testTbl4 WHERE Fname = 'Kyoichi';

SELECT * FROM buytbl;
UPDATE buytbl SET price = price / 1.5;
UPDATE buytbl SET price = price / 1.5 WHERE price < 1000;

DELETE FROM testTbl4 WHERE Fname = 'Aamer';
SELECT * FROM testTbl4 WHERE Fname = 'Aamer';

SELECT * FROM testTbl4 WHERE Fname = 'Aamod';
SELECT COUNT(*) FROM testTbl4 WHERE Fname = 'Aamod';
DELETE FROM testTbl4 WHERE Fname = 'Aamod' LIMIT 100;

CREATE TABLE bigTbl1 (SELECT * FROM employees.employees);
CREATE TABLE bigTbl2 (SELECT * FROM employees.employees);
CREATE TABLE bigTbl3 (SELECT * FROM employees.employees);

DELETE FROM bigTbl1;
DROP TABLE bigTbl2;
TRUNCATE TABLE bigTbl3;  -- drop 후 create, delete는 오래걸리기떄문에 테이블 형태를 남기며 데이터를 지울때는 truncate 를 사용하는게 좋음
SELECT * FROM bigTbl1;

ALTER TABLE bigTbl1 MODIFY hire_date VARCHAR(10);
ALTER TABLE bigTbl1 CHANGE hire_date hiredate VARCHAR(3);
ALTER TABLE bigTbl1 ADD COLUMN test_column VARCHAR(1);
ALTER TABLE bigTbl1 DROP COLUMN test_column;
ALTER TABLE bigTbl1 MODIFY hiredate DATETIME FIRST;
ALTER TABLE bigTbl1 MODIFY hiredate DATETIME AFTER last_name;

CREATE TABLE user1(id INT PRIMARY KEY, name VARCHAR(20));
SELECT * FROM user1;
INSERT INTO user1 VALUES (1, '홍길동');
INSERT IGNORE INTO user1 VALUES (1, '홍길자');  -- 오류 생길경우 스킵, 안씀 로그에러로 확인하고 수정하는것이 좋음
INSERT IGNORE INTO user1 VALUES (2, '홍길');

INSERT INTO user1 VALUES(2, '인서트') ON DUPLICATE KEY UPDATE name='업데이';

-- inner join
SELECT * FROM buytbl;
SELECT * FROM usertbl;
SELECT * FROM buytbl INNER JOIN usertbl ON buytbl.userID = usertbl.userID;
SELECT * FROM buytbl AS b INNER JOIN usertbl AS u ON b.userID = u.userID WHERE b.userID = 'KBS' ORDER BY b.num DESC;
SELECT b.num, b.userID, u.name, b.prodName, b.groupName, b.price, b.amount, CONCAT(u.mobile1, u.mobile2) AS phone FROM buytbl AS b INNER JOIN usertbl AS u ON b.userID = u.userID WHERE b.userID = 'KBS' ORDER BY b.num;
SELECT DISTINCT u.userID, u.name, u.addr FROM usertbl AS u INNER JOIN buytbl AS b ON u.userID = b.userID ORDER BY u.userID;
SELECT u.userID, u.name, u.addr FROM usertbl u WHERE EXISTS (SELECT * FROM buytbl b WHERE u.userID = b.userID);

CREATE TABLE stdtbl(
	stdName VARCHAR(10) NOT NULL PRIMARY KEY, 
    addr CHAR(4) NOT NULL
);
CREATE TABLE clubtbl(
	clubName VARCHAR(10) NOT NULL PRIMARY KEY,
    roomNo CHAR(4) NOT NULL
);
CREATE TABLE stdclubtbl(
	num INT AUTO_INCREMENT NOT NULL PRIMARY KEY,
    stdName VARCHAR(10) NOT NULL,
    clubName VARCHAR(10) NOT NULL,
    FOREIGN KEY(stdName) REFERENCES stdtbl(stdName),
    FOREIGN KEY(clubName) REFERENCES clubtbl(clubName)
);
INSERT INTO stdtbl VALUES ('김범수', '경남'), ('성시경', '서울'), ('조용필', '경기'), ('은지원', '경북'), ('바비킴', '서울');
INSERT INTO clubtbl VALUES ('수영', '101호'), ('바둑', '102호'), ('축구', '103호'), ('봉사', '104호');
INSERT INTO stdclubtbl VALUES (null, '김범수', '바둑'), (null, '김범수', '축구'), (null, '조용필', '축구'), (null, '은지원', '축구'), (null, '은지원', '봉사'), (null, '바비킴', '봉사');

SELECT * FROM stdtbl;
SELECT * FROM clubtbl;
SELECT * FROM stdclubtbl;

SELECT s.stdName, s.addr, c.clubName, c.roomNo 
FROM stdtbl s 
INNER JOIN stdclubtbl sc 
ON s.stdName = sc.stdName 
INNER JOIN clubtbl c 
ON c.clubName = sc.clubName 
ORDER BY s.stdName;

-- outer join
SELECT * FROM usertbl ORDER BY usertbl.userID;
SELECT * FROM buytbl ORDER BY userID;
SELECT * FROM usertbl JOIN buytbl ON usertbl.userID = buytbl.userID ORDER BY usertbl.userID;
SELECT * FROM usertbl LEFT OUTER JOIN buytbl ON usertbl.userID = buytbl.userID ORDER BY usertbl.userID;
SELECT * FROM usertbl RIGHT JOIN buytbl ON usertbl.userID = buytbl.userID ORDER BY usertbl.userID;

SELECT usertbl.name, COUNT(*) FROM usertbl LEFT JOIN buytbl ON usertbl.userID = buytbl.userID WHERE buytbl.amount is NOT NULL GROUP BY usertbl.userID ORDER BY usertbl.userID;
SELECT sc.num, s.stdName, s.addr, c.clubName, c.roomNo 
FROM stdtbl s 
LEFT JOIN stdclubtbl sc 
ON s.stdName = sc.stdName 
LEFT JOIN clubtbl c 
ON sc.clubName = c.clubName 
ORDER BY sc.num;
SELECT sc.num, s.stdName, s.addr, c.clubName, c.roomNo 
FROM stdtbl s 
LEFT JOIN stdclubtbl sc 
ON s.stdName = sc.stdName 
RIGHT JOIN clubtbl c 
ON sc.clubName = c.clubName 
ORDER BY sc.num;

SELECT sc.num, s.stdName, s.addr, c.clubName, c.roomNo 
FROM stdtbl s 
LEFT JOIN stdclubtbl sc 
ON s.stdName = sc.stdName 
LEFT JOIN clubtbl c 
ON sc.clubName = c.clubName 
UNION
SELECT sc.num, s.stdName, s.addr, c.clubName, c.roomNo 
FROM stdtbl s 
LEFT JOIN stdclubtbl sc 
ON s.stdName = sc.stdName 
RIGHT JOIN clubtbl c 
ON sc.clubName = c.clubName;

-- cross join
SELECT * FROM buytbl;
SELECT * FROM usertbl;
SELECT * FROM buytbl
CROSS JOIN usertbl;

SELECT * FROM employees.titles;
SELECT COUNT(*) FROM employees.titles;

SELECT COUNT(*) FROM employees.employees ;

USE sqldb;
SELECT * FROM buytbl;
SELECT * FROM usertbl;
SELECT * FROM buytbl CROSS JOIN usertbl;

CREATE TABLE empTbl (emp CHAR(3), manager CHAR(3), empTel VARCHAR(8));

DROP TABLE empTbl;

INSERT INTO empTbl VALUES ('나사장', NULL, '0000');
INSERT INTO empTbl VALUES ('김재무', '나사장', '2222');
INSERT INTO empTbl VALUES ('김부장', '김재무', '2222-1');
INSERT INTO empTbl VALUES ('이부장', '김재무', '2222-2');
INSERT INTO empTbl VALUES ('우대리', '이부장', '2222-2-1');
INSERT INTO empTbl VALUES ('지사원', '이부장', '2222-2-2');
INSERT INTO empTbl VALUES ('이영업', '나사장', '1111');
INSERT INTO empTbl VALUES ('한과장', '이영업', '1111-1');
INSERT INTO empTbl VALUES ('최정보', '나사장', '3333');
INSERT INTO empTbl VALUES ('윤차장', '최정보', '3333-1');
INSERT INTO empTbl VALUES ('이주임', '윤차장', '3333-1-1');

SELECT A.emp AS '부하직원', B.emp AS '직속상관', B.empTel AS '직속상관연락처' FROM empTbl A INNER JOIN empTbl B ON A.manager = B.emp WHERE A.emp = '우대리';

SELECT * FROM stdtbl;
SELECT * FROM clubtbl;
SELECT stdName, addr FROM stdtbl
UNION
SELECT clubName, roomNo FROM clubtbl;

SELECT name, CONCAT(mobile1, mobile2) AS '전화번호' FROM usertbl WHERE name NOT IN (SELECT name FROM usertbl WHERE mobile1 IS NULL);

DROP PROCEDURE IF EXISTS ifProc;
DELIMITER $$
CREATE PROCEDURE ifProc()
BEGIN
	DECLARE var1 INT;
    SET var1 = 101;
	IF var1 = 100 THEN
		SELECT '100입니다';
	ELSE
		SELECT '100이 아닙니다.';
	END IF;
END $$
DELIMITER ;
CALL ifProc();

DROP PROCEDURE IF EXISTS ifProc2;
USE employees;
DELIMITER $$
CREATE PROCEDURE ifProc2()
BEGIN
	DECLARE hireDATE DATE;
    DECLARE curDATE DATE;
    DECLARE days INT;
    SELECT hire_date INTO hireDATE
		FROM employees.employees
        WHERE emp_no = 250000;
	SET curDATE = current_date();
    SET days = datediff(curDATE, hireDATE);
    
    IF (days/365) >= 5 THEN
		SELECT concat('입사한지 ', days, '일이 지났습니다. 어이구야');
	ELSE
		SELECT '입사한지' + days + '일밖에 안되었네요. 도망치세요.';
	END IF;
END $$
DELIMITER ;
CALL ifProc2;

DELIMITER $$
CREATE PROCEDURE ifProc3()
BEGIN
	DECLARE point INT;
    DECLARE credit CHAR(1);
    SET point = 77;
    
    IF point >= 90 THEN
		SET credit = "A";
	ELSEIF point > 80 THEN
		set credit = "B";
    ELSEIF point > 70 THEN
		SET credit = "C";
	ELSEIF point > 60 THEN
		SET credit = "D";
	ELSE
		SET credit = "F";
	END IF;
    SELECT concat("취득점수==>", point), concat("학점==>", credit);
END $$
DELIMITER ;
CALL ifProc3();



DELIMITER $$
CREATE PROCEDURE caseProc()
BEGIN
	DECLARE point INT;
    DECLARE credit CHAR(1);
    SET point = 77;
    CASE
		WHEN point >= 90 THEN
			SET credit = "A";
		WHEN point >= 80 THEN
			SET credit = "B";
		WHEN point >= 70 THEN
			SET credit = "C";
		WHEN point >= 60 THEN
			SET credit = "D";
		ELSE
			SET credit = "F";
	END CASE;
    SELECT point 점수, credit 학점;
END $$
DELIMITER ;
CALL caseProc();

SELECT * FROM usertbl;
SELECT * FROM buytbl;

SELECT u.userID, u.name, SUM(price*amount) '총구매액',
	CASE
		WHEN (SUM(price*amount) >= 1500) THEN '최우수고객'
		WHEN (SUM(price*amount) >= 1000) THEN '우수고객'
		WHEN (SUM(price*amount) >= 1) THEN '일반고객'
        ELSE '유령고객'
	END '고객등급'
FROM buytbl b
	RIGHT JOIN usertbl u
    ON b.userID = u.userID
GROUP BY u.userID
ORDER BY SUM(price*amount) DESC;

DELIMITER $$
CREATE PROCEDURE whileProc2()
BEGIN
	DECLARE i INT;
    DECLARE sum INT;
    SET i = 1;
    SET sum = 0;
    myWhile: WHILE (i <= 1000) DO
		IF (i % 3 = 0) OR (i % 8 = 0) THEN
			SET sum = sum + i;
		END IF;
		SET i = i + 1;
	END WHILE;
    SELECT sum;
END $$
DELIMITER ;
CALL whileProc2();

DELIMITER $$
CREATE PROCEDURE errorProc()
BEGIN
	DECLARE CONTINUE HANDLER FOR 1146 SELECT '테이블 없음' AS '메시지';
    SELECT * FROM noTable;
END $$
DELIMITER ;
CALL errorProc();

DELIMITER $$
CREATE PROCEDURE errorProc2()
BEGIN
	DECLARE CONTINUE HANDLER FOR SQLEXCEPTION
    BEGIN
		SHOW ERRORS;
        SELECT '오류 발생. 롤백' AS '메시지';
        ROLLBACK;
	END;
    INSERT INTO usertbl VALUES ('LSG', '이상구', 1988, '서울', NULL, NULL, 170, current_date());
END $$
DELIMITER ;
CALL errorProc2();
        
