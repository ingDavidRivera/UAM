const int ledPin1 = 9;
const int ledPin2 = 10;
const int ledPin3 = 11;
const int ledPin4 = 12;
const int ledPin5 = 13;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
}

void loop() {
  int ledState = LOW;
  while (true) {
    digitalWrite(ledPin1, ledState);
    digitalWrite(ledPin2, ledState);
    digitalWrite(ledPin3, ledState);
    digitalWrite(ledPin4, ledState);
    digitalWrite(ledPin5, ledState);
    ledState = !ledState;
    delay(500);
  }
}
