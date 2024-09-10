int motorPin = 9; //Declaración de una variable int para el pin del motor
const int sensorPin = A0; //Declaración de una variable const int para el pin del sensor

void setup() {
  pinMode(motorPin, OUTPUT); //Configurar el pin del motor como salida
  pinMode(sensorPin, INPUT); //Configurar el pin del sensor como entrada
}

void loop() {
  int sensorValue = analogRead(sensorPin); //Declaración de una variable int local para almacenar el valor leído del sensor
  if(sensorValue > 500) { //Comparación del valor del sensor con un umbral
    digitalWrite(motorPin, HIGH); //Encender el motor
  } else {
    digitalWrite(motorPin, LOW); //Apagar el motor
  }
}
