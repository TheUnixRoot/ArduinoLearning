int triggerPin = 7; //triggering on pin 7
int echoPin = 8;    //echo on pin 8
int LED = 13;
int info;

void setup() {
  delay(5000);
  pinMode(triggerPin, OUTPUT); //defining pins
  pinMode(echoPin, INPUT);
  pinMode(LED, OUTPUT);

  Serial.begin(9600); //making serial connection
 
}

void loop() {
  
  int duration, distance;    //Adding duration and distance
  
  digitalWrite(triggerPin, HIGH); //triggering the wave(like blinking an LED)
  delay(10);
  digitalWrite(triggerPin, LOW);
  
  duration = pulseIn(echoPin, HIGH); //a special function for listening and waiting for the wave
  distance = ((duration/2000)*340) * 100; //transforming the number to cm(if you want inches, you have to change the 29.1 with a suitable number
  
  //IF YOU WANT THE PORGRAM SPITTING OUT INFORMATION SLOWER, JUST UNCOMMENT(DELETE THE 2 //) THE NEXT LINE AND CHANGE THE NUMBER
  //delay(500);
  if(distance < 20){
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
  delay(500);
}
