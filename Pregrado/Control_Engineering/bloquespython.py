# -*- coding: utf-8 -*-
"""
Created on Thu Apr 16 21:44:32 2020

@author: david
"""

#import control
from control.matlab import *

###############################################################################
#           PYTHON             MATLAB                                         #
# g1=tf([20.],[3., 8.]);  #g1=tf(20,[3 8])                                    #
#                                                                             #
###############################################################################
#           100
#  -----------------------
#  3 s^4 + 26 s^3 + 48 s^2
#
import math
import sympy
g1=tf([20.],[3., 8.])
g2=tf([1.],[1., 0.])
g3=tf([5.],[1., 0.])
g4=tf([1.],[1., 6.])
h1=tf([10.],[1.])
h2=tf([6.],[1.])
h3=tf([1., 3.],[0., 1])
g1g2=series(g1,g2);
print("G1G2",g1g2)
g3g4=series(g3,g4);
print("G3G4",g3g4)
g1_4=series(g1g2,g3g4); # Numerador
# denominador
g1g2h1=series(g1g2,h1);
g2g3=series(g2,g3);
g4h2=series(g4,h2);
g2g3g4h2=series(g2g3,g4h2);
g1_4h3=series(g1_4,h3);
d=1+g1g2h1+g2g3g4h2+g1_4h3; # denominador 
print("El numerador es:", g1_4)
print("El denominador es:",d)
y_r=sympy.factor(g1_4)
d_r=sympy.factor(d)
#g=(y_r/d_r)
#print("y(s)/r(s)",g)
# y_r=tf([g1_4],[d])