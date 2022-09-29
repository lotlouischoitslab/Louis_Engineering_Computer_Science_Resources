# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

"f5 is another option to run the entire file"

import numpy as np
a = np.array([10,20,30])
print(a)
#a = np.arange(10)

#size of the related variables
print(a.shape) #how many elements inside the array
print(a.ndim) # dimension
print(a.dtype) #data type int double float long
print(a.itemsize) #how many bits are used
print(a.size) #how many elements inside the array
print(type(a)) #array

#if you want to add another data type element to array don't forget to do this

a = a.astype('float64')
a[2] = 30.55
print(a)
print(a.dtype)

c = np.array([10.1,20.1,30.1],'int32') #I can assign what data type to be assigned
print(c)

#divide by 2
x = np.array([7,9,11])
y = x/2
print(y) #prints out 3.5 4.5 5.5
print(y.dtype)

#make 1D array
a = np.array([10.,20.,30.])
print(a)

#make 2D array
a = np.array([[10,20,30],
              [40,50,60],
              [70,80,90]])


threed_array = np.array( #check variable explorer for the drawings
    [
     [[10,50],[20,60]],
     [[30,70],[40,80]]
     ]
    )

#matrix
b = np.matrix([[10],[20]]) #2 by 1 matrix column vector
b = np.matrix([[10,20],[30,40]]) #2 by 2 matrix

#insert
a = np.array([10,20,30])
a = np.insert(a,0,5)  #insert(array, index to add, what value)

#delete
a = np.delete(a,0) #delete(array, index to delete)

#Array generation function
a = np.array([1,2,3])

a = np.arange(3)

a = np.zeros((2,3))

a = np.ones((2,3))

a = np.linspace(0,5,6) #from 0 to 5, 6 elements

#Basic Operations
a = np.array([10,20,30])
b = np.array([1,2,3])

print("Basic arithmetic functions: ")
c = np.add(a,b)
print(c)

c = np.subtract(a,b)
print(c)

c = np.multiply(a,b)
print(c)

c = np.divide(a,b)
print(c)

c = np.divmod(a,b)
print(c)

c = np.exp(b)
print(c)

c = np.sqrt(b)
print(c)

idx = b < 20 #boolean logic 
print(idx)

#Statistical Functions in Numpy:
a = np.array([10,20,30])
mean = np.mean(a)

#Important for Machine Learning but weighted average
wav = np.average(a,weights=[1,1,0])
print("Average:", mean, "\nWeighted Average:", wav)

med = np.median(a)
print("Median:",med)

com = np.cumsum(a)
print("Cumulative sum:", com)

cov = np.cov(a)
print("Covariance:",cov)

std = np.std(a)
print("Standard Deviation:",std)

var = np.var(a)
print("Variance: ", var)

total = a.sum()
print("Total:",total)

minimum = a.min()
print("Minimum:",minimum, "Min index:", a.argmin())

maximum = a.max()
print("Maximum:",maximum,"Max index:", a.argmax())

range_ = a.ptp()
print("Range:",range_)

x = np.array([10,20,30,25,15])
y = np.sort(x)
idx = np.argsort(x)
print("Sorted array:", y ,"\nSorted index:",idx )

#We are now going to search sort 2 arrays
a = np.array([10,20,30])
b = np.array([-5,25])
c = np.searchsorted(a,b)

print(c) #Tells where -5 needs to go and tells where 25 needs to go

d = np.arange(1,7,1)

e = d.reshape(2,3) #reshape to 2 by 3 array

f = np.linspace(1,10,10) #make array from 1 to 10 with 10 elements

g = np.linspace(1,10,10).reshape(2,5)

a = np.array([[1,2],[3,4]])

np.repeat(a,2) #repeat 2 times
np.repeat(a,2,axis=0)  #repeat in 0 axis goes down vertically
np.repeat(a,2,axis=1)  #repeat in 1 axis goes horizontally

np.repeat(a,[1,2], axis = 0) 
#output : array([[1, 2],
         # [3, 4],
         # [3, 4]])

np.repeat(a,[3,1], axis = 0)
#output : array([[1, 2],
           #[1, 2],
           #[1, 2],
           #[3, 4]])

np.repeat(a,[1,2], axis = 1)
#output : array([[1, 2, 2],
              # [3, 4, 4]])

