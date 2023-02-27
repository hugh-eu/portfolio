import time
import spidev
import BlynkLib
import RPi.GPIO as GPIO

BLYNK_AUTH_TOKEN = "deqa72PJKJ52RqZMNX_XNGL4wX31HBjL"
blynk = BlynkLib.Blynk(BLYNK_AUTH_TOKEN)

LED_PIN = 26
GPIO.setmode(GPIO.BCM)
GPIO.setup(LED_PIN, GPIO.OUT)

spi=spidev.SpiDev()
spi.open(0, 0)
spi.max_speed_hz=1350000

def analog_read(channel):
    r = spi.xfer2([1, (8 + channel) << 4, 0])
    adc_out = ((r[1]&3) << 8) + r[2]
    return adc_out

while True :
    reading = 1023 - analog_read(0)
    voltage = reading * 3.3 /1024
    blynk.virtual_write(2, reading)
    print("Reading=%d\tVoltage=%f" % (reading, voltage))
    if reading < 100:
	    GPIO.output(LED_PIN, GPIO.HIGH)
	    print("LED ON")
    else:
	    GPIO.output(LED_PIN, GPIO.LOW)
	    print("LED OFF")
    time.sleep(1)