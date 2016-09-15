import sys
import Tkinter

from pdb import set_trace


def center_window(window, width = 300, height = 200):
	# This function has inspiration from this stack overflow answer:
	# http://stackoverflow.com/questions/14910858/how-to-specify-where-a-tkinter-window-opens

	# get screen width and height
	screen_width = window.winfo_screenwidth()
	screen_height = window.winfo_screenheight()

	# calculate position x and y coordinates
	x = (screen_width/2) - (width/2) + 600
	y = (screen_height/2) - (height/2)
	window.geometry('%dx%d+%d+%d' % (width, height, x, y))

class Dialog:

	'''
		Data invariant: This class is the information GUI dialog
			of a complete power iteration run. It displays useful
			information such as the input matrix, the dominant Eigenvector
			the total number of iterations to reach it and
			time spent in computation

			The print formatting is incredibly complex since the python
				datatypes do not play well with with the NumPy ones.
				For example a column vector is a 2d list in python
				but numpy will still treat it like a row vector.
				Multiple functions were defined to deal with this problem
				and the size of the vector
	'''


	def __init__(self, parent, use_numpy, A, xk, iterations, time):
		# Create and arrange the gui elements from top to bottom
		top = self.top = Tkinter.Toplevel(parent)

		# Find the right size for the result here
		if len(A) > 10:
			height, width = 800, 400
		else:
			if len(A) > 5:
				height, width = len(A) * 80, len(A) * 45
			else:
				height, width = 450, 250

		center_window(top, height, width)

		top.title('Result')

		A, xk = self.prepare_data_for_display(A, xk, use_numpy)

		Tkinter.Label(top, text = 'Input matrix:').grid(row = 0, column = 0)
		Tkinter.Label(top, text = A).grid(row = 0, column = 1)

		Tkinter.Label(top, text = 'Dominant Eigenvector:').grid(row = 1, column = 0)
		Tkinter.Label(top, text = xk).grid(row = 1, column = 1)

		Tkinter.Label(top, text = 'Iterations').grid(row = 2, column = 0)
		Tkinter.Label(top, text = str(iterations)).grid(row = 2, column = 1)

		Tkinter.Label(top, text = 'Time:').grid(row = 3, column = 0)
		Tkinter.Label(top, text = format(time, '.5')).grid(row = 3, column = 1)

		Tkinter.Button(top, text = 'OK', command = self.exit).grid(
			row = 4, column = 0, pady = 5)

	def prepare_data_for_display(self, A, xk, use_numpy):
		# Entry point to format the data for display
		xk_str = 'No solution was found for input matrix'
		if len(A) > 10:
			if xk is not None:
				xk_str = self.format_large_numpy_vector(xk) if use_numpy else self.format_large_matrix(xk)
			return self.format_large_matrix(A), xk_str

		if xk is not None:
			xk_str = '\n'.join(str(x) for x in xk) if use_numpy else self.format_matrix(xk)

		return self.format_matrix(A), xk_str

	def format_matrix(self, A):
		# Format smaller matrixes be it python 2d matrix, python column vector
		# or a NumPy Matrix
		Astr = [[format(col, '.5f') for col in row] for row in A]
		return '\n'.join(' '.join(col for col in row) for row in Astr)

	def format_large_matrix(self, A):
		# Format a large matrix here, be it python 2d matrix, python column vector
		# or a NumPy Matrix
		num = 10
		Astr = ''
		for x in xrange(10):
			if len(A[x]) == 1:
				num = 1
			for y in xrange(num):
				Astr += format(A[x][y], '.5f') + ' '
			Astr = Astr[:-1]
			if num != 1:
				Astr += ' ...'
			Astr += '\n'
		return Astr[:-1] + '\n...'

	def format_large_numpy_vector(self, xk):
		# Format large NumPy vector here
		xk_str = ''
		for x in xrange(10):
			xk_str += format(xk[x], '.5f') + '\n'
		return xk_str + '...'

	def exit(self):
		self.top.destroy()
