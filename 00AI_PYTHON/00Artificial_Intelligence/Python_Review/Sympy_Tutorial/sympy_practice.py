# -*- coding: utf-8 -*-
"""
Created on Wed Jan  5 14:30:40 2022

@author: LOTLOUISCHO
"""

import numpy as np
from sympy import symbols

x = symbols('x')

expr = 2*x

ans = expr.subs(x,2)

#Differentiation
from sympy import diff
from sympy import sin
f = x**3

df1 = diff(f,x)
df2 = diff(df1,x)
df3 = diff(df2,x)

f = sin(x)
df1 = diff(f,x)

#Integration
from sympy import integrate
ans = integrate(f,(x,0,2*np.pi))

#Limit
from sympy import limit
l1 = limit(sin(x)/x,x,0)

#Ordinary Differential Equations
from sympy import Function, Eq, dsolve
t = symbols('t')
x = Function('x')
ODE = Eq(x(t).diff(t,t) + x(t))
ans = dsolve(ODE,x(t))