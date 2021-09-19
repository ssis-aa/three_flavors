import time
from adafruit_circuitplayground import cp
red = 0
green = 0
blue = 0
x = 0.0
y = 0.0
z= 0.0
cp.pixels.brightness = 0.1

while True:
    x, y, z = cp.acceleration

    if (y < -0.3):
        red = 255
        green = 0
        blue = 0

    elif (y > 0.3):
        red = 0
        green = 0
        blue = 255

    else:
        red = 0
        green = 255
        blue = 0
    
    cp.pixels.fill((red, green, blue))
    cp.pixels.show()
    time.sleep(0.1)
