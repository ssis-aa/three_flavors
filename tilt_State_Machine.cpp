#include <WiFiNINA.h>
#include <Arduino_LSM6DSOX.h>

float x, y, z;


#define TILT_FORWARD 0
#define TILT_BACKWARD 1
#define LEVEL 2

int state = LEVEL;

void setup() {
  
if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }
  
  pinMode(LEDR, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(LEDG, OUTPUT);
}

void updateSystem(void){
  // store acceleration into x, y, and z
    if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);
  }
}

int evaluateState(float x){
  if(x < -0.1){
     return TILT_FORWARD;
  }
  else if (x > 0.1){
     return TILT_BACKWARD;
  }
  else{
    return LEVEL;
  }
}

void reactToState(int state){
  switch(state){
    case TILT_FORWARD:
      drive_backward();
      break;
    case TILT_BACKWARD:
      drive_forward();
      break;
     case LEVEL:
      hold_motors();
      break;
  }
}

void light_red(){
  digitalWrite(LEDR, HIGH); //RED ON
  digitalWrite(LEDG, LOW); //GREEN OFF
  digitalWrite(LEDB, LOW); //BLUE OFF
}

void light_blue(){
  digitalWrite(LEDR, LOW); //RED OFF
  digitalWrite(LEDG, LOW); //GREEN OFF
  digitalWrite(LEDB, HIGH); //BLUE ON
}

void light_green(){
  digitalWrite(LEDR, LOW); //RED OFF
  digitalWrite(LEDG, HIGH); //GREEN ON
  digitalWrite(LEDB, LOW); //BLUE OFF
}

void loop() {
  updateSystem(); //update system variables and inputs
  state = evaluateState(x);//decide which state we need to be in
  reactToState(state); //based on the state, determine the output
  delay(10);                                          
}
