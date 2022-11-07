# -*- coding: utf-8 -*-
"""
Created on Tue Jan  4 17:28:32 2022

@author: LOTLOUISCHO
"""

import matplotlib.pyplot as plt
import numpy as np

#Important for signal processing in electrical computer engineering
t = np.linspace(0,100,1000)#remember the t is in radians NOT in degrees
tau = 100
y = np.sin(t)*np.exp(-t/tau)
plt.plot(t,y,label='Decay Oscillating Response')
plt.ylabel('y [m]')
plt.xlabel('t [s]')
plt.legend()

# Euler Equation
t = np.linspace(0,1,100)
f = 1 #frequency
y_euler = np.exp(1j*2*np.pi*f*t)
y_cos = np.real(y_euler) #real numbers
y_sin = np.imag(y_euler) #imaginary numbers

hfig, hax = plt.subplots(2,1) #split the plots into 2 distinct graphs 
#2 y axis and 1 x axis
hax[0].plot(t,y_cos,'-r',label='cos')
hax[1].plot(t,y_sin,'--b',label='sin')
hax[0].grid()
hax[0].legend()
hax[1].grid()
hax[1].legend()
