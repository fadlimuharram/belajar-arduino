int LED=13;
int LDR=A0;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int NilaiLDR = analogRead (LDR)/4;
  Serial.println(NilaiLDR);
  analogWrite(LED, NilaiLDR); 
  delay(100);
}
