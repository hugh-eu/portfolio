import pymysql

DB_HOST = '192.168.0.101'
DB_USER = 'hugh'
DB_PASSWORD = '1234'
DB_NAME = 'db_smart_plug'

def db_insert(led_status = 0):
    conn = pymysql.connect(host=DB_HOST, user=DB_USER, password=DB_PASSWORD, db=DB_NAME, charset='utf8')
    cur = conn.cursor()
    sql = "INSERT INTO tbl_led(l_status, l_reg_date, l_mod_date) VALUES ('" + str(led_status)+ "', NOW(), NOW())"
    cur.execute(sql)
    conn.commit()
    conn.close()

def db_get_led_status():
    conn = pymysql.connect(host=DB_HOST, user=DB_USER, password=DB_PASSWORD, db=DB_NAME, charset='utf8', cursorclass=pymysql.cursors.SSDictCursor)
    cur = conn.cursor()
    sql = "SELECT l_status FROM tbl_led ORDER BY l_reg_date DESC LIMIT 1"
    cur.execute(sql)
    rows = cur.fetchall()
    conn.close()
    return rows[0]["l_status"]
