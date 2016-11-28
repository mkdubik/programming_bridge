import copy
import random
import math
import time

import numpy as np

try:
	import Cpppy as cp
	# If we need random numbers,
	# we must seed in the C++ world once
	cp.seed_random()
except ImportError:
	cp = None
	import traceback
	traceback.print_exc()

def calculate(N, epsilon, method):
	# Main entry point for the calculation
	# Decide here to use NumPy or not and
	#	make sure the arguments are of the right type
	assert(isinstance(N, (int, long)))
	assert(isinstance(epsilon, float))
	assert(isinstance(method, int))
	dispatch_table = {
		1: _normal,
		2: _numpy,
		3: _cpppy
	}
	return dispatch_table[method](N, epsilon)

def _normal(N, epsilon, profiler_matrix = None):
	# Non-NumPy power iteration
	# Return None if iterations time out

	# Initialize matrix with random values and eigenvector with ones
	A, x0 = [], []
	for i in xrange(N):
		A.append([random.random() for x in xrange(N)])
		x0.append([1.0])

	# This is used for profiling when we want to test the same matrix
	# on two methods
	if profiler_matrix is not None:
		A = profiler_matrix
		x0 = [[1.0] for x in xrange(len(profiler_matrix))]

	# I use deepcopy for convenience to get the same size
	xk, yk = copy.deepcopy(x0), copy.deepcopy(x0)

	# Don't profile preparation
	t1 = time.time()
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
			return A, xk, i, time.time() - t1

		# Update eigenvector for further iteration
		x0 = copy.deepcopy(xk)
	return A, None, i, time.time() - t1

def _numpy(N, epsilon, profiler_matrix = None):
	# NumPy power iteration
	# Return None if iterations time out
	# Some example iterations are commented out for easy testing

	# Initialize matrix with random values and eigenvector with ones
	A, x0 = np.random.random((N,N)), np.ones(N).transpose()


	# This is used for profiling when we want to test the same matrix
	# on two methods
	if profiler_matrix is not None:
		A = np.array(profiler_matrix)
		x0 = np.ones(len(profiler_matrix)).transpose()

	# Algorithm implemented exactly like in the assignment
	# Don't profile preparation
	t1 = time.time()
	for i in xrange(10000):
		yk = A.dot(x0)
		xk = yk / max(yk)
		eps = np.sqrt(np.power((np.sum(xk - x0)), 2) / N)

		if eps < epsilon:
			return A, xk, i, time.time() - t1

		x0 = xk
	return A, None, i, time.time() - t1

def _cpppy(N, epsilon, profiler_matrix = None):
	# C++ power iteration
	# Return None if iterations time out
	# Some example iterations are commented out for easy testing
	# Initialize matrix with random values and eigenvector with ones

	def sub(a, b):
		tmp = []
		for i in xrange(len(a)):
			tmp.append(a[i] - b[i])
		tmp = cp.dArray(tmp)
		return cp.dVector().set_vector(tmp)

	if cp is None:
		print 'C++ module import failed, function unavailable'
		return _, _, _, _

	# Commented out special test cases
	A, x0 = cp.dMatrix.random(N, N), cp.dVector.ones(N)

	# This is used for profiling when we want to test the same matrix w/ different methods
	if profiler_matrix is not None:
		A = cp.dMatrix()
		[A.push(cp.dVector.set_vector(cp.dArray(pv))) for pv in profiler_matrix]

	# Don't profile preparation
	t1 = time.time()
	for i in xrange(10000):
		yk = A * x0
		xk = yk / yk.vmax()

		eps_k = sub(xk, x0)
		eps = cp.vsqrt(cp.vpow((eps_k.vsum()), 2) / N)

		if eps < epsilon:
			return A, xk, i, time.time() - t1

		x0 = xk
	return A, None, i, time.time() - t1

if __name__ == '__main__':
	# This block only used for testing
	# It is possible to run this program without GUI
	from pdb import set_trace
	from pprint import pprint
	import argparse
	parser = argparse.ArgumentParser()
	parser.add_argument('n', const = 2, type = int, nargs = '?')
	parser.add_argument('eps', const = 0.0006, type = float, nargs = '?')
	parser.add_argument('numpy', const = False, type = str, nargs = '?')
	args = parser.parse_args()

	N = args.n
	A, eps = [], 0.000006
	for i in xrange(N):
		A.append([random.random() for x in xrange(N)])

	print 'For N = %s' % N

	A = [[1, 1], [0, -1]]
	A, xk, i, t = _numpy(N, eps, A)
	print 'NumPy finished running in %s' % (t)
	print xk, i

	#A, xk, i, t = _normal(N, eps, A)
	#print 'Non-NumPy finished running in %s' % (t)
	A, xk, i, t = _cpppy(N, eps, A)
	print 'C++ finished running in %s ' % (t)
	print xk, i