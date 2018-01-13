#define TrigPin A1 
#define EchoPin A0
#include <AFMotor.h>
#include <Servo.h>

AF_DCMotor motor_depan_kiri(3);
AF_DCMotor motor_belakang_kiri(2);

AF_DCMotor motor_belakang_kanan(1);
AF_DCMotor motor_depan_kanan(4);


int i=0;  
int m=0;
Servo myservo;

int curr_kecepatan = 100;

char curr_roda = 'e';


int curr_derajat_servo = 60;
void setup() {
  
  // put your setup code here, to run once:
  Serial.begin(9600);
  motor_depan_kiri.run(RELEASE);
  motor_belakang_kiri.run(RELEASE);
  
  motor_depan_kanan.run(RELEASE);
  motor_belakang_kanan.run(RELEASE);
  myservo.attach(9);

   pinMode(TrigPin,OUTPUT);
   pinMode(EchoPin,INPUT);
   Serial.println(curr_roda);
   myservo.write(curr_derajat_servo);
}

void loop() {
  // put your main code here, to run repeatedly:
  int durasi, durasijarak;

  digitalWrite(TrigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(TrigPin,LOW);
  durasi = pulseIn (EchoPin,HIGH);
  durasijarak = (durasi/2) / 29.1;
  Serial.println(durasijarak);
    if(durasijarak < 0){
      durasijarak=0;
    }else if (durasijarak < 5 ){
      mundur ();
      delay(500);
      berhenti();
    }else if(durasijarak > 5 && durasijarak < 15){
      
    }
  
  if (Serial.available() > 0){ 
    int keyboard = Serial.read();
    switch (keyboard){
      case 'a':
        maju();

        
      break;
      case 'b':
        mundur();

      break;
      case 'e':
        berhenti();
        
       break;
      case 'd':
        belokkanan();

       break;
      case 'c':
        belokkiri();

       break;
      case'g':
        //putar kanan
        curr_derajat_servo=curr_derajat_servo+10;
        myservo.write(curr_derajat_servo);
        
      break;
      case'f':
        //putar kiri
        curr_derajat_servo=curr_derajat_servo-10;
        myservo.write(curr_derajat_servo);
      break;
      case'j':
        //tambah kecepatan
        tambahkecepatan();
      break;
      case 'k':
        //kurang kecepatan
        kurangkecepatan();
      break;
      
     /* case '6':
      myservo.write(70);
      *\
      
      /*for(int y=30;y<=180;y++){
        myservo.write(y);
        Serial.println(y);
        delay(100);
        }*/
       
      //break;
    }
    Serial.println(curr_kecepatan);
    if(curr_kecepatan>255){
      curr_kecepatan=255;

      }
  }
  
}


void maju(){
        motor_depan_kiri.setSpeed(curr_kecepatan);
        motor_depan_kiri.run(FORWARD);
        motor_belakang_kiri.setSpeed(curr_kecepatan);
        motor_belakang_kiri.run(BACKWARD);
        motor_belakang_kanan.setSpeed(curr_kecepatan);
        motor_belakang_kanan.run(BACKWARD);
        motor_depan_kanan.setSpeed(curr_kecepatan);
        motor_depan_kanan.run(FORWARD);
}

void mundur(){
        motor_depan_kiri.setSpeed(curr_kecepatan);
        motor_depan_kiri.run(BACKWARD);
        motor_belakang_kiri.setSpeed(curr_kecepatan);
        motor_belakang_kiri.run(FORWARD);
        motor_belakang_kanan.setSpeed(curr_kecepatan);
        motor_belakang_kanan.run(FORWARD);
        motor_depan_kanan.setSpeed(curr_kecepatan);
        motor_depan_kanan.run(BACKWARD);
}

void berhenti(){
        motor_depan_kiri.run(RELEASE);
        motor_belakang_kanan.run(RELEASE);
        motor_belakang_kiri.run(RELEASE);
        motor_depan_kanan.run(RELEASE);
}

void belokkanan(){
   motor_depan_kiri.setSpeed(curr_kecepatan);
        motor_depan_kiri.run(FORWARD);
        motor_belakang_kiri.setSpeed(curr_kecepatan);
        motor_belakang_kiri.run(BACKWARD);
        motor_belakang_kanan.setSpeed(curr_kecepatan);
        motor_belakang_kanan.run(FORWARD);
        motor_depan_kanan.setSpeed(curr_kecepatan);
        motor_depan_kanan.run(BACKWARD);
}

void belokkiri(){
        motor_depan_kiri.setSpeed(curr_kecepatan);
        motor_depan_kiri.run(BACKWARD);
        motor_belakang_kiri.setSpeed(curr_kecepatan);
        motor_belakang_kiri.run(FORWARD);
        motor_belakang_kanan.setSpeed(curr_kecepatan);
        motor_belakang_kanan.run(BACKWARD);
        motor_depan_kanan.setSpeed(curr_kecepatan);
        motor_depan_kanan.run(FORWARD);
}

void tambahkecepatan(){
  curr_kecepatan = curr_kecepatan + 10;
}

void kurangkecepatan(){
    curr_kecepatan = curr_kecepatan - 10;
}

void kecepatansedang(){
  for(int k=curr_kecepatan;k>=20;k--){
   curr_kecepatan = k;
   current_jalan();
  }  
}

void current_jalan(){
  switch(curr_roda){
    case'a':
      maju();
    break;
    case'b':
      mundur();
    break;
    case'c':
      belokkiri();
    break;
    case'd':
      belokkanan();
    break;
    case'e':
      berhenti();
    break;
  } 
}






