// Lectura Analógica

// Pines (Constante)
const int Pot1 = 34;

// Variables
int valorPot1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  valorPot1 = analogRead(Pot1);
  Serial.println(valorPot1);
  delay(1000);
}
