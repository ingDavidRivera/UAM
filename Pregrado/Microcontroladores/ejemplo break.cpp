const int led1 = 9;
const int led2 = 10;
const int led3 = 11;
const int led4 = 12;
const int led5 = 13;
const int boton = 14;

int EstadoLED = LOW;
bool detenerSecuencia = false;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(boton, INPUT_PULLUP);
}

void loop() {
  int LED_Actual = led1;

  while (LED_Actual <= led5) {
    digitalWrite(LED_Actual, EstadoLED);
    delay(1000);
    LED_Actual++;
    if (digitalRead(boton) == LOW) {
      detenerSecuencia = true;
      break;
    }
  }
  
  if (detenerSecuencia) {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
    detenerSecuencia = false;
  }
  
  EstadoLED = !EstadoLED;
}
