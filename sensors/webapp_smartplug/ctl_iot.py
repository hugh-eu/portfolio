from flask import Flask, request, render_template
import RPi.GPIO as GPIO
import db_op_relay as db

RELAY = 4
GPIO.setmode(GPIO.BCM)
GPIO.setup(RELAY, GPIO.OUT)

app = Flask(__name__)

@app.route("/")
def relay_control():
    return render_template("relay_control.html")

@app.route("/act", methods=["GET"])
def relay_control_act():
    if request.method == "GET":
        status = "[    ]"
        relay = request.args["relay"]
        if relay == "0":
            GPIO.output(RELAY, False)
            status = "OFF"
            db.set_log(relay)
        elif relay == "1":
            GPIO.output(RELAY, True)
            status = "ON"
            db.set_log(relay)
        return render_template("relay_control.html", status=status)

if __name__ == "__main__":
    app.run(debug=True, port=80, host="0.0.0.0")