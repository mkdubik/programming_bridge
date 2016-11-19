import Vector
a, b = Vector.iArray(), Vector.iArray()
a = [0, 1, 2, 3, 4]
b = [4, 3, 2, 1, 0]
k = Vector.iVector(a) * Vector.iVector(b)
k.write()