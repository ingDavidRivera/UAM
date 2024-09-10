const int tiempo = 100;  

void setup() {
  for (int Pin = 9; Pin < 14; Pin++) {
    pinMode(Pin, OUTPUT);
  }
}

void loop() {
  for (int Pin = 9; Pin < 14; Pin++) {
    digitalWrite(Pin, HIGH);
    delay(tiempo);
    digitalWrite(Pin, LOW);
  }

  for (int Pin = 13; Pin >= 9; Pin--) {
    digitalWrite(Pin, HIGH);
    delay(tiempo);
    digitalWrite(Pin, LOW);
  }
}
