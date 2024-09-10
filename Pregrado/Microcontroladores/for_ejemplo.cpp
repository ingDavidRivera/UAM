void setup()
{
  for(int LEDPin = 2 ; LEDPin <=7; LEDPin++){ 
  	pinMode(LEDPin, OUTPUT); // Configura los pines digitales como salida desde D2 a D7
  }  
}

void loop()
{
  for(int LEDPin = 2; LEDPin <=7; LEDPin++){
    digitalWrite(LEDPin, HIGH);
    delay(100); 
    digitalWrite(LEDPin, LOW);
  }
}
