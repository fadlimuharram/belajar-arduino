// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>

AF_DCMotor motor(3);

void setup() {
  Serial.begin(9600);  
  motor.setSpeed(255);
  motor.run(RELEASE); 
  // set up Serial library at 9600 bps
  Serial.println("Motor test!");

  // turn on motor
  motor.setSpeed(200);
  motor.run(RELEASE);
}

void loop() {
 motor.run(FORWARD);
 delay(1000);
 motor.run(RELEASE);
 delay(10000);
}
