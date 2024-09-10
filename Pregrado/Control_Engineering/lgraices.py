# -*- coding: utf-8 -*-
"""
Created on Wed Apr 29 19:31:32 2020

@author: david
"""
from control.matlab import * # importamos librerías
import matplotlib.pyplot as plt
g=tf([62/50.],[1.,7/10.,214/100.])
print(g)



plt.figure(1)
yout,T=step(g)
plt.plot(T.T, yout.T) 

#anaconda prompt
# conda install numpy scipy matplotlib
# conda install -c conda-forge control