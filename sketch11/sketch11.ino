#include <AFMotor.h>
AF_DCMotor motor(3);


//pin A0 led +
int lampu = A0;
int i=0;  
int m=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(lampu, OUTPUT);
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
        
        for (int m=0;m<=255;m++){
         Serial.println("ini dua ");
         //digitalWrite(lampu,LOW); 
         motor.setSpeed(m);
         motor.run(FORWARD);
         delay(10);
         motor.run(RELEASE);
         
        }
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



