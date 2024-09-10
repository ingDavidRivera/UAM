const int Pulsador_pd = 14;  // Define el número del pin que se utilizará para el botón

void setup() {
  pinMode(Pulsador_pd, INPUT_PULLDOWN); // Configura el pin como entrada y activa la resistencia pull-down interna
  Serial.begin(9600);  // Inicia la comunicación serial para imprimir los mensajes en el monitor
}

void loop() {
  int EstadoPulsador = digitalRead(Pulsador_pd); // Lee el estado del pin

  if (EstadoPulsador == HIGH) { // Si el botón está presionado, el estado del pin será HIGH (por la resistencia pull-down)
    Serial.println("El botón está presionado");
  } else { // Si el botón no está presionado, el estado del pin será LOW (por la resistencia pull-down)
    Serial.println("El botón no está presionado");
  }
  
  delay(100); // Espera 100 milisegundos antes de leer el pin de nuevo
}
