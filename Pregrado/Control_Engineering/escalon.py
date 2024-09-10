from control.matlab import * # importamos librerías
import matplotlib.pyplot as plt
g=tf([62/50.],[1.,7/10.,214/100.])
print(g)
rlocus(g)


#g1=tf([3., 15.],[4.,6.,25/2.])
#print(g1)
#rlocus(g1)

