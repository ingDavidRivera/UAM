// Revisar el siguiente código y aplicar la indentación correcta.
void loop() { 
int botonPresionado1 = digitalRead(boton1); // Lee el estado del primer botón 
int botonPresionado2 = digitalRead(boton2); // Lee el estado del segundo botón 

// Estructura switch case para controlar los LED según los botones presionados 
switch (botonPresionado1 * 2 + botonPresionado2) { 
case 0: digitalWrite(ledRojo, LOW); // Apaga el LED rojo 
digitalWrite(ledVerde, LOW); // Apaga el LED verde 
break; 
case 1: digitalWrite(ledRojo, HIGH); // Enciende el LED rojo 
digitalWrite(ledVerde, LOW); // Apaga el LED verde 
break; 
case 2: digitalWrite(ledRojo, LOW); // Apaga el LED rojo 
digitalWrite(ledVerde, HIGH); // Enciende el LED verde 
break; 
case 3: digitalWrite(ledRojo, HIGH); // Enciende el LED rojo 
digitalWrite(ledVerde, HIGH); // Enciende el LED verde 
break; 
} 
} 
