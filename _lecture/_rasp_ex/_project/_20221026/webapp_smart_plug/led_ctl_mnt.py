from flask import Flask, request, render_template 
import RPi.GPIO as GPIO
import time
import db_operator as db
import config as cf
import datetime
import Adafruit_DHT as dht

LED = 17
led_status = 0

app = Flask(__name__)

GPIO.setmode(GPIO.BCM)
GPIO.setup(LED, GPIO.OUT)

@app.route('/')
def root_index():
    if (cf.LOGGER_FLAG): print("root_index() called.")
    if db.db_get_led_status() == "0":
        status = "OFF"
    else:
        status = "ON"

    return render_template('led_ctl.html', l_status=status)

@app.route('/led_btn_click', methods=['GET'])
def led_btn_click():
    if (cf.LOGGER_FLAG): print("led_btn_click() called.")
    if request.method == 'GET':
        click_value = request.args["click_value"]
        if click_value == "1":
            if db.db_get_led_status() == "0":
                GPIO.output(LED, True)
                led_status = 1
                if cf.LOGGER_FLAG: print("led_status :", led_status)
                db.db_insert(led_status)
        else:
            if db.db_get_led_status() == "1":
                GPIO.output(LED, False)
                led_status = 0
                if cf.LOGGER_FLAG: print("led_status :", led_status)
                db.db_insert(led_status)
    if db.db_get_led_status() == "0":
        status = "OFF"
    else:
        status = "ON"
    return render_template('led_ctl.html', l_status=status)

@app.route('/consumption_power', methods=['GET'])
def consumption_power():
    if (cf.LOGGER_FLAG): print("consumption_power() called.")
    return render_template("consumption_power.html")

if __name__ == "__main__":
    app.run(debug=True, port=5000, host='0.0.0.0')
