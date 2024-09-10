// Definición de pines
const int pinPotenciometroVelocidad = A0;   // Pin analógico para el potenciómetro de velocidad
const int pinPotenciometroSentido = A1;     // Pin analógico para el potenciómetro de sentido
const int pinMotor = 9;                     // Pin PWM para controlar el motor
const int pinLED_R = 5;                     // Pin digital para el LED rojo del RGB
const int pinLED_G = 6;                     // Pin digital para el LED verde del RGB
const int pinLED_B = 7;                     // Pin digital para el LED azul del RGB

// Variables globales
int velocidad = 0;                          // Variable para almacenar la velocidad del motor
int sentido = 0;                            // Variable para almacenar el sentido de giro del motor

void setup() {
  // Configuración de pines
  pinMode(pinMotor, OUTPUT);
  pinMode(pinLED_R, OUTPUT);
  pinMode(pinLED_G, OUTPUT);
  pinMode(pinLED_B, OUTPUT);
  
  // Inicialización de comunicación serial
  Serial.begin(115200);
}

void loop() {
  // Lectura de valores de los potenciómetros
  int valorPotenciometroVelocidad = analogRead(pinPotenciometroVelocidad);
  int valorPotenciometroSentido = analogRead(pinPotenciometroSentido);
  
  // Mapeo de los valores de los potenciómetros a los rangos deseados
  velocidad = map(valorPotenciometroVelocidad, 0, 1023, 0, 255);
  sentido = map(valorPotenciometroSentido, 0, 1023, -1, 1);
  
  // Control de la velocidad del motor mediante PWM
  analogWrite(pinMotor, velocidad);
  
  // Control del LED RGB según el sentido de giro
  if (sentido == -1) {
    // Sentido antihorario (CCW)
    digitalWrite(pinLED_R, HIGH);
    digitalWrite(pinLED_G, LOW);
    digitalWrite(pinLED_B, LOW);
  } else if (sentido == 1) {
    // Sentido horario (CW)
    digitalWrite(pinLED_R, LOW);
    digitalWrite(pinLED_G, HIGH);
    digitalWrite(pinLED_B, LOW);
  } else {
    // Motor detenido
    digitalWrite(pinLED_R, LOW);
    digitalWrite(pinLED_G, LOW);
    digitalWrite(pinLED_B, HIGH);
  }
  
  // Envío de datos a través de comunicación serial
  Serial.print("Estado: ");
  if (velocidad == 0) {
    Serial.print("Detenido");
  } else {
    Serial.print("En movimiento");
  }
  Serial.print("\tVelocidad: ");
  Serial.print(velocidad);
  Serial.print("\tSentido de giro: ");
  if (sentido == -1) {
    Serial.print("Antihorario (CCW)");
  } else if (sentido == 1) {
    Serial.print("Horario (CW)");
  } else {
    Serial.print("Detenido");
  }
  Serial.println();
  
  delay(100);  // Pausa para evitar lecturas y envíos excesivos por la comunicación serial
}
