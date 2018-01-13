int led = 9;
void setup() {
  // put your setup code here, to run once:
pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeate
  digitalWrite(led, HIGH);//pada port 13 , high adalah menyala
  delay(100); //selama 1 detik
  digitalWrite(led, LOW);//low adalah mati
  delay(100);
}
