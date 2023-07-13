import pymysql

DB_HOST = "192.168.0.201"
DB_USER = "hugh"
DB_PW = "1234"
DB_NAME = "db_test"
RELAY_NAME = "relay_823857"

def set_log(status):
    conn = pymysql.connect(host=DB_HOST, user=DB_USER, password=DB_PW, db=DB_NAME, charset='utf8', cursorclass=pymysql.cursors.DictCursor)
    cur = conn.cursor()
    sql = "INSERT INTO tbl_smartplug (p_name, p_status, p_reg_date) VALUES ('" + RELAY_NAME + "', " + status + ", NOW())"
    cur.execute(sql)
    conn.commit()
    conn.close()
