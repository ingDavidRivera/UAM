const int BUTTON_PIN = 16;  // Define el número del pin que se utilizará para el botón
void setup() {  
pinMode(BUTTON_PIN, INPUT_PULLDOWN); // Configura el pin como entrada y activa la resistencia pull-down interna             Serial.begin(9600);  // Inicia la comunicación serial para imprimir los mensajes en el monitor
}
void loop() {  
 int buttonState = digitalRead(BUTTON_PIN); // Lee el estado del pin  
 if (buttonState == HIGH) { // Si el botón está presionado, el estado del pin será HIGH (por la resistencia pull-down)            Serial.println("El botón está presionado");  
} else { // Si el botón no está presionado, el estado del pin será LOW (por la resistencia pull-down)    
 Serial.println("El botón no está presionado");  
}    
 delay(100); // Espera 100 milisegundos antes de leer el pin de nuevo
}
