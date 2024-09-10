// https://wokwi.com/projects/364929893939430401

// Pines de conexión de los potenciómetros
const int potLEDPines[]={A0,A1,A2};

// Pines de conexión del LED RGB
const int LED_Pines[]={20,19,18};

// Número de componentes del LED RGB
const int Num_LED = 3;

void setup() {
  // Configurar los pines de salida para el LED RGB
  for (int i = 0; i < Num_LED; i++){
    pinMode(LED_Pines[i],OUTPUT);
  }
}

void loop() {
  for(int i =0; i<Num_LED; i++){
  // Leer los valores de los potenciómetros
    int ValPotenciometros = analogRead(potLEDPines[i]);
  // Mapear los valores de los potenciómetros al rango de 0-255 (brillo del LED)
    int brilloLED = map(ValPotenciometros,0,1023,0,255);
  // Aplicar el brillo a cada componente del LED RGB
    analogWrite(LED_pines[i],brilloLED);
  }
}
