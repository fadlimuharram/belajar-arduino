const int TombolPin = A2;
int PosisiTombol = 0;

void setup() {
  Serial.begin(9600);
  pinMode (TombolPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
PosisiTombol = digitalRead (TombolPin);
  Serial.println(PosisiTombol);
}
