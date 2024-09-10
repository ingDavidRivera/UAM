/*******************************************
* Maestría en Ingeniería                   *
* Diseño de Dispositivos IoT               *
* Receptor desde BSFrance LoRa32u4         *
* Adaptado desde: LoRa Library             *                                         
*******************************************/
#include <SPI.h>
#include <LoRa.h>
#define ss 5
#define rst 14
#define dio0 2

void setup() {
  Serial.begin(115200);
  while (!Serial);
  Serial.println("LoRa Receptor");

  LoRa.setPins(ss, rst, dio0);
  while (!LoRa.begin(915E6)) {
    Serial.println(".");
    delay(500);
  }
  Serial.println("Inicialización de LoRa exitosa");
}

void loop() {
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    Serial.print("Dato recibido: ");
    while (LoRa.available()) {
      String LoRaData = LoRa.readString();
      Serial.print(LoRaData); 
    }
    Serial.print(" con RSSI ");
    Serial.println(LoRa.packetRssi());
  }
}
