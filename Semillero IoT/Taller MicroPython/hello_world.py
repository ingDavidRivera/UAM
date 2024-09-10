from machine import Pin # Importar el método Pin desde la librería machine
import time # Importar librería time
led = machine.Pin(25, machine.Pin.OUT)

while True:
    led.value(1)  # Enciende el LED
    time.sleep(1) # Espera 1 segundo
    led.value(0)  # Apaga el LED
    time.sleep(1) # Espera 1 segundo
