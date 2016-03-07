//#include <SoftwareSerial.h>

//SoftwareSerial blue (11,12);
int led = 13;
String cad;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);
  delay(6000);
  Serial.begin(9600);
  digitalWrite(led, LOW);
  delay(1000);
  Serial.println("Activado");
  

}

void loop() {
  // put your main code here, to run repeatedly:
  int i = 0;
  while(i < 10){
    cad = cad + (String) Serial.read();
    ++i;
  }
  Serial.println((String)cad);
  Serial.println(i);
  cad = "";
  delay(1000);
}
