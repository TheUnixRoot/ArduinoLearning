char NAME[] ="ArduLove";
char BPS ='4';
char PIN[] ="0000";

int LED = 13; //led pin
void setup() {
  Serial.begin(9600); // Making serial connection
  pinMode(LED, OUTPUT);    // Defining LED pin
  digitalWrite(LED, HIGH);  // Once the programm starts, it's going to turn on the led
  
  delay(10000);           // Ten seconds to connect bluetooth and getting ready for the set up
  
  digitalWrite(LED, LOW); // Visual signal to know the configuration started

  Serial.print("AT");   // Configures bluetooth to starting listening the following commands
  delay(1000);

  Serial.print("AT+NAME");  // Sets a new name
  Serial.print(NAME);
  delay(1000);

  Serial.print("AT+BPS");
  Serial.print(BPS);
  delay(1000);

  Serial.print("AT+PIN");   // Sets a new pin
  Serial.print(PIN);
  delay(1000);
}
void loop() {
  digitalWrite(13, !digitalRead(13)); // Set on/off led for 500ms each state to know everything get done
  delay(500);
}
