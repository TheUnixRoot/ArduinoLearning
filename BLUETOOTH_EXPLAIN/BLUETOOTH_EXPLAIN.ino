//#include <SoftwareSerial.h>



int LED = 13; //led pin
int info = 0;//variable for the information comming from the bluetooth module
int state = 0;//simple variable for displaying the state
//SoftwareSerial blu(2, 3);


void setup() {
  pinMode(LED, OUTPUT);    //defining LED pin
  digitalWrite(LED, HIGH); 
  
 delay(10000);
 Serial.begin(9600); //making serial connection
 digitalWrite(LED, LOW);
 delay(5000);//once the programm starts, it's going to turn of the led, as it can be missleading
 Serial.println("Conectado");
}
void loop() {
  char cad[10];
  int i = 0;
  while(Serial.available() > 0 && i < 10){  //if there is any information comming from the serial lines...
    info = Serial.read();  
    cad [i] = (char) info; 
    i++;
    delay(1000);
       //...than store it into the "info" variable
  }
  if(info == '1'){                //if it gets the number 1(stored in the info variable...
    digitalWrite(LED, HIGH);
    delay(100);//it's gonna turn the led on(the on board one)
   Serial.println("on ");
   for(int i = 0; i < 10 ; ++i){
    Serial.println(cad[i]);
    
   }
   info = 'd';
   
  }
  else if(info == '0'){
    digitalWrite(LED, LOW);      //else, it's going to turn it off
    info = 'd';
  }
}
