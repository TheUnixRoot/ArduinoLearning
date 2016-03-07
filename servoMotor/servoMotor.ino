#include <Servo.h>

Servo serv1;
int LED = 13; //led pin
int info;

void setup() {
 pinMode(LED, OUTPUT);    //defining LED pin
 digitalWrite(LED, HIGH); 
 serv1.attach(9);
 delay(8000);
 
 Serial.begin(9600); //making serial connection
 digitalWrite(LED, LOW);
 delay(5000);//once the programm starts, it's going to turn of the led, as it can be missleading
 
 Serial.write("Conectado");
}
void loop() {
  if(Serial.available() > 0){
    info = Serial.read();
  }
  if(info == '1'){
    digitalWrite(LED, HIGH);
    } else if(info == '0'){
    digitalWrite(LED, LOW);
  }
}
