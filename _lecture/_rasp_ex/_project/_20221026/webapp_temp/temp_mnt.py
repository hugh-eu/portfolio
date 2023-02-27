from flask import Flask, request, render_template, jsonify
import RPi.GPIO as GPIO
import Adafruit_DHT as dht
import db_op_temp_mnt as db
import time

LOGGER_FLAG = True

app = Flask(__name__)

LED_GREEN = 5
LED_YELLOW = 6
LED_RED = 7

GPIO.setmode(GPIO.BCM)
GPIO.setup(LED_GREEN, GPIO.OUT)
GPIO.setup(LED_YELLOW, GPIO.OUT)
GPIO.setup(LED_RED, GPIO.OUT)

@app.route('/')
def root_index():
	if (LOGGER_FLAG): print("root_index() called.")
	h, c_t = dht.read_retry(dht.DHT11, 4)
	if c_t < 25:
		GPIO.output(LED_GREEN, True)
		GPIO.output(LED_YELLOW, False)
		GPIO.output(LED_RED, False)
	elif 25 <= c_t < 30:
		GPIO.output(LED_GREEN, False)
		GPIO.output(LED_YELLOW, True)
		GPIO.output(LED_RED, False)
	else:
		GPIO.output(LED_GREEN, False)
		GPIO.output(LED_YELLOW, False)
		GPIO.output(LED_RED, True)
	db.set_temp(c_t)
	temps = db.get_temps_realtime()
	times = []
	degs = []
	for t in temps:
		times.insert(0, (t['t_reg_date']).strftime('%y-%m-%d %H:%M:%S'))
		degs.insert(0, t['t_temp'])
	return render_template("temp_mnt_realtime.html", current_temp = db.get_temps_realtime()[0]['t_temp'], temps = temps, times = times, degs = degs)

@app.route('/hourly')
def hourly():
	if (LOGGER_FLAG): print("hourly() called.")
	h, c_t = dht.read_retry(dht.DHT11, 4)
	if c_t < 25:
		GPIO.output(LED_GREEN, True)
		GPIO.output(LED_YELLOW, False)
		GPIO.output(LED_RED, False)
	elif 25 <= c_t < 30:
		GPIO.output(LED_GREEN, False)
		GPIO.output(LED_YELLOW, True)
		GPIO.output(LED_RED, False)
	else:
		GPIO.output(LED_GREEN, False)
		GPIO.output(LED_YELLOW, False)
		GPIO.output(LED_RED, True)
	db.set_temp(c_t)
	temps = db.get_temps_hourly()
	times = []
	degs = []
	for t in temps:
		times.insert(0, t['t_reg_date'])
		degs.insert(0, t['t_temp'])
	return render_template("temp_mnt_hourly.html", current_temp = db.get_temps_realtime()[0]['t_temp'], temps = temps, times = times, degs = degs)

@app.route('/daily')
def daily():
	if (LOGGER_FLAG): print("daily() called.")
	h, c_t = dht.read_retry(dht.DHT11, 4)
	if c_t < 25:
		GPIO.output(LED_GREEN, True)
		GPIO.output(LED_YELLOW, False)
		GPIO.output(LED_RED, False)
	elif 25 <= c_t < 30:
		GPIO.output(LED_GREEN, False)
		GPIO.output(LED_YELLOW, True)
		GPIO.output(LED_RED, False)
	else:
		GPIO.output(LED_GREEN, False)
		GPIO.output(LED_YELLOW, False)
		GPIO.output(LED_RED, True)
	db.set_temp(c_t)
	temps = db.get_temps_daily()
	times = []
	degs = []
	for t in temps:
		times.insert(0, t['t_reg_date'])
		degs.insert(0, t['t_temp'])
	return render_template("temp_mnt_daily.html", current_temp = db.get_temps_realtime()[0]['t_temp'], temps = temps, times = times, degs = degs)

@app.route('/monthly')
def monthly():
	if (LOGGER_FLAG): print("monthly() called.")
	h, c_t = dht.read_retry(dht.DHT11, 4)
	if c_t < 25:
		GPIO.output(LED_GREEN, True)
		GPIO.output(LED_YELLOW, False)
		GPIO.output(LED_RED, False)
	elif 25 <= c_t < 30:
		GPIO.output(LED_GREEN, False)
		GPIO.output(LED_YELLOW, True)
		GPIO.output(LED_RED, False)
	else:
		GPIO.output(LED_GREEN, False)
		GPIO.output(LED_YELLOW, False)
		GPIO.output(LED_RED, True)
	db.set_temp(c_t)
	temps = db.get_temps_monthly()
	times = []
	degs = []
	for t in temps:
		times.insert(0, t['t_reg_date'])
		degs.insert(0, t['t_temp'])
	return render_template("temp_mnt_monthly.html", current_temp = db.get_temps_realtime()[0]['t_temp'], temps = temps, times = times, degs = degs)

@app.route('/ajax', methods=['POST'])
def ajax():
    data = request.get_json()
    print(data)

    return jsonify(result = "success", result2= data)


if __name__ == "__main__":
	app.run(debug=True, port=5000, host='0.0.0.0')
