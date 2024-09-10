const int ledRojo = 15;     // Pin del LED rojo
const int ledVerde = 17;    // Pin del LED verde
const int boton1 = 14;      // Pin del primer botón
const int boton2 = 16;      // Pin del segundo botón

void setup() {
  pinMode(ledRojo, OUTPUT);   // Configura el pin del LED rojo como salida
  pinMode(ledVerde, OUTPUT);  // Configura el pin del LED verde como salida
  pinMode(boton1, INPUT);     // Configura el pin del primer botón como entrada
  pinMode(boton2, INPUT);     // Configura el pin del segundo botón como entrada
}

void loop() {
  int botonPresionado1 = digitalRead(boton1);   // Lee el estado del primer botón
  int botonPresionado2 = digitalRead(boton2);   // Lee el estado del segundo botón

  // Estructura switch case para controlar los LED según los botones presionados
  switch (botonPresionado1 * 2 + botonPresionado2) {
    case 0:
      digitalWrite(ledRojo, LOW);    // Apaga el LED rojo
      digitalWrite(ledVerde, LOW);   // Apaga el LED verde
      break;
    case 1:
      digitalWrite(ledRojo, HIGH);   // Enciende el LED rojo
      digitalWrite(ledVerde, LOW);   // Apaga el LED verde
      break;
    case 2:
      digitalWrite(ledRojo, LOW);    // Apaga el LED rojo
      digitalWrite(ledVerde, HIGH);  // Enciende el LED verde
      break;
    case 3:
      digitalWrite(ledRojo, HIGH);   // Enciende el LED rojo
      digitalWrite(ledVerde, HIGH);  // Enciende el LED verde
      break;
  }
}
