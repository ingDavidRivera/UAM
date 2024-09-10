/*******************************************
* Maestría en Ingeniería                   *
* Diseño de Dispositivos IoT               *
* Receptor desde BSFrance LoRa32u4         *
* Adaptado desde: LoRa Library             *                                         
*******************************************/
#include <SPI.h>
#include <LoRa.h>
#define csPin 8
#define resetPin 4 

int contador = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("Emisor LoRa");
  LoRa.setPins(csPin, resetPin); 
  if (!LoRa.begin(915E6)) {
    Serial.println("Comunicación fallida!");
    while (1);
  }
}

void loop() {
  Serial.print("Enviando datos: ");
  Serial.println(contador);

  // send packet
  LoRa.beginPacket();
//  LoRa.print("Hola ");
  LoRa.print(contador);
  LoRa.endPacket();
  contador++;
  delay(5000);
}
