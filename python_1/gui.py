import Tkinter
import tkMessageBox
import sys

import power_method

from pdb import set_trace

class Application(Tkinter.Frame):

	def __init__(self, master = None):
		Tkinter.Frame.__init__(self, master)
		master.bind("<Escape>", sys.exit)
		master.title('Caluclate dominant eigenvector')
		self.pack(fill = Tkinter.BOTH, expand = True)
		self.createWidgets()

	# Variable describing if user wants to use
	# NumPy library or not. This must be a 'global'
	# variable or the gui will display both options
	# as selected
	USE_NUMPY = None

	def exit(self):
		sys.exit(1)

	def compute(self):
		_, xk, iterations, time = power_method.calculate(int(self.param_entry_size.get()),
										float(self.param_entry_eps.get()),
										'NumPy' if self.USE_NUMPY.get() == 1 else 'Normal')
		if xk is None:
			tkMessageBox.showinfo('Complete', 'The matrix {matrix} did not converge within {iterations} iterations with time {time}'.format(
				matrix = int(self.param_entry_size.get()), result = xk, iterations = iterations, time = time))
		else:
			tkMessageBox.showinfo('Complete', 'The matrix {matrix} gave the result {result} with {iterations} iterations with time {time}'.format(
				matrix = int(self.param_entry_size.get()), result = xk, iterations = iterations, time = time))

	def createWidgets(self):
		# Create and arrange the gui elements
		param_frame = Tkinter.LabelFrame(self, text = 'Parameters')
		param_frame.grid(row = 0, column = 0)

		param_label_size = Tkinter.Label(param_frame,
			text = 'Enter the size of the matrix:')
		param_label_size.grid(row = 1, column = 0)

		self.param_entry_size = Tkinter.Entry(param_frame)
		self.param_entry_size.insert(Tkinter.END, '100')
		self.param_entry_size.focus()
		self.param_entry_size.grid(row = 2, column = 0)

		param_label_size = Tkinter.Label(param_frame, text = 'Epsilon:')
		param_label_size.grid(row = 3, column = 0)

		self.param_entry_eps = Tkinter.Entry(param_frame)
		self.param_entry_eps.insert(Tkinter.END, '1.0e-6')
		self.param_entry_eps.grid(row = 4, column = 0)


		self.computation_status = Tkinter.Label(self, text = '')
		self.computation_status.grid(row = 5, column = 0)


		self.USE_NUMPY = Tkinter.IntVar()
		self.USE_NUMPY.set(1) # Set default state as NumPy

		option_frame = Tkinter.LabelFrame(self, text = 'Method:')
		option_frame.grid(row = 0, column = 1, padx = 20)

		option_numpy = Tkinter.Radiobutton(
			option_frame,
			variable = self.USE_NUMPY,
			value = 1)
		option_numpy.grid(row = 1, column = 1)

		option_label_numpy = Tkinter.Label(option_frame, text = 'NumPy')
		option_label_numpy.grid(row = 2, column = 1)

		option_notnumpy = Tkinter.Radiobutton(
			option_frame,
			variable = self.USE_NUMPY,
			value = 2)
		option_notnumpy.grid(row = 3, column = 1)

		option_label_notnumpy = Tkinter.Label(option_frame,
			text = 'Not NumPy')
		option_label_notnumpy.grid(row = 4, column = 1)

		self.button_compute = Tkinter.Button(self,
			text = 'Compute',
			command = self.compute)
		self.button_compute.grid(row = 5, column = 1)

		button_exit = Tkinter.Button(self,
			text = 'Exit',
			command = self.exit)
		button_exit.grid(row = 6, column = 1)

window = Tkinter.Tk()

def center_window(width=300, height=200):
	# get screen width and height
	screen_width = window.winfo_screenwidth()
	screen_height = window.winfo_screenheight()

	# calculate position x and y coordinates
	x = (screen_width/2) - (width/2) + 600
	y = (screen_height/2) - (height/2)
	window.geometry('%dx%d+%d+%d' % (width, height, x, y))

center_window()

app = Application(master = window)
app.mainloop()
