int led = 9;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i=0;i<=255;i++){
    Serial.println(i);
    analogWrite(led, i);
    delay(100);
  }
  for (int i=255;i>=0;i--){
    Serial.println(i);
    analogWrite(led, i);
    delay(100);
  }
}
