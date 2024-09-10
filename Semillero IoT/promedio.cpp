#define pot1 A0
#define pot2 A1
#define pot3 A2

int lecturas[3]; // Vector que almacenará las lecturas de los potenciómetros
float promedio;  // Variable que almacenará el promedio de las lecturas

void setup(){
  Serial.begin(9600); // Inicializamos la comunicación serial a 9600 baudios
}

void loop(){
  // Lecturas de los potenciómetros
  lecturas[0] = analogRead(pot1);
  lecturas[1] = analogRead(pot2);
  lecturas[2] = analogRead(pot3);
  
  // Calculamos el promedio
  promedio = ((lecturas[0] + lecturas[1] + lecturas[2])/3.0);
  
  Serial.print("Lecturas: ");
  
  // Almacenamiento de las lecturas de los potenciómetros
  for(int i=0; i<3; i++){
    Serial.print(lecturas[i]);
    Serial.print(" ");
  }
  
  // Salida de los datos
  Serial.println();
  Serial.print("Promedio: ");
  Serial.println(promedio);
  // Tiempo de espera entre cada dato
  delay(500);
}
