#Implement power method here, accept command line input
# and spit out value
from __future__ import division
from pprint import pprint
from pdb import set_trace
from copy import deepcopy

class power_method(object):

	@staticmethod
	def calculate(N, epsilon, method):
		# result size is mxn * nxp = mxp

		matrix = [[2, -12], [1, -5]]

		result, eigenvector = [], []

		for i in xrange(2):
			result.append([1])
			eigenvector.append([1])

		approximation = deepcopy(eigenvector)

		for i in xrange(6):
			# Dot product
			for j in xrange(len(matrix)):
				tmp = 0
				for k in xrange(len(eigenvector)):
					tmp += matrix[j][k] * eigenvector[k][0]

				result[j] = [tmp]




			eigenvector = deepcopy(result)

			for j, x in enumerate(eigenvector):
				approximation[j][0] = eigenvector[j][0] / eigenvector[-1][0]

			print eigenvector


if __name__ == '__main__':
	power_method.calculate(3, 0.00006, 'Normal')


