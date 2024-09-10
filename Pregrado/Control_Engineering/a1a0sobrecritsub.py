# -*- coding: utf-8 -*-
"""
Created on Mon Apr 13 16:03:52 2020

@author: david
"""
import math
# s^2+a1s+a0=0
# s^2+2s+81=0
# S^2+2*z*wn*S+wn^2=0
a1=float(input("Ingrese a1: "))
a0=float(input("Ingrese a0: "))
wn=math.sqrt(a0)
print("El valor de Wn es igual a: ",wn)
z=a1/(2*wn)


a12=a1**2
#print("El valor de a1^2 es igual a: ",a12)
a04=4*a0
#print("El valor de 4*a0 es igual a: ",a04)



# Sistema sobreamortiguado z mayor que 1
if z>1:
    print("El sistema es sobreamortiguado")
    # El sistema es sobreamortiguado, por lo tanto, no tiene:
    # - Tiempo pico w=wn*math.sqrt(1-z**2)
elif z == 1:
    print("El sistema es Críticamente amortiguado")
    # El sistema es críticamente amortiguado, por lo tanto, no tiene:
    # - Máximo pico de sobreimpulso    
else:    
    print("El valor de Z es igual a: ",z)
    w=wn*math.sqrt(1-z**2)
    print("El valor de W es igual a: ",w)
    # El sistema es subamortiguado, por lo tanto, tiene: 
    # Tiempo pico 
    tp=math.pi/w
    print("El tiempo pico es igual a: ",tp,"segundos")
    # Tiempo de asentamiento 
    ts=4/(z*wn)
    print("El tiempo de asentamiento es igual a: ",ts,"segundos")
    # Tiempo de elevación 
    tr=(2.5*z+0.8)/wn
    print("El tiempo de elevación es igual a: ",tr,"segundos")
    # Máximo pico de sobreimpulso 
    mpsi=math.exp((-z*math.pi)/math.sqrt(1-z**2))
    print("El máximo pico de sobreimpulso es igual a: ",100*mpsi,"%")
    print("El sistema es subamortiguado")    