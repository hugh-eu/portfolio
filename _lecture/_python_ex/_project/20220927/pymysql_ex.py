import pymysql
import pandas as pd
conn = ""
cur = ""
rows = []
try:
    conn = pymysql.connect(host='192.168.61.130', user='hugh', password='1234', db='sqldb', charset='utf8', cursorclass=pymysql.cursors.SSDictCursor)
    cur = conn.cursor()
    sql = "SELECT * FROM buytbl"
    cur.execute(sql)
    rows = cur.fetchall()
    for row in rows:
        print(row)
except Exception as e:
    print(e)
finally:
    try:
        if cur != "":
            cur.close()
        if conn != "":
            conn.close()
    except Exception as e2:
        print(e2)

buytbl = pd.DataFrame(rows)
print(buytbl)
