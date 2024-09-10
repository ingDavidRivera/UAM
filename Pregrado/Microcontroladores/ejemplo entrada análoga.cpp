#define Potenciometro A0 // Asigna el pin A0 al potenciómetro
// const int Potenciometro = A0; 

int valPot = 0; // Variable para almacenar el valor del potenciómetro

void setup() {
  Serial.begin(9600); // Inicializa la comunicación serial a 9600 baudios
}

void loop() {
  valPot = analogRead(Potenciometro);
  Serial.println("Valor potenciómetro: "); // Imprime el mensaje "Valor potenciómetro"
  Serial.print(valPot); // Imprime el valor leído por el potenciómetro
  delay(1000); // Esperar 1 segundo
}
