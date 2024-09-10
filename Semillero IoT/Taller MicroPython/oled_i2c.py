# Importación de componentes de librería
from machine import Pin, I2C
from ssd1306 import SSD1306_I2C

i2c = I2C(1,scl=Pin(27),sda=Pin(26),freq=200000)  # Inicia I2C on I2C1 (GPIO 26/27)
print("I2C dirección:  " +hex(i2c.scan()[0]).upper())
print("I2C configuración:" +str(i2c))
oled = SSD1306_I2C(128,64,i2c)
oled.text("Hola",0,0)
oled.fill(0)
oled.show() 