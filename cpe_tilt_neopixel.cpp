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
