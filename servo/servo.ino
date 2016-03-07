#include <Servo.h>
Servo brum;
int led = 13;

void setup() {
  // put your setup code here, to run once:
  brum.attach(9);
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);
  delay(10000);
  digitalWrite(led, LOW);
  Serial.begin(9600);
}

void loop() {
  int info;
  if (Serial.available() > 0) {
    info = Serial.read();
  }
  if (info == '1') {
    for (int pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      brum.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  } else if (info == '0') {
    for (int pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      brum.write(pos);              // tell servo to go to position in variable 'pos'
      delay(15);                       // waits 15ms for the servo to reach the position
    }
  }
}