np.repeat(a,[3,1], axis = 1)
#output : array([[1, 1, 1, 2],
               # [3, 3, 3, 4]])

a = np.array([[1],[2],[3]])
b = np.array([[4],[5],[6]])
c1 = np.concatenate((a,b),axis = 0) #remember axis of 0 is vertical
c2 = np.concatenate((a,b),axis = 1) #remember axis of 1 is horizontal
print("c1:",c1,"\nc2:",c2)

#vertical stack
np.vstack((a,b))

#horizontal stack
np.hstack((a,b))

A = np.array([[10,20,30],
               [40,50,60]])

np.hsplit(A,3) #horizontal split
np.vsplit(A,2) #vertical split

A = np.array([[10,20,30],[40,50,60]])
A.transpose()

#change everything to one line
A.ravel()
A.reshape(-1)

A.ravel(order='C') #row major
A.ravel(order='F') #column major

A.flatten()

A = np.array([[[1,2]],
             [[3,4]],
             [[5,6]]])

B = A.squeeze()
#[1,2,3] and [4,5,6]
#
#[1,4]
#[2,5]
#[3,6]

A1 = np.array([1,2,3])
B1 = np.array([4,5,6])

A2 = A1[:,np.newaxis] #add new axis to A1 and store it to A2
B2 = B1[:,np.newaxis] #add new axis to B1 and store it to B2

np.concatenate((A2,B2),axis=0) #prints vertically
np.concatenate((A2,B2),axis=1) #prints horizontally

CV = np.vstack((A1,B1)).transpose() #prints vertically

CH = np.hstack((A1,B1)).transpose() #prints horizontally

A = np.array([10,20,30])
B = A

B is A

#shallow copy
A = np.array([10,20,30,40])
B = A.view()

B is A
id(A)
id(B) 
B[0] = 99 #both B and A get updated

B.shape = (2,2)
B[0][1] = 7

#shallow copy A and B don't share the same size

#deep copy
A = np.array([10,20,30,40])
B = A.copy()


a = np.array([0,1,2])
a.all() #if all the values are true but is false because of the 0
a.any() #asks if at least one is true
a.nonzero() #checks for non-zero
np.where(a>0) #asks where a[i] is greater than 0
np.where(a==0) #asks where a[i] is equal to 0
np.where(a<0) #asks where a[i] is less than 0

M1 = np.array([100,
               101,
               102,
               103,
               104])

#indexing and slicing
M1[0:5] #returns elements from 0 to 4
M1[0:5:1] #returns elements from 0 to 4 and increments the element by 1

M2 = np.array([[100,101,102],
               [200,201,202]])

fr = M2[0,:] #first row
fc = M2[:,0] #first column

M3 = np.array(
    [
     [[100,101,102,103],
      [104,105,106,107],
      [108,109,110,111]],
     [[200,201,202,203],
      [204,205,206,207],
      [208,209,210,211]]
     ])

#Image Processing
IMAGE = np.array([[255,0,255],
                  [255,0,255],
                  [255,0,255]])

idx = np.where(IMAGE==255)

IMAGE[idx] = 0 #color the image black


#Linear Algebra
M = np.array([[10,20],[30,40]])
N = np.array([[1,2],[3,4]])

print("Multiplying matrices M*N elemet wise:",M*N)

print("Multiplying matrices M*N matrix operations:",M@N)

print("Dot product:",M.dot(N)) #I could use this instead of @

a = np.zeros((3,3))
b = np.ones((3,3))

tr = np.trace(b) #add up the diagonals

M = np.array([[1,-3],
              [2,4]])
y = np.array([[1],[3]])

M_inv = np.linalg.inv(M)

sol = np.linalg.solve(M,y)
eg = np.linalg.eig(M)
sd = np.linalg.svd(M)

N = np.zeros((5,5))
np.fill_diagonal(N,100)

A = np.array([
    [10,20,30],
    [40,50,60],
    [70,80,90]
    ])

B = np.array(
    [
     [1],
     [2],
     [3]
    ])

B = B.repeat(3,axis=1)

#set theory
a = np.array([10,20,30,40,50])
b = np.array([30,50])
set_dif_a_b = np.setdiff1d(a,b) #a - b difference between a and b but in a
set_dif_b_a = np.setdiff1d(b,a) #b - a difference between b and a but in b
x = np.random.randint(100) #from 0 to 99








