import pymysql

DB_HOST = '192.168.0.101'
DB_USER = 'hugh'
DB_PASSWORD = '1234'
DB_NAME = 'db_temp_mnt'

def get_temps_realtime():
    conn = pymysql.connect(host=DB_HOST, user=DB_USER, password=DB_PASSWORD, db=DB_NAME, charset='utf8', cursorclass=pymysql.cursors.SSDictCursor)
    cur = conn.cursor()
    sql = "SELECT t_reg_date, t_temp FROM tbl_temp_mnt ORDER BY t_reg_date DESC LIMIT 12"
    cur.execute(sql)
    rows = cur.fetchall()
    conn.close()
    return rows

def get_temps_hourly():
    conn = pymysql.connect(host=DB_HOST, user=DB_USER, password=DB_PASSWORD, db=DB_NAME, charset='utf8', cursorclass=pymysql.cursors.SSDictCursor)
    cur = conn.cursor()
    sql = "SELECT DATE_FORMAT(t_reg_date, '%Y-%m-%d %H') as t_reg_date, round(avg(t_temp), 2) as t_temp FROM tbl_temp_mnt GROUP BY DATE_FORMAT(t_reg_date, '%Y-%m-%d %H') ORDER BY DATE_FORMAT(t_reg_date, '%Y-%m-%d %H') DESC LIMIT 12"
    cur.execute(sql)
    rows = cur.fetchall()
    conn.close()
    return rows

def get_temps_daily():
    conn = pymysql.connect(host=DB_HOST, user=DB_USER, password=DB_PASSWORD, db=DB_NAME, charset='utf8', cursorclass=pymysql.cursors.SSDictCursor)
    cur = conn.cursor()
    sql = "SELECT DATE_FORMAT(t_reg_date, '%Y-%m-%d') as t_reg_date, round(avg(t_temp), 2) as t_temp FROM tbl_temp_mnt GROUP BY DATE_FORMAT(t_reg_date, '%Y-%m-%d') ORDER BY DATE_FORMAT(t_reg_date, '%Y-%m-%d') DESC LIMIT 12"
    cur.execute(sql)
    rows = cur.fetchall()
    conn.close()
    return rows

def get_temps_monthly():
    conn = pymysql.connect(host=DB_HOST, user=DB_USER, password=DB_PASSWORD, db=DB_NAME, charset='utf8', cursorclass=pymysql.cursors.SSDictCursor)
    cur = conn.cursor()
    sql = "SELECT DATE_FORMAT(t_reg_date, '%Y-%m') as t_reg_date, round(avg(t_temp), 2) as t_temp FROM tbl_temp_mnt GROUP BY DATE_FORMAT(t_reg_date, '%Y-%m') ORDER BY DATE_FORMAT(t_reg_date, '%Y-%m') DESC LIMIT 12"
    cur.execute(sql)
    rows = cur.fetchall()
    conn.close()
    return rows

def set_temp(temp):
    conn = pymysql.connect(host=DB_HOST, user=DB_USER, password=DB_PASSWORD, db=DB_NAME, charset='utf8')
    cur = conn.cursor()
    sql = "INSERT INTO tbl_temp_mnt(t_temp, t_reg_date) VALUES (" + str(temp)+ ", NOW())"
    cur.execute(sql)
    conn.commit()
    conn.close()
