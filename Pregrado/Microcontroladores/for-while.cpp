const int buttonPin = 17; // Pin del pulsador
const int ledPins[] = {3, 4, 5, 6, 7}; // Array de pines de los LEDs
const int numLeds = sizeof(ledPins) / sizeof(int); // Número de LEDs

void setup() {
  // Configurar el botón como entrada
  pinMode(buttonPin, INPUT_PULLUP);
  
  // Configurar los pines de los LEDs como salida
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Esperar a que se pulse el botón
  while (digitalRead(buttonPin) == HIGH) {
    // No hacer nada mientras no se pulse el botón
  }
  
  // Encender los LEDs uno por uno
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(500);
  }
  
  // Apagar los LEDs uno por uno
  for (int i = numLeds - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], LOW);
    delay(500);
  }
}
