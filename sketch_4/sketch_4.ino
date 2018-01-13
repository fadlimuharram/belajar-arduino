int led = 11;//HIJAU
int led2 = 12;//KUNING
int led3 = 13;//MERAH
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(led, LOW);
digitalWrite(led3,HIGH);
digitalWrite(led2, LOW);
delay(5000);
digitalWrite(led, LOW);
digitalWrite(led3,LOW);
digitalWrite(led2,HIGH);
delay(1000);
digitalWrite(led, HIGH);
digitalWrite(led3,LOW);
digitalWrite(led2, LOW);
delay(5000);
digitalWrite(led, LOW);
digitalWrite(led3,LOW);
digitalWrite(led2,HIGH);
delay(1000);
}
