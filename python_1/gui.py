import sys
import Tkinter
import tkMessageBox

from dialog import Dialog, center_window
import power_method


class Application(Tkinter.Frame):

	'''
		Data invariant: This class is the GUI part
			of the power method calculation and is thus
			the 'main' entry point of the application
	'''

	def __init__(self, master = None):
		Tkinter.Frame.__init__(self, master)
		master.title('Caluclate dominant eigenvector')
		self.pack(fill = Tkinter.BOTH, expand = True)
		self.createWidgets()

	# Variable describing if user wants to use
	# NumPy library or not. This must be a 'global'
	# variable or the gui will display both options
	# as selected
	USE_NUMPY = None

	def exit(self):
		# Exit the program. Use escape or hit the Exit button
		sys.exit(1)

	def validate(self):
		# Fetch parameters from GUI elements and validate them

		size = self.param_entry_size.get()
		eps = self.param_entry_eps.get()

		try:
			if int(size) < 1:
				tkMessageBox.showinfo('Bad Input!',
					'Input size must be an integer > 0!')
				return
		except ValueError:
			tkMessageBox.showinfo('Bad Input!', 'Input size must be an integer > 0')
			return

		try:
			float(eps)
		except ValueError:
			tkMessageBox.showinfo('Bad Input!', 'Eps must be a float value!\nAccepted formats are: 1.0e-6, 0.005')
			return


		self.compute(int(size), float(eps), self.USE_NUMPY.get())


	def compute(self, size, eps, use_numpy):
		# Run the power iteration and display results on complete run
		Dialog(self, use_numpy, *power_method.calculate(size, eps, use_numpy))

	def createWidgets(self):
		# Create and arrange the gui elements
		# From top to bottom, the variables explain what
		# 	element of the GUI they control
		# Some elements must be decleared global to be accessible
		#	by the compute function. These start with 'self.'

		param_frame = Tkinter.LabelFrame(self, text = 'Parameters')
		param_frame.grid(row = 0, column = 0)

		param_label_size = Tkinter.Label(param_frame,
			text = 'Enter the size of the matrix:')
		param_label_size.grid(row = 1, column = 0)

		self.param_entry_size = Tkinter.Entry(param_frame)
		self.param_entry_size.insert(Tkinter.END, '9')
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
		self.USE_NUMPY.set(2) # Set default state as using NumPy

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

		option_cpp = Tkinter.Radiobutton(
			option_frame,
			variable = self.USE_NUMPY,
			value = 3)
		option_cpp.grid(row = 5, column = 1)

		option_label_cpp = Tkinter.Label(
			option_frame,
			text = 'C++')
		option_label_cpp.grid(row = 6, column = 1)


		self.button_compute = Tkinter.Button(self,
			text = 'Compute',
			command = self.validate)
		self.button_compute.grid(row = 7, column = 1)

		button_exit = Tkinter.Button(self,
			text = 'Exit',
			command = self.exit)
		button_exit.grid(row = 8, column = 1)


# Create window and center it in the middle for convenience
window = Tkinter.Tk()
center_window(window)

app = Application(master = window)
app.mainloop()
