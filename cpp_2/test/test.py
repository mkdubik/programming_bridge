from Cpppy import iVector
from Cpppy import iArray

a, b = iArray([0, 1, 2, 3, 4]), iArray([4, 3, 2, 1, 0])

ai = iVector(a)
bi = iVector(b)

k = ai * bi

print k

