# -*- coding: utf-8 -*-
"""
Created on Wed Jul  3 22:46:20 2024

@author: vinic
"""
import sys
from datetime import datetime
import math
now = datetime.now
sys.setrecursionlimit(150000)
validation_treshold = 1

def bissec_recur(f, ran, prec, sol):
    #print(str(ran))
    a = ran[0]
    b = ran[1]
    
    
    if f(a)*f(b)>0 and abs(a - b) < validation_treshold:
        return
    
    
    c = (a + b)/2
    
    if f(a)*f(b)<0 and abs(a - b) < prec:
        sol.append([c, (a, b)])
        return
    elif abs(a - b) < prec:
        return
    
    if f(a)*f(b)<0 and abs(a - b) < validation_treshold:
        bissec_recur(f, (a, c), prec, sol)
        bissec_recur(f, (c, b), prec, sol)

        
    if not abs(a - b) < validation_treshold:
        bissec_recur(f, (a, c), prec, sol)
        bissec_recur(f, (c, b), prec, sol)
    
    return
    

def bissec(f, ran, prec):
    start = now()
    solucao = []
    bissec_recur(f, ran, prec, solucao)
    end = now()
    print("concluido em", (end-start))
    return solucao