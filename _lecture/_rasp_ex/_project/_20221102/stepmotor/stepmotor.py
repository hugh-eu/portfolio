import time
import RPi.GPIO as GPIO

import BlynkLib

BLYNK_AUTH_TOKEN = "deqa72PJKJ52RqZMNX_XNGL4wX31HBjL"
blynk = BlynkLib.Blynk(BLYNK_AUTH_TOKEN)

GPIO.setmode(GPIO.BCM)
STEP_PINS = [12, 16, 20, 21]

for pin in STEP_PINS:
    GPIO.setup(pin, GPIO.OUT)
    GPIO.output(pin, False)

stepCounter = 0
stepCount = 4

SEQ0 = [[1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0], [0, 0, 0, 1]]
SEQ1 = [[0, 0, 0, 1], [0, 0, 1, 0], [0, 1, 0, 0], [1, 0, 0, 0]]

global speed
speed = 0
global SEQ
SEQ = []

@blynk.on("V2")
def v2_write_handler(value):
    global SEQ
    if value[0] == "1":
        SEQ = SEQ1
    else:
        SEQ = SEQ0

@blynk.on("V3")
def v3_write_handler(value):
    global speed
    speed = float(value[0])

try:
    while True:
        blynk.run()
        print("speed :", speed)
        print("SEQ :", SEQ)
        if speed != 0 and len(SEQ) != 0:
            for pin in range(0, 4):
                xpin = STEP_PINS[pin]
                if SEQ[stepCounter][pin] != 0:
                    GPIO.output(xpin, True)
                else:
                    GPIO.output(xpin, False)
            stepCounter += 1
            if (stepCounter == stepCount):
                stepCounter = 0
            if (stepCounter < 0):
                stepCounter = stepCount
            time.sleep(speed)
        
except KeyboardInterrupt:
    GPIO.cleanup()