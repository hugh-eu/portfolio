import RPi.GPIO as GPIO
import time

import BlynkLib

BLYNK_AUTH_TOKEN = "deqa72PJKJ52RqZMNX_XNGL4wX31HBjL"
blynk = BlynkLib.Blynk(BLYNK_AUTH_TOKEN)

servo_pin = 18
GPIO.setmode(GPIO.BCM)
GPIO.setup(servo_pin, GPIO.OUT)
pwm = GPIO.PWM(servo_pin, 50)  # 50Hz (서보모터 PWM 동작을 위한 주파수)
pwm.start(3.0) #서보의 0도 위치(0.6ms)이동:값 3.0은 pwm주기인 20ms의 3%를 의미하므로,0.6ms됨.


global i
i = 3

@blynk.on("V3")
def v3_write_handler(value):
    global i
    if i != float(value[0]):
        i = float(value[0])
        pwm.ChangeDutyCycle(i)
        time.sleep(1.0) 

try:
    while True:
        blynk.run()
except KeyboardInterrupt:    
    pwm.ChangeDutyCycle(0.0)
    pwm.stop()
    GPIO.cleanup()