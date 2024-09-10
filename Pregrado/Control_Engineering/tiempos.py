# -*- coding: utf-8 -*-
"""
Created on Sun Apr 19 01:05:28 2020

@author: david
"""

def saludo(nombre):
    return "Hola {}".format(nombre)
    
# argumentos
print("Ingresa tu nombre")
nombre=input()
print(saludo(nombre))    