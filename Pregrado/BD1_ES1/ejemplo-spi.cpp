// Incluyo las librerías
#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         22          // Configurable, seleccionado por usuario
#define SS_PIN          21          // Configurable, seleccionado por usuario
#define Leyendo         2

/* Crea una instancia de la clase MFRC522 y configura la comunicación con el 
   módulo MFRC522 utilizando los pines SS_PIN y RST_PIN de la ESP32. */
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance

//*****************************************************************************************//
void setup() {
  Serial.begin(9600);                             // Inicializa comunicación serial 
  SPI.begin();                                    // Inicializa bus SPI
  mfrc522.PCD_Init();                             // Inicializa tarjeta MFRC522 
  Serial.println(F("Listo. Leyendo tarjeta:"));   // Muestra por serial que está listo para leer
  pinMode(Leyendo,OUTPUT);                        // LED indicador de lectura
}

//*****************************************************************************************//
void loop() {


  MFRC522::MIFARE_Key key; // Declara la variable "key" como un objeto de tipo "MFRC522::MIFARE_Key"
  for (byte i = 0; i < 6; i++) key.keyByte[i] = 0xFF;

  // Variables necesarias
  byte block;                 // Almacena valores entre 0 y 255
  byte len;                   // Almacena la longitud o tamaño de algún dato
  MFRC522::StatusCode status; // 

  //-------------------------------------------

  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    return;
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) {
    return;
  }

  Serial.println(F("**Tarjeta detectada y siendo leída:**"));
  digitalWrite(Leyendo,HIGH);
  delay(2000);
  digitalWrite(Leyendo,LOW);
  //-------------------------------------------

  mfrc522.PICC_DumpDetailsToSerial(&(mfrc522.uid)); //dump some details about the card

  //mfrc522.PICC_DumpToSerial(&(mfrc522.uid));      //uncomment this to see all blocks in hex

  //-------------------------------------------

  Serial.print(F("Name: "));

  byte buffer1[18];

  block = 4;
  len = 18;

  //------------------------------------------- GET FIRST NAME
  status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, 4, &key, &(mfrc522.uid)); //line 834 of MFRC522.cpp file
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Autenticación fallida: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  status = mfrc522.MIFARE_Read(block, buffer1, &len);
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Lectura fallida: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  //PRINT FIRST NAME
  for (uint8_t i = 0; i < 16; i++)
  {
    if (buffer1[i] != 32)
    {
      Serial.write(buffer1[i]);
    }
  }
  Serial.print(" ");

  //---------------------------------------- GET LAST NAME

  byte buffer2[18];
  block = 1;

  status = mfrc522.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, 1, &key, &(mfrc522.uid)); //line 834
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Authentication failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  status = mfrc522.MIFARE_Read(block, buffer2, &len);
  if (status != MFRC522::STATUS_OK) {
    Serial.print(F("Reading failed: "));
    Serial.println(mfrc522.GetStatusCodeName(status));
    return;
  }

  //PRINT LAST NAME
  for (uint8_t i = 0; i < 16; i++) {
    Serial.write(buffer2[i] );
  }


  //----------------------------------------

  Serial.println(F("\n**Lectura finalizada**\n"));

  delay(1000); //change value if you want to read cards faster

  mfrc522.PICC_HaltA();
  mfrc522.PCD_StopCrypto1();
}
