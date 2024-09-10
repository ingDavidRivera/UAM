#include <Arduino.h>
#include <WiFi.h>
#include <ThingSpeak.h>
#include "Parametros_Red.h" 
/* Archivo parámetros de red disponible en: 

https://raw.githubusercontent.com/ingDavidRivera/TAI---Microcontroladores/main/Parametros_Red.h?token=GHSAT0AAAAAACJX3JFRMTK3XPD7R6FP7WZGZKCYN4A

*/
char ssid[] = ID_Red;
char pass[] = Red_contrasena;
unsigned long numero_de_canal = ID_Canal;
const char * WriteAPIKey = WRITE_API_Canal;

WiFiClient LaboratorioIoT;

// Definir pines
#define SensorTemperatura 27 // Pin asociado al sensor de temperatura
#define SensorLuz 26 // Pin asociado a la fotorresistencia

// Crear variables para almacenar los datos
float temperatura;
int Luz;


void setup(){
  Serial.begin(9600); // Inicializar la comunicación serial a 9600 baudios
  pinMode(SensorLuz,INPUT);
  while (!Serial)
  {
    ;    // Espera que el puerto serie se conecte
  }
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(LaboratorioIoT); // Inicializa ThingSpeak
}

void pruebas_Sensores(){
  temperatura = 100.0*((3.3*analogRead(SensorTemperatura))/4095.0);
  Luz = analogRead(SensorLuz);
  Luz = map(Luz, 0, 1666, 0, 100);
  Serial.print("El porcentaje de luz ambiente es igual a: ");
  Serial.print(Luz);
  Serial.println("%");
  Serial.print("La temperatura ambiente es igual a: ");
  Serial.print(temperatura);
  Serial.println("°C");
  delay(1000);
}

void conectar_WiFi(){
  // Conectar o reconectar a WiFi
  if(WiFi.status()!= WL_CONNECTED){
    Serial.print("Intentando conectar a la red: ");
    Serial.println(ID_Red);
    while (WiFi.status()!=WL_CONNECTED){
      WiFi.begin(ID_Red,Red_contrasena);
      Serial.print(".");
      delay(5000);
    }
   Serial.println("\n Conectado");
  }
}

void medir_enviar_temperatura(){
  temperatura = 100.0*((3.3*analogRead(SensorTemperatura))/4095.0);
  float t = ThingSpeak.writeField(numero_de_canal,1,temperatura,WriteAPIKey);
  delay(15000);
}

void loop(){
  // pruebas_Sensores(); // Función para inicializar y probar instrumentación sin IoT
  conectar_WiFi();    // Conectar o reconectar a WiFi
  medir_enviar_temperatura();
}
