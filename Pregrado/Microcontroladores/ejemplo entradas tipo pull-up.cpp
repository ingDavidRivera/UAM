const int Pulsador = X; // Definimos el pin de entrada

void setup() {
  pinMode(Pulsador, INPUT_PULLUP); // Configuramos el pin como entrada con resistencia pull-up interna
  Serial.begin(9600); // Inicializamos la comunicación serial para mostrar el valor leído
}

void loop() {
  int Estado = digitalRead(Pulsador); // Leemos el valor del pin
  Serial.println(Estado); // Mostramos el valor leído en el monitor serial
  delay(100); // Esperamos un breve instante antes de volver a leer el pin
}
