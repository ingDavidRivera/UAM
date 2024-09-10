# -*- coding: utf-8 -*-
"""
Created on Thu Oct  1 21:07:36 2020

@author: david
"""
# s^2+a1s+a0=0   s^2+2zwns+wn^2=0
# a0 = wn^2
# wn = sqrt(a0)
# Ingreso de datos  

import math
a1=float(input("Ingresa a1: "))
a0=float(input("Ingresa a0: "))
# Calculamos Wn
wn = math.sqrt(a0)
# Calculamos Z 
z=a1/(2*wn)
# Calculamos Tiempo de asentamiento (Ts)
Ts= 4/(z*wn)  # Para el críterio del 2% (4)
# Calculamos Tiempo de subida/elevación (Tr)
Tr= (2.5*z+0.8)/wn

# Clasificación del sistema
if z>1:
    print("El sistema es sobreamortiguado")
elif z==1:
    print("El sistema es críticamente amortiguado")
else:
    print("El sistema es subamortiguado")
    w=wn*math.sqrt(1-z**2)
    Tp=math.pi/w
    MPSI=math.exp(-(z*math.pi)/(math.sqrt(1-z**2)))
    print("El valor de W es igual a ",w,"segundos")
    print("El tiempo pico es igual a ",Tp,"segundos")  
    print("El máximo pico de sobreimpulso es igual a ",100*MPSI,"%")      
# Salida de datos
print("El valor de Wn es igual a ",wn)
print("El valor de z es igual a ",z)
print("El tiempo de asentamiento es igual a ",Ts,"segundos")
print("El tiempo de subida es igual a ",Tr,"segundos")