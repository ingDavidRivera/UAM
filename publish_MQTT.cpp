// Incluir las librerías necesarias
#include <WiFi.h>
#include <PubSubClient.h>

// Información de la red Wi-Fi
const char* ssid = "WiFi_SSID"; // Reemplazar por el nombre de la red WiFI
const char* password = "WiFi_password"; // Reemplazar por la contraseña de la red WiFi seleccionada en la línea anterior

// Información del broker MQTT
const char* mqtt_server = "your_MQTT_server_IP"; // IP del servidor MQTT
const int mqtt_port = 1883;
const char* mqtt_topic = "your_MQTT_topic";

WiFiClient wifiClient;
PubSubClient client(wifiClient);

void setup() {
  // Inicializa la conexión a la red Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a la red Wi-Fi...");
  }
  Serial.println("Conectado a la red Wi-Fi");

  // Inicializa la conexión al broker MQTT
  client.setServer(mqtt_server, mqtt_port);
  while (!client.connect("arduino_publisher")) {
    Serial.println("Conectando al broker MQTT...");
    delay(1000);
  }
  Serial.println("Conectado al broker MQTT");
}

void loop() {
  // Envía un mensaje al tópico MQTT
  String message = "Hello, MQTT!";
  client.publish(mqtt_topic, message.c_str());
  Serial.println("Mensaje publicado: " + message);

  // Espera un tiempo antes de publicar el siguiente mensaje
  delay(5000);
}
