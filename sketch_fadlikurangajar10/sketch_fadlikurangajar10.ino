int led=10;
int led2=14;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()>0){
    char data = Serial.read();
    if (data =='1'){
      digitalWrite(led, HIGH);
    }
    else if(data == '4'){
      digitalWrite(led, LOW);
    }
  }
}
