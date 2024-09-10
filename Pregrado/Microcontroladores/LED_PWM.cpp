const int pot = A0;
const int LED = 18;

int brillo = 0;

void setup() {
  pinMode(LED,OUTPUT);
}

void loop() {
  brillo = analogRead(pot);
  brillo = map(brillo, 0, 1023, 0, 255);
  analogWrite(LED,brillo);
  delay(100);
}
