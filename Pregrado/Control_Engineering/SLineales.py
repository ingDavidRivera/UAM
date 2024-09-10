# -*- coding: utf-8 -*-
"""
Created on Wed Apr 15 09:08:46 2020

@author: david
"""

import math

a1=int(input("Ingrese el valor de a1:"))
a0=int(input("Ingrese el valor de a0:"))

wn=math.sqrt(a0)
z=a1/(2*wn)
 #Tiempo de asentamiento
ta=4/(z*wn)
#Tiempo de elevacion
te=(2.5*z+0.8)/wn

#sobreamortiguado
if z>1:
 print("El sistema es sobreamortiguado")
#criticamente amortiguado 
elif z==1:
 print("Es sistema es criticamente amortiguado")
#subamortiguado
else:
 print("Es sistema es subamortiguado")
 w=wn*math.sqrt(1-z**2)
 print("El valor de W es igual a : " ,w)
 #Tiempo pico
 tp= math.pi/w
 #maximo pico de sobreimpulso
 mpsi=math.exp((-z*math.pi)/math.sqrt(1-z**2))
 print("El tiempo pico es igual a",tp,"segundos")
 print("El máximo pico de sobreimpulso es igual a : " ,100*mpsi,"%")

print("El valor de Wn es igual a : " ,wn)
print("El valor de Z es igual a : " ,z)
print("El tiempo de asentamiento es igual a",ta,"segundos")
print("El tiempo de elevación es igual a",te,"segundos")



