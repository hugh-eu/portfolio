
BLYNK_AUTH_TOKEN = "deqa72PJKJ52RqZMNX_XNGL4wX31HBjL"
BLYNK_TEMPLATE_ID = "TMPLxxA46IKD"
BLYNK_DEVICE_NAME = "Raspi"

import BlynkLib
import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BCM)
GPIO.setup(17, GPIO.OUT)

# initialize Blynk
blynk = BlynkLib.Blynk(BLYNK_AUTH_TOKEN)


# Register virtual pin handler
@blynk.on("V1")
def v3_write_handler(value):
    print('Current slider value: {}'.format(value[0]))
    if value[0] == "1":
        GPIO.output(17, True)
    else:
        GPIO.output(17, False)

while True:
    blynk.run()