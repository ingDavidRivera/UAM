import machine # Importa la librería machine
import time # Importa la librería tiempo

potenciometro = machine.ADC(26) # GPIO 26 como primer canal ADC0 en el conversor análogo - digital

while True:
    print(potenciometro.read_u16()) # Muestra el valor leído por el potenciómetro
    time.sleep(0.1) # Espera 100 milisegundos
    