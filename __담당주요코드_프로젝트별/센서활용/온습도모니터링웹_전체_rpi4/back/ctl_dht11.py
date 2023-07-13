from flask import Flask, request, render_template
import db_op_dht11 as db
import Adafruit_DHT

SENSOR = Adafruit_DHT.DHT11

PIN = 4

app = Flask(__name__)

@app.route("/")
def dht11_root():
    h, t = Adafruit_DHT.read_retry(SENSOR, PIN)
    db.setTempHumidity(t, h)
    rows = db.getRealtime()
    d_temps = []
    d_humis = []
    d_reg_dates = []
    for row in rows:
        d_temps.insert(0, row["d_temp"])
        d_humis.insert(0, row["d_humi"])
        d_reg_dates.insert(0, row["d_reg_date"].strftime("%y-%m-%d %H:%M:%S"))
    return render_template("dht11_realtime.html", rows=rows, temps = d_temps, humis = d_humis, dates = d_reg_dates)

@app.route("/hourly")
def dht11_hourly():
    h, t = Adafruit_DHT.read_retry(SENSOR, PIN)
    db.setTempHumidity(t, h)
    rows = db.getHourly()
    d_temps = []
    d_humis = []
    d_reg_dates = []
    for row in rows:
        d_temps.insert(0, row["d_temp"])
        d_humis.insert(0, row["d_humi"])
        d_reg_dates.insert(0, row["d_reg_date"])
    return render_template("dht11_hourly.html", rows=rows, temps = d_temps, humis = d_humis, dates = d_reg_dates)

@app.route("/daily")
def dht11_daily():
    h, t = Adafruit_DHT.read_retry(SENSOR, PIN)
    db.setTempHumidity(t, h)
    rows = db.getDaily()
    d_temps = []
    d_humis = []
    d_reg_dates = []
    for row in rows:
        d_temps.insert(0, row["d_temp"])
        d_humis.insert(0, row["d_humi"])
        d_reg_dates.insert(0, row["d_reg_date"])
    return render_template("dht11_daily.html", rows=rows, temps = d_temps, humis = d_humis, dates = d_reg_dates)

@app.route("/monthly")
def dht11_monthly():
    h, t = Adafruit_DHT.read_retry(SENSOR, PIN)
    db.setTempHumidity(t, h)
    rows = db.getMonthly()
    d_temps = []
    d_humis = []
    d_reg_dates = []
    for row in rows:
        d_temps.insert(0, row["d_temp"])
        d_humis.insert(0, row["d_humi"])
        d_reg_dates.insert(0, row["d_reg_date"])
    return render_template("dht11_monthly.html", rows=rows, temps = d_temps, humis = d_humis, dates = d_reg_dates)


if __name__ == "__main__":
    app.run(debug=True, port=80, host="0.0.0.0")