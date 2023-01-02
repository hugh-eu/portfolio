import pymysql

DB_HOST = "192.168.0.201"
DB_USER = "hugh"
DB_PW = "1234"
DB_NAME = "db_test"
DEVICE_NAME = "dht11_23t283"

def setTempHumidity(temp, humi):
    conn = pymysql.connect(host=DB_HOST, user=DB_USER, password=DB_PW, db=DB_NAME, charset="utf8", cursorclass=pymysql.cursors.DictCursor)
    cur = conn.cursor()
    sql = "INSERT INTO tbl_dht11 (d_name, d_temp, d_humi, d_reg_date) VALUES ('" + DEVICE_NAME + "', " + str(temp) + ", " + str(humi) + ", NOW())"
    cur.execute(sql)
    conn.commit()
    conn.close()

def getRealtime():
    conn = pymysql.connect(host=DB_HOST, user=DB_USER, password=DB_PW, db=DB_NAME, charset="utf8", cursorclass=pymysql.cursors.DictCursor)
    cur = conn.cursor()
    sql = "SELECT * FROM tbl_dht11 ORDER BY d_reg_date DESC LIMIT 20"
    cur.execute(sql)
    rows = cur.fetchall()
    conn.close()
    return rows

def getHourly():
    conn = pymysql.connect(host=DB_HOST, user=DB_USER, password=DB_PW, db=DB_NAME, charset="utf8", cursorclass=pymysql.cursors.DictCursor)
    cur = conn.cursor()
    sql = "SELECT round(AVG(d_temp), 2) AS d_temp, round(AVG(d_humi), 2) AS d_humi, date_format(d_reg_date, '%y-%m-%d %h') as d_reg_date FROM tbl_dht11 GROUP BY date_format(d_reg_date, '%y-%m-%d %h') ORDER BY d_reg_date DESC LIMIT 20"
    cur.execute(sql)
    rows = cur.fetchall()
    conn.close()
    return rows

def getDaily():
    conn = pymysql.connect(host=DB_HOST, user=DB_USER, password=DB_PW, db=DB_NAME, charset="utf8", cursorclass=pymysql.cursors.DictCursor)
    cur = conn.cursor()
    sql = "SELECT round(AVG(d_temp), 2) AS d_temp, round(AVG(d_humi), 2) AS d_humi, date_format(d_reg_date, '%y-%m-%d') as d_reg_date FROM tbl_dht11 GROUP BY date_format(d_reg_date, '%y-%m-%d') ORDER BY d_reg_date DESC LIMIT 20"
    cur.execute(sql)
    rows = cur.fetchall()
    conn.close()
    return rows

def getMonthly():
    conn = pymysql.connect(host=DB_HOST, user=DB_USER, password=DB_PW, db=DB_NAME, charset="utf8", cursorclass=pymysql.cursors.DictCursor)
    cur = conn.cursor()
    sql = "SELECT round(AVG(d_temp), 2) AS d_temp, round(AVG(d_humi), 2) AS d_humi, date_format(d_reg_date, '%y-%m') as d_reg_date FROM tbl_dht11 GROUP BY date_format(d_reg_date, '%y-%m') ORDER BY d_reg_date DESC LIMIT 20"
    cur.execute(sql)
    rows = cur.fetchall()
    conn.close()
    return rows
