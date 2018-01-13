#include <Servo.h>
Servo myservo;
int potensiometer= A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  int nilaiPot = analogRead (potensiometer);
  Serial.println(nilaiPot/6);
  int puter = nilaiPot/6;
  
  myservo.write(puter);
  delay(100);
}
