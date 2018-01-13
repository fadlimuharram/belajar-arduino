#include <Servo.h>
int led=10;
int potensiometer= A0;
Servo myservo;
void setup() {
  // put your setup code here, to run once:
myservo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
int val = analogRead(potensiometer);
val = map(val, 0, 1023,0,180);
myservo.write(val);
delay(15);

}
