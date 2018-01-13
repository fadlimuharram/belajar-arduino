#include <AFMotor.h>
AF_DCMotor motor(4);

//pin A0 led +
int lampu = A0;
int i=0;  


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(lampu, OUTPUT);
  motor.setSpeed(200);
  motor.run(RELEASE); 
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0){ 
    int keyboard = Serial.read();
    switch (keyboard){
      case '1':
        Serial.println("ini satu");
        //digitalWrite(lampu, HIGH);
        //delay(1000);
     
      for (int i= 0; i<=10; i++){
        Serial.println(i);
        fungsilampu();
      }
      break;
      case '2':
        Serial.println("ini dua");
        digitalWrite(lampu,LOW);
        motor.run(FORWARD);
        delay(1000);
        motor.run(RELEASE);
        delay(1000);
       break;
  
    }
  }
}


void fungsilampu(){
  digitalWrite(lampu,HIGH);
  delay(1000);
  
  digitalWrite(lampu,LOW);
  delay(1000);
  
}



