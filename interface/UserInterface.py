"""Handles the UI"""
from tkinter import *

class UI:
	"""User Interface for Quote Adder"""

	def __init__(self):
		root = Tk()  # Create root widget.

		a = Label(root, fg="red", text="Hello, world!")  # Label widget as a child to the root.
		a.pack()  # Call pack on 'a'. It'll size and make visible.

		root.mainloop()