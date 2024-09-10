from machine import Pin # Importar el método Pin desde la librería machine
import time # Importar librería time
led = machine.Pin(25, machine.Pin.OUT) # GPIO 25 como salida
boton = machine.Pin(14, machine.Pin.IN) #GPIO14 definido como entrada

while True:
    led.value(boton()) # Salida del LED según el valor del pulsador
    time.sleep(0.2) # Espera 200 milisegundos
    