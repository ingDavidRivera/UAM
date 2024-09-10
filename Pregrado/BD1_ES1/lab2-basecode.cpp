#include <Arduino.h>
#include <WiFi.h>
#include <ThingSpeak.h>

////////////////////////////// /* Modify the following lines with your network and ThingSpeak credentials */ //////////////////////////////
const char* ssid = "Your WiFi SSID";
const char* password = "Your WiFi Password";
unsigned long channelID = 12345;
const char* apiKey = "Your API Key";
////////////////////////////// /* Modify the lines above with your network and ThingSpeak credentials */ //////////////////////////////

WiFiClient client;

void setup() {
  Serial.begin(9600);
  WiFi.begin(ssid, password);

  while(!Serial){
    ;
  }
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
}

void loop() {
    if(WiFi.status() != WL_CONNECTED){
      Serial.print("Attempting to connect to SSID: ");
      Serial.print(ssid);
    while (WiFi.status() != WL_CONNECTED) {
      WiFi.begin(ssid,password);
      delay(5000);
      Serial.print(".");
  }
  Serial.println("Connected.");
    }
  float temperature = 25.0;
  ThingSpeak.writeField(channelID, 1, temperature, apiKey);
  delay(15000);
}
