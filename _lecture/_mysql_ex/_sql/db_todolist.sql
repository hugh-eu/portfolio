CREATE DATABASE db_todos;

USE db_todos;

CREATE TABLE tbl_members(
	m_no INT PRIMARY KEY AUTO_INCREMENT NOT NULL, 
    m_id VARCHAR(20) NOT NULL, 
    m_pw VARCHAR(20) NOT NULL
);

CREATE TABLE tbl_todos(
	t_no INT PRIMARY KEY AUTO_INCREMENT NOT NULL, 
    t_txt VARCHAR(200) NOT NULL, 
    t_clear CHAR(1) NOT NULL, 
    t_clear_date DATETIME, 
    m_no INT NOT NULL, 
    FOREIGN KEY (m_no) REFERENCES tbl_members (m_no)
);

CREATE TABLE complete_todos(
	m_no VARCHAR(20),
    t_txt VARCHAR(200),
    t_clear_date DATETIME
);

DELIMITER //
CREATE TRIGGER trg_complete_todos 
	AFTER DELETE 
    ON tbl_todos
    FOR EACH ROW
BEGIN 
	INSERT INTO complete_todos 
	VALUES (OLD.m_no, OLD.t_txt, OLD.t_clear_date);
END//
DELIMITER ;

DROP TRIGGER trg_complete_todos;

SELECT * FROM tbl_members;
SELECT * FROM tbl_todos;
SELECT * FROM complete_todos;

DROP TABLE tbl_todos;
DROP TABLE tbl_members;
DROP TABLE complete_todos;

DELETE FROM tbl_todos;
DELETE FROM tbl_members;
DELETE FROM complete_todos;