import pymysql

DB_HOST = "192.168.0.101"
DB_USER = "hugh"
DB_PW = "1234"
DB_NAME = "db_detector"

def checkIdAndPwForLogin(u_id, u_pw):
    conn = pymysql.connect(host=DB_HOST, user=DB_USER, password=DB_PW, db=DB_NAME, charset="utf8")
    cur = conn.cursor(pymysql.cursors.DictCursor)
    sql = "SELECT * FROM tbl_users WHERE u_id='" + u_id + "' AND u_pw='" + u_pw + "'"
    cur.execute(sql)
    rows = cur.fetchall()
    conn.close()
    return rows

def setLoginDate(u_no):
    conn = pymysql.connect(host=DB_HOST, user=DB_USER, password=DB_PW, db=DB_NAME, charset="utf8")
    cur = conn.cursor(pymysql.cursors.DictCursor)
    sql = "INSERT INTO tbl_login_log (u_no, l_login_date) VALUES (" + str(u_no) + ", NOW())"
    cur.execute(sql)
    conn.commit()
    conn.close()

def checkIdForSignup(u_id):
    conn = pymysql.connect(host=DB_HOST, user=DB_USER, password=DB_PW, db=DB_NAME, charset="utf8")
    cur = conn.cursor(pymysql.cursors.DictCursor)
    sql = "SELECT * FROM tbl_users WHERE u_id='" + u_id + "'"
    cur.execute(sql)
    rows = cur.fetchall()
    conn.close()
    return rows

def registId(u_id, u_pw):
    conn = pymysql.connect(host=DB_HOST, user=DB_USER, password=DB_PW, db=DB_NAME, charset="utf8")
    cur = conn.cursor(pymysql.cursors.DictCursor)
    sql = "INSERT INTO tbl_users (u_id, u_pw, u_auth, u_reg_date, u_mod_date) VALUES ('" + u_id + "', '" + u_pw + "', 'X', NOW(), NOW())"
    cur.execute(sql)
    conn.commit()
    conn.close()

def getImgList():
    conn = pymysql.connect(host=DB_HOST, user=DB_USER, password=DB_PW, db=DB_NAME, charset="utf8")
    cur = conn.cursor(pymysql.cursors.DictCursor)
    sql = "SELECT * FROM tbl_imgs ORDER BY i_no DESC"
    cur.execute(sql)
    rows = cur.fetchall()
    conn.close()
    return rows

def getImgListMonthly(month):
    conn = pymysql.connect(host=DB_HOST, user=DB_USER, password=DB_PW, db=DB_NAME, charset="utf8")
    cur = conn.cursor(pymysql.cursors.DictCursor)
    sql = "SELECT i_no, i_img_name, DATE_FORMAT(i_reg_date, '%Y-%m-%d %H:%i:%S') AS i_reg_date FROM tbl_imgs WHERE DATE_FORMAT(i_reg_date, '%Y-%m') = '" + month + "' ORDER BY i_no DESC"
    cur.execute(sql)
    rows = cur.fetchall()
    conn.close()
    return rows

def getImgListDaily(day):
    conn = pymysql.connect(host=DB_HOST, user=DB_USER, password=DB_PW, db=DB_NAME, charset="utf8")
    cur = conn.cursor(pymysql.cursors.DictCursor)
    sql = "SELECT i_no, i_img_name, DATE_FORMAT(i_reg_date, '%Y-%m-%d %H:%i:%S') AS i_reg_date FROM tbl_imgs WHERE DATE_FORMAT(i_reg_date, '%Y-%m-%d') = '" + day + "' ORDER BY i_no DESC"
    cur.execute(sql)
    rows = cur.fetchall()
    conn.close()
    return rows

def getUserList():
    conn = pymysql.connect(host=DB_HOST, user=DB_USER, password=DB_PW, db=DB_NAME, charset="utf8")
    cur = conn.cursor(pymysql.cursors.DictCursor)
    sql = "SELECT * FROM tbl_users ORDER BY u_no"
    cur.execute(sql)
    rows = cur.fetchall()
    conn.close()
    return rows

def changeAuth(u_no, u_auth):
    conn = pymysql.connect(host=DB_HOST, user=DB_USER, password=DB_PW, db=DB_NAME, charset="utf8")
    cur = conn.cursor(pymysql.cursors.DictCursor)
    sql = "UPDATE tbl_users SET u_auth = '" + u_auth + "', u_mod_date = NOW() WHERE u_no = " + str(u_no)
    cur.execute(sql)
    conn.commit()
    conn.close()

def setLogoutDate(u_id):
    conn = pymysql.connect(host=DB_HOST, user=DB_USER, password=DB_PW, db=DB_NAME, charset="utf8")
    cur = conn.cursor(pymysql.cursors.DictCursor)
    sql = "SELECT u_no FROM tbl_users WHERE u_id = '" + u_id + "'"
    cur.execute(sql)
    rows = cur.fetchall()
    u_no = rows[0]["u_no"]
    sql = "SELECT l_no FROM tbl_login_log WHERE u_no = " + str(u_no) + " ORDER BY l_no DESC LIMIT 1"
    cur.execute(sql)
    rows = cur.fetchall()
    l_no = rows[0]["l_no"]
    sql = "UPDATE tbl_login_log SET l_logout_date = NOW() WHERE l_no = " + str(l_no)
    cur.execute(sql)
    conn.commit()
    conn.close()
