int led=10;
int potensiometer= A0;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int nilaiPot = analogRead (potensiometer);
Serial.println(nilaiPot);
delay(100);
}
