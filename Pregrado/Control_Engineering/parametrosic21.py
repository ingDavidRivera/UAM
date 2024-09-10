# -*- coding: utf-8 -*-
"""
Created on Wed Mar  3 16:46:14 2021

@author: david
"""
# importar librerias
import math
from control.matlab import *
a1= float(input("Ingrese el valor de a1: "))
a0= float(input("Ingrese el valor de a0: "))
# Clasificación de un sistema de control
# Sobreamortiguado a1^2>4a0
if(a1**2 > 4*a0):
    print("El sistema es sobreamortiguado")
# Críticamente amortiguado
elif(a1**2 == 4*a0):
    print("El sistema es críticamente amortiguado")
# Subamortiguado
else:    
    print("El sistema es subamortiguado")    
# Encontrar los coeficientes A,B,C
# Respuesta al escalón unitario
# step()
# Parámetros del sistema de control
# Máximo pico de sobreimpulso 
# Tiempo pico
# Tiempo de asentamiento