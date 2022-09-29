# -*- coding: utf-8 -*-
"""
Created on Tue Jan  4 17:28:32 2022

@author: LOTLOUISCHO
"""

import numpy as np
import matplotlib.pyplot as plt

#Drawing Histograms
data = np.random.randn(50000)
plt.hist(data,100,density=True) #Think about normal distribution in Probability


#Normal Distribution 정규분포
x = np.linspace(-4,4,100)
sigma = 1
mean = 0
nd = ( (1/(sigma*np.sqrt(2*np.pi)))*np.exp(-0.5*((x-mean)/sigma)**2) )
plt.plot(x,nd,'r',label='Std Normal Distribution')
plt.ylabel('PSD')
plt.xlabel('X')
plt.legend()

