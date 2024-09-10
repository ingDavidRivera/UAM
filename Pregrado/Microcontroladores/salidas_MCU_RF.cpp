//Declarar pines 🡪 Colores del semáforo.
#define ROJO 13     // Declaro el pin 13 como color ROJO
#define AMARILLO 12 // Declaro el pin 12 como color AMARILLO
#define VERDE 11 // Declaro el pin 11 como color VERDE

//Configurar los pines 🡪 Salida (PinMode) (OUTPUT)
void setup(){
  pinMode(ROJO, OUTPUT);      // Declaro el ROJO como salida
  pinMode(AMARILLO, OUTPUT);  // Declaro el AMARILLO como salida
  pinMode(VERDE, OUTPUT);     // Declaro el VERDE como salida  
}
//Función cíclica (Se repite)
void loop(){
  // Rojo
  rojo();
  amarillo();
  verde();
  amarillo();
  }
  
void rojo(){
  digitalWrite(ROJO, HIGH);   // Enciende el LED ROJO
  digitalWrite(AMARILLO, LOW);// Apaga el LED AMARILLO
  digitalWrite(VERDE, LOW);   // Apaga el LED VERDE
  delay(5000);                // Espera 5 segundos
}

void amarillo(){
  // Amarillo
  digitalWrite(ROJO, LOW);
  digitalWrite(AMARILLO, HIGH);
  digitalWrite(VERDE, LOW);
  delay(1000);
}

void verde(){
  // Verde
  digitalWrite(ROJO, LOW);
  digitalWrite(AMARILLO, LOW);
  digitalWrite(VERDE, HIGH);
  delay(4000);
}
