# three_flavors
These are three programs that each has the same output on hardware, but includes different implementation in software.

More details in the video [W6-3 - Introduction to State Machine Programming](https://youtu.be/FPyg7os2Cbw)

## Circuit Playground Expess [from Adafruit](https://learn.adafruit.com/adafruit-circuit-playground-express) - CircuitPython

``` py
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
```

## Circuit Playground Expess - C++

``` cpp
#include <Adafruit_CircuitPlayground.h>
#include <Wire.h>
#include <SPI.h>

float x, y, z;
int red, blue, green;

void setup() {
  CircuitPlayground.begin();
  CircuitPlayground.strip.setBrightness(10);
}

void loop() {
  y = CircuitPlayground.motionY();

  if(y < -0.3){
     red = 255;
     blue = 0;
     green = 0;
  }
  else if (y > 0.3){
     red = 0;
     blue = 255;
     green = 0;
  }
  else{
    red = 0;
    blue = 0;
    green = 255;

  }
  for (int i=0; i<10; ++i) {
      CircuitPlayground.strip.setPixelColor(i, red, green, blue);
  }
    CircuitPlayground.strip.show();
  delay(200);                                          
}
```

## Raspberry Pi 2040 - C++

``` cpp
#include <WiFiNINA.h>
#include <Arduino_LSM6DSOX.h>

float x, y, z;
 
void setup() {
  
if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }
  
  pinMode(LEDR, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(LEDG, OUTPUT);
}

void loop() {
  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);
  }
  if(x < -0.1){
      digitalWrite(LEDR, HIGH); //RED ON
      digitalWrite(LEDG, LOW); //GREEN OFF
      digitalWrite(LEDB, LOW); //BLUE OFF
  
  }
  else if (x > 0.1){
      digitalWrite(LEDR, LOW); //RED OFF
      digitalWrite(LEDG, LOW); //GREEN OFF
      digitalWrite(LEDB, HIGH); //BLUE ON
      
  }
  else{
  digitalWrite(LEDR, LOW); //RED OFF
  digitalWrite(LEDB, LOW); //BLUE OFF
  digitalWrite(LEDG, HIGH); //GREEN ON
  }
  delay(10);                                          
}
```
