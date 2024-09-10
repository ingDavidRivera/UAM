# -*- coding: utf-8 -*-
"""
Created on Thu Jun 11 19:46:01 2020

@author: david
"""
from control.matlab import *
import matplotlib as plt
N= [10.] # 10
D= [1., 2., 5.]#   s^2 + 5s + 6
ftr= tf(N,D)
print(ftr)
t,y = step(ftr)
plt.plot(t,y)
plt.grid(True)
plt.title("Respuesta al escalón")
plt.xlabel("segundos")