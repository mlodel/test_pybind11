import numpy as np
import time

from interface import Interface

vector = np.ones((1000000, 1), dtype=np.int32)
vector[: vector.shape[0] // 2] *= 0

obj = Interface(2, 2)
print("obj created")
start = time.time()
obj.numpy2eigen(vector)
print(time.time() - start)
result = obj.getObs()

# print(result)
