int vcc = 13;
int led = 9;
int sens = 12;
void setup()

{
  // put your setup code here, to run once:
  pinMode(vcc, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(sens, INPUT);
  
  digitalWrite(vcc, HIGH);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int k = digitalRead(sens);
  if(k == 0){
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
}
