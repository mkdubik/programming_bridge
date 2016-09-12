from pprint import pprint
from copy import deepcopy
import random
import math
import time
import numpy as np

class power_method(object):

	@staticmethod
	def calculate(N, epsilon, method):
		assert(isinstance(N, (int, long)))
		assert(isinstance(epsilon, float))
		assert(isinstance(method, basestring))

		if method == 'NumPy':
			start = time.time()
			return power_method._numpy(N, epsilon), time.time() - start

		start = time.time()
		return power_method._normal(N, epsilon), time.time() - start

	@staticmethod
	def _normal(N, epsilon):
		#A, x0, N = [[2.0, -12.0], [1.0, -5.0]], [[1.0], [1.0]], 2
		#A, x0, N = [[1.0, 1.0], [0.0, -1.0]], [[1.0], [1.0]], 2
		#A, x0, N = [[6.0, 3.0, 2.0], [7.0, 2.0, 3.0], [5.0, 5.0, 1.0]], [[1.0], [1.0], [1.0]], 3

		A, x0 = [], []
		for i in xrange(N):
			A.append([float(random.randint(-100, 100)) for x in xrange(N)])
			x0.append([1.0])

		xk, yk = deepcopy(x0), deepcopy(x0)

		for i in xrange(100000):
			# Dot product
			for j in xrange(N):
				yk[j][0] = 0.0
				for k in xrange(N):
					yk[j][0] += A[j][k] * x0[k][0]

			norm_max_yk = max(yk)[0]

			for j in xrange(N):
				xk[j][0] = yk[j][0] / norm_max_yk

			error = math.sqrt(math.pow(sum([xk[j][0] - x0[j][0] for j in xrange(N)]) , 2) / N)

			if error < epsilon:
				return xk, i

			x0 = deepcopy(xk)

	@staticmethod
	def _numpy(N, epsilon):
		#A, x0 = np.array([[2, -12], [1, -5]]), np.ones(2).transpose()
		#A, x0 = np.array([[1, 1], [0, -1]]), np.ones(2).transpose()
		#A, x0 = np.array([[6, 3, 2], [7, 2, 3], [5, 5, 1]]), np.ones(3).transpose()
		A, x0 = np.random.randint(-100, 100, (N,N)), np.ones(N).transpose()
		for i in xrange(100000):
			yk = A.dot(x0)
			xk = yk / max(yk)
			error = np.sqrt(np.power((np.sum(xk - x0)), 2)/2)

			if error < epsilon:
				return xk, i

			x0 = xk

if __name__ == '__main__':
	# This block only used for testing
	import argparse
	parser = argparse.ArgumentParser()
	parser.add_argument('n', const = 2, type = int, nargs = '?')
	parser.add_argument('eps', const = 0.0006, type = float, nargs = '?')
	parser.add_argument('numpy', const = False, type = str, nargs = '?')
	args = parser.parse_args()

	#print power_method.calculate(args.n, args.eps, 'NumPy')
	print power_method.calculate(args.n, args.eps, args.numpy)
