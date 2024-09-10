// Declarar los pines
const int buttonPin =21;  // Pin del pulsador
const int LEDPin = 20;    // Pin del LED

// Variables para los estados del pulsador
int buttonState = HIGH;     // Estado del pulsador
int lastButtonState = HIGH; // Último estado del pulsador

void setup() {
  pinMode(buttonPin, INPUT); // Configurar el pin del pulsador como entrada
  pinMode(LEDPin, OUTPUT);   // Configurar el pin del LED como salida
}

void loop() {
  buttonState = digitalRead(buttonPin); // Leer el estado actual del pulsador
  // Detectar si hay cambios en el estado del pulsador
  if(buttonState != lastButtonState){   // Si hay un cambio en el estado del pulsador
    if(buttonState == LOW){             // Si el pulsador se ha presionado
      digitalWrite(LEDPin,HIGH);        // Encender el LED
    }else{
      digitalWrite(LEDPin,LOW);         // Apagar el LED
    }
  }
  lastButtonState = buttonState;        // Guardar el estado actual del pulsador para la próxima iteración
}// Declarar los pines
const int buttonPin =21;  // Pin del pulsador
const int LEDPin = 20;    // Pin del LED

// Variables para los estados del pulsador
int buttonState = HIGH;     // Estado del pulsador
int lastButtonState = HIGH; // Último estado del pulsador

void setup() {
  pinMode(buttonPin, INPUT); // Configurar el pin del pulsador como entrada
  pinMode(LEDPin, OUTPUT);   // Configurar el pin del LED como salida
}

void loop() {
  buttonState = digitalRead(buttonPin); // Leer el estado actual del pulsador
  // Detectar si hay cambios en el estado del pulsador
  if(buttonState != lastButtonState){   // Si hay un cambio en el estado del pulsador
    if(buttonState == LOW){             // Si el pulsador se ha presionado
      digitalWrite(LEDPin,HIGH);        // Encender el LED
    }else{
      digitalWrite(LEDPin,LOW);         // Apagar el LED
    }
  }
  lastButtonState = buttonState;        // Guardar el estado actual del pulsador para la próxima iteración
}
