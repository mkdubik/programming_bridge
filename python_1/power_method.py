import copy
import random
import math
import time

import numpy as np

def calculate(N, epsilon, use_numpy):
	# Main entry point for the calculation
	# Decide here to use NumPy or not and
	#	make sure the arguments are of the right type
	assert(isinstance(N, (int, long)))
	assert(isinstance(epsilon, float))
	assert(isinstance(use_numpy, bool))

	if use_numpy:
		start = time.time()
		A, xk, i = _numpy(N, epsilon)
		return A, xk, i, time.time() - start,

	start = time.time()
	A, xk, i = _normal(N, epsilon)
	return A, xk, i, time.time() - start

def _normal(N, epsilon):
	# Non-NumPy power iteration
	# Return None if iterations time out
	# Some example iterations are commented out for easy testing
	#A, x0, N = [[2.0, -12.0], [1.0, -5.0]], [[1.0], [1.0]], 2
	#A, x0, N = [[1.0, 1.0], [0.0, -1.0]], [[1.0], [1.0]], 2
	#A, x0, N = [[6.0, 3.0, 2.0], [7.0, 2.0, 3.0], [5.0, 5.0, 1.0]], [[1.0], [1.0], [1.0]], 3

	# Initialize matrix with random values and eigenvector with ones
	A, x0 = [], []
	for i in xrange(N):
		A.append([random.random() for x in xrange(N)])
		x0.append([1.0])

	# I use deepcopy for convenience to get the same size
	xk, yk = copy.deepcopy(x0), copy.deepcopy(x0)

	for i in xrange(10000):
		# Calculate the dot product
		for j in xrange(N):
			yk[j][0] = 0.0
			for k in xrange(N):
				yk[j][0] += A[j][k] * x0[k][0]

		norm_max_yk = max(yk)[0]

		# xk = yk / max(yk)
		for j in xrange(N):
			xk[j][0] = yk[j][0] / norm_max_yk

		# Use formula provided by assignment to calculate solution
		eps = math.sqrt(
			math.pow(sum([xk[j][0] - x0[j][0] for j in xrange(N)]) , 2) / N)

		if eps < epsilon:
			return A, xk, i

		# Update eigenvector for further iteration
		x0 = copy.deepcopy(xk)
	return A, None, i

def _numpy(N, epsilon):
	# NumPy power iteration
	# Return None if iterations time out
	# Some example iterations are commented out for easy testing

	#A, x0, N = np.array([[2, -12], [1, -5]]), np.ones(2).transpose(), 2
	#A, x0, N = np.array([[1, 1], [0, -1]]), np.ones(2).transpose(), 2
	#A, x0, N = np.array([[6, 3, 2], [7, 2, 3], [5, 5, 1]]), np.ones(3).transpose(), 3

	# Initialize matrix with random values and eigenvector with ones
	# Algorithm implemented exactly like in the assignment
	A, x0 = np.random.random((N,N)), np.ones(N).transpose()
	for i in xrange(10000):
		yk = A.dot(x0)
		xk = yk / max(yk)

		eps = np.sqrt(np.power((np.sum(xk - x0)), 2) / N)

		if eps < epsilon:
			return A, xk, i

		x0 = xk
	return A, None, i

if __name__ == '__main__':
	# This block only used for testing
	# It is possible to run this program without GUI
	import argparse
	parser = argparse.ArgumentParser()
	parser.add_argument('n', const = 2, type = int, nargs = '?')
	parser.add_argument('eps', const = 0.0006, type = float, nargs = '?')
	parser.add_argument('numpy', const = False, type = str, nargs = '?')
	args = parser.parse_args()
	print calculate(args.n, args.eps, args.numpy)
