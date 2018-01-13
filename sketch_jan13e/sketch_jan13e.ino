#define TrigPin A1
#define EchoPin A0

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   pinMode(TrigPin,OUTPUT);
   pinMode(EchoPin,INPUT);
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
  
}
