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
