# -*- coding: utf-8 -*-
"""
Created on Wed Jan  5 14:49:01 2022

@author: LOTLOUISCHO
"""

import numpy as np
import matplotlib.pyplot as plt
from scipy import interpolate

x = np.array([1,2,3,4,5])
y = np.array([1,0.8,0.4,0.3,0.2])

#Plot
#plt.plot(x,y,'*')

#Linear Interpolatation
f_lin = interpolate.interp1d(x,y)
x_new = np.arange(1,5,0.1)
y_lin = f_lin(x_new)

# Splint Interpolation
tick = interpolate.splrep(x,y,s=0)
y_spl = interpolate.splev(x_new,tick,der=0)

#Plot
fig, ax = plt.subplots()
ax.plot(x,y,'o',label='Data')
ax.plot(x_new,y_lin,label='Linear')
ax.plot(x_new,y_spl,label='Spline')
ax.legend()