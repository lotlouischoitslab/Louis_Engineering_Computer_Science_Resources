# -*- coding: utf-8 -*-
"""
Created on Wed Jan  5 15:25:08 2022

@author: LOTLOUISCHO
"""

import numpy as np
import cv2 as cv
import matplotlib.pyplot as plt

#Import Image
im = cv.imread('ktx_eum.jpg')

#BGR
plt.figure()
plt.imshow(im)
plt.title('Original')

#RGB
rgb = cv.cvtColor(im,cv.COLOR_BGR2RGB)
plt.figure()
plt.imshow(rgb)
plt.title('RGB')

#Gray Scale
gray = cv.cvtColor(im,cv.COLOR_BGR2GRAY)
plt.figure()
plt.imshow(gray,cmap='gray')
plt.title('Gray')

#Blur 
blur = cv.blur(im,(5,5))
blur = cv.cvtColor(blur,cv.COLOR_BGR2RGB)
plt.subplot(121)
plt.imshow(rgb)
plt.title('RGB')
plt.subplot(122)
plt.imshow(blur)
plt.title('Blur')

#Edge Detection
edges = cv.Canny(gray,100,200)
plt.subplot(121)
plt.imshow(gray,cmap='gray')
plt.title('Gray')
plt.subplot(122)
plt.imshow(edges,cmap='gray')
plt.title('Edge Detection')
