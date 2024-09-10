const int led1 = 9;
const int led2 = 10;
const int led3 = 11;
const int led4 = 12;
const int led5 = 13;
const int boton = 14;

int EstadoLED = LOW;
int contador = 0;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(boton, INPUT_PULLUP);
}

void loop() {
  while (contador < 5) {
    digitalWrite(led1 + contador, HIGH);
    delay(500);
    digitalWrite(led1 + contador, LOW);
    delay(500);
    counter++;
    
    if (digitalRead(boton) == LOW) {
      break;
    }
  }
  
  while (counter > 0) {
    counter--;
    digitalWrite(led1 + contador, HIGH);
    delay(500);
    digitalWrite(led1 + contador, LOW);
    delay(500);
    
    if (digitalRead(boton) == LOW) {
      break;
    }
  }
}
