# -*- coding: utf-8 -*-
"""
Created on Wed Apr 15 18:40:56 2020

@author: david
"""
import math
# s^2+a1s+a0=0
a1=int(input("Ingrese a1: "))
a0=int(input("Ingrese a0: "))
wn=math.sqrt(a0)
z=a1/(2*wn)
print("El valor de wn es igual",wn)
print("El valor de z es igual",z)
a12=a1**2
a04=4*a0
# Tiempo de elevación       
te=(2.5*z+0.8)/wn       
print("El tiempo de elevación es igual",te,"segundos")
# Tiempo de asentamiento    
ta=4/(z*wn)
print("El tiempo de asentamiento es igual",ta,"segundos")

###############################################################################
#                                 # Sobre     # Crit    # sub           399      #
#  Tiempo de elevación               si        si        si                   #
#  Tiempo de asentamiento            si        si        si                   #
#  Tiempo pico                       no        no        si                   #
#  Máximo pico de sobreimpulso       no        no        si                   #
###############################################################################

# Sobreamortiguados a1^2>4*a0 ó z>1
if a12 > a04:
    print("El sistema es sobreamortiguado")
# críticamente amortiguados a1^2=4*a0 ó z=1
elif a12==a04:
    print("El sistema es críticamente amortiguado")
# Subamortiguados a1^2<4*a0 ó 0<z<1
else:
    w=wn*math.sqrt(1-z**2)
    print("El valor de w es igual",w)
    print("El sistema es subamortiguado")
    # Tiempo pico
    tp=math.pi/w    
    print("El tiempo pico es igual",tp,"segundos")
    # Máximo pico de sobreimpulso 
    mpsi=math.exp(-(z*math.pi)/(math.sqrt(1-z**2)))
    print("El máximo pico de sobreimpulso es igual",100*mpsi,"%") 
print('Fin')                              