#Implement GUI in here. Discard command line input and call power method
import Tkinter
import power_method
import sys
from pdb import set_trace

class Application(Tkinter.Frame):

	def __init__(self, master = None):
		Tkinter.Frame.__init__(self, master)
		master.bind("<Escape>", self.exit)
		master.title('Caluclate largest eigenvalue')
		self.pack(fill = Tkinter.BOTH, expand = True)
		self.createWidgets()

	# Variable describing if user wants to use
	# NumPy library or not. This must be a 'global'
	# variable or the gui will display both options
	# as selected
	USE_NUMPY = None

	def exit(self, arg):
		# Exit the application
		#self.destroy()
		sys.exit(1)

	def compute(self):
		# Compute
		solution, eigenvalue, eigenvector, time = power_method.calculate()
		print "hi there, everyone!"

	def validate_int(self, arg):
		print 'validating'
		return True

	def createWidgets(self):
		# Create and arrange the gui elements
		param_frame = Tkinter.LabelFrame(self, text = 'Parameters')
		param_frame.pack()

		param_label_size = Tkinter.Label(param_frame,
			text = 'Enter the size of the matrix:')
		param_label_size.pack()

		param_entry_size = Tkinter.Entry(param_frame,
			validatecommand = self.validate_int)
		param_entry_size.insert(Tkinter.END, '100')
		param_entry_size.focus()
		param_entry_size.pack()

		param_label_size = Tkinter.Label(param_frame, text = 'Epsilon:')
		param_label_size.pack()

		param_entry_eps = Tkinter.Entry(param_frame)
		param_entry_eps.insert(Tkinter.END, '1-e6')
		param_entry_eps.pack()

		self.USE_NUMPY = Tkinter.IntVar()
		self.USE_NUMPY.set(1) # Set default state as NumPy

		option_frame = Tkinter.LabelFrame(self, text = 'Method:')
		option_frame.pack()

		option_numpy = Tkinter.Radiobutton(
			option_frame,
			variable = self.USE_NUMPY,
			value = 1)
		option_numpy.pack()

		option_label_numpy = Tkinter.Label(option_frame, text = 'NumPy')
		option_label_numpy.pack()

		option_notnumpy = Tkinter.Radiobutton(
			option_frame,
			variable = self.USE_NUMPY,
			value = 2)
		option_notnumpy.pack()

		option_label_notnumpy = Tkinter.Label(option_frame,
			text = 'Not NumPy')
		option_label_notnumpy.pack()

		button_compute = Tkinter.Button(self,
			text = 'Compute',
			command = self.compute)
		button_compute.pack()

		button_exit = Tkinter.Button(self,
			text = 'Exit',
			command = self.exit)
		button_exit.pack()

window = Tkinter.Tk()

# TODO: Use for debugging, remove for production
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
