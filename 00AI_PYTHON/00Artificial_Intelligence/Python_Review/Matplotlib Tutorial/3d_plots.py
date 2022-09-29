# -*- coding: utf-8 -*-
"""
Created on Tue Jan  4 17:37:53 2022

@author: LOTLOUISCHO
"""

#3D Plot
import numpy as np
import matplotlib.pyplot as plt

#f(x,y) = sin(x)*sin(y)

x = np.linspace(0,2*np.pi,20)
y = np.linspace(0,2*np.pi,20)
grid_x, grid_y = np.meshgrid(x,y)

z = np.sin(grid_x)*np.sin(grid_y)

hfig = plt.figure()
hax = hfig.gca(projection ='3d')
hax.plot_surface(grid_x,grid_y,z,cmap='jet')
hax.set_xlabel('x')
hax.set_ylabel('y')
hax.set_zlabel('z')

#Simple Animation
#OOP style 

fig, ax = plt.subplots()

x = np.array([1,2,3,4,5])
y = np.array([1,1,1,1,1])

hp, = ax.plot(x,y)
ax.set_ybound([0,11]) 

i = 2
hp.set_ydata(i*y)

for i in range(0,11,1):
    hp.set_ydata(i*y)
    plt.pause(0.5)