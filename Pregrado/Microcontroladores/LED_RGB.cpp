// Pines de conexión de los potenciómetros
const int potLEDRojo = A0;
const int potLEDVerde = A1;
const int potLEDAzul = A2;

// Pines de conexión del LED RGB
const int pinRojo  = 20;
const int pinVerde = 19;
const int pinAzul  = 18;

void setup() {
  // Configurar los pines de salida para el LED RGB
  pinMode(pinRojo, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinAzul, OUTPUT);
}

void loop() {
  // Leer los valores de los potenciómetros
  int valor_rojo = analogRead(potLEDRojo);  
  int valor_verde = analogRead(potLEDVerde);  
  int valor_azul = analogRead(potLEDAzul);  

  // Mapear los valores de los potenciómetros al rango de 0-255 (brillo del LED)
  int brilloRojo = map(valor_rojo, 0, 1023, 0, 255);    
  int brilloVerde = map(valor_verde, 0, 1023, 0, 255);
  int brilloAzul = map(valor_azul, 0, 1023, 0, 255);

  // Aplicar el brillo a cada componente del LED RGB
  analogWrite(pinRojo, brilloRojo);
  analogWrite(pinVerde, brilloVerde);
  analogWrite(pinAzul, brilloAzul);
}
