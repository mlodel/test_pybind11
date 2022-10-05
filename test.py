# from interface import Interface
# obj = Interface(2,2)
# a = [1,2]
# obj.numpy2eigen(a)
# print(a)

from example import *
import numpy as np
import time

a = np.ones((2,2), dtype=np.uint8).flatten().tolist()
start = time.time()
v = VecInt(a)
# v = a 
print(time.time()-start)
# start = time.time()
# v.append(2)
# print(time.time()-start)
start = time.time()
append_1(v)
print(time.time()-start)
# print(v)
b = np.array(v)
print(b.shape)