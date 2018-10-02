# This is written in Python 3.5.2

class Stack(object):

	# l is a list/tuple which can be used for initialization of the stack.
	# The value at the last index position is considered as the top of the stack.
	def __init__(self, l = []):
		self.stack = list(l)


	# Inserting a new value at the top of the stack.
	def push(self, x):
		self.stack.append(x)
		print(x, "pushed at the top of the stack.")


	# Deleting the value at the top of the stack.
	def pop(self):
		if len(self.stack) == 0:
			print("The stack is empty.")
			return
		temp = self.stack.pop()
		print("The value found at the top of the stack is", temp)
		return temp


	# Returning the value at the top of the stack without deleting it.
	def peek(self):
		if len(self.stack) == 0:
			print("The stack is empty.")
			return
		temp = self.stack[-1]
		print("The value found at the top of the stack is", temp)
		return temp


	# Clearing the entire stack
	def delete(self):
		self.stack = []


	# String representation of the stack class
	def __str__(self):
		return self.stack.__str__()
