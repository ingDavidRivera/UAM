const int bot_incremento = 2;
const int bot_decremento = 3;
const int PinesLED[] = {7, 8, 9, 10, 11, 12, 13};
const int numero_de_LED = 7;

int LED_Actual = 0;

void setup() {
  for (int i = 0; i < numero_de_LED; i++) {
    pinMode(PinesLED[i], OUTPUT);
  }
  pinMode(bot_incremento, INPUT);
  pinMode(bot_decremento, INPUT);
}

void loop() {
  if (digitalRead(bot_incremento) == HIGH) {
    digitalWrite(PinesLED[LED_Actual], LOW);
    LED_Actual = (LED_Actual + 1) % numero_de_LED;
    digitalWrite(PinesLED[LED_Actual], HIGH);
    delay(200);
  } else if (digitalRead(bot_decremento) == HIGH) {
    digitalWrite(PinesLED[LED_Actual], LOW);
    LED_Actual = (LED_Actual + numero_de_LED - 1) % numero_de_LED;
    digitalWrite(PinesLED[LED_Actual], HIGH);
    delay(200);
  }
}
