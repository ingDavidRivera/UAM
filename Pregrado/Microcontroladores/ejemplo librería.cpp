void setup() {
  Serial.begin(9600); // Inicializa la comunicación serial a 9600 baudios
}

void loop() {
  Serial.println("Hola mundo"); // Imprime el mensaje "Hola mundo"
  delay(1000); // Esperar 1 segundo
}
