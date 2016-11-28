import Cpppy as cp

N = 10

dm = cp.dMatrix.random(N, N)
vv = cp.dVector.ones(N)

vresult = dm * vv
print vresult

vresult[1] = 20.0
print vresult[1]

print dm[1]
dm[1] = cp.dVector.set_vector(cp.dArray([10, 10, 10, 10, 10, 10, 10 ,10, 10, 10]))


