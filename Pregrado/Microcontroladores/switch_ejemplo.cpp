// Declarar pines
const int PinPot = 0; // Potenciómetro conectado al pin A0

void setup(){
	Serial.begin(9600);
	DDRD = B11111100; // Pines D2 a D7 como salidas
}

void loop(){
  int Potenciometro = analogRead(PinPot);
  int LED = map(Potenciometro, 0,1023, 2,7);
  Serial.println(LED);
  
  switch(LED){
    case 2:
    	PORTD = B00000100;
    break;
    
    case 3:
    	PORTD = B00001000;
    break;
    
    case 4:
    	PORTD = B00010000;
    break;
    
    case 5:
    	PORTD = B00100000;
    break;
    
    case 6:
    	PORTD = B01000000;
    break;
    
    case 7:
    	PORTD = B10000000;
    break;  
   
  }    
}
// Simulación del ejemplo --> https://www.tinkercad.com/things/2o6iDYOPLlJ-super-leelo-crift/editel?tenant=circuits
