// Inicio variables motor
int pin2=9;   //Entrada 2 del L293D
int pin7=10;  //Entrada 7 del L293D

// Inicio variables para la lectura por puerto serie
long rx;
char command;
int tx;


void setup()
{
	pinMode(13, OUTPUT);
	digitalWrite(13, HIGH);
	delay(2000);
	// Enciendo el led 13 y espero dos segundos
	Serial.begin(9600);
	digitalWrite(13, LOW);
	delay(2000);
	// Comienzo la comunicacion serie y espero 2 segundos

	pinMode(pin2, OUTPUT);
	pinMode(pin7, OUTPUT);

	// Configuro el motor como salida
}

void loop()
{
	// En teoría va leyendo el puerto serie buscando numeros
	if(Serial.read() > 0){
		command = Serial.read();
	}
	switch (command) {
		case 'm':
    delay(3000);
		while(Serial.available() > 0){
			rx = Serial.parseInt();
		}
	// Para encender el motor:
	
		if( rx == 0){
		analogWrite(pin2, 127);
		analogWrite(pin7, 127);	    
		} else {
			int dos = map(rx, 1, 9, 0, 255);
			int siete = map(rx, 1, 9, 255, 0);
			analogWrite(pin2, dos);
			analogWrite(pin7, siete);
		}
		break;
		case 'l':
	      digitalWrite(13, HIGH);
	      break;
	      // Lo que diga el sensor de obstáculos  
	  }


	// Todo a izq o derecha
}
