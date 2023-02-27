CREATE DATABASE db_air;
USE db_air;
CREATE TABLE tbl_air_reservation(
	r_no INT PRIMARY KEY NOT NULL AUTO_INCREMENT, 
    r_name VARCHAR(10) NOT NULL, 
    r_phone VARCHAR(15) NOT NULL, 
    r_start_location VARCHAR(5) NOT NULL, 
    r_end_location VARCHAR(5) NOT NULL, 
    r_start_time VARCHAR(25) NOT NULL, 
    r_end_time VARCHAR(25) NOT NULL, 
    r_reg_date DATETIME
);

SELECT * FROM tbl_air_reservation;
SELECT * FROM deletedTbl;
DROP TABLE tbl_air_reservation;

DELETE FROM tbl_air_reservation WHERE r_no = 1;

SELECT * FROM tbl_air_reservation WHERE r_no = 1;

ALTER TABLE tbl_air_reservation ADD r_mod_date DATETIME;

UPDATE tbl_air_reservation SET r_mod_date = NOW() WHERE r_no = 1;

CREATE TABLE deletedTbl (
	r_no INT, 
    r_name VARCHAR(10), 
    r_phone VARCHAR(15), 
    r_start_location VARCHAR(5), 
    r_end_location VARCHAR(5), 
    r_start_time VARCHAR(25), 
    r_end_time VARCHAR(25), 
    r_del_date DATETIME, 
    r_del_user VARCHAR(20)
);
DROP TABLE deletedTbl;

DELIMITER //
CREATE TRIGGER trg_deletedTbl 
	AFTER DELETE 
    ON tbl_air_reservation 
    FOR EACH ROW
BEGIN 
	INSERT INTO deletedTbl 
	VALUES (OLD.r_no, OLD.r_name, OLD.r_phone, OLD.r_start_location, OLD.r_end_location, OLD.r_start_time, OLD.r_end_time, now(), user());
END//
DELIMITER ;

SHOW TRIGGERS;
