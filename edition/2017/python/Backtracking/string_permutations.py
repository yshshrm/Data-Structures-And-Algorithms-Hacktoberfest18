"""
Print all the string permutations using backtracking method.
"""
def permutations(string,index,size):

	if index == size:
		print ''.join(string)
		return

	for i in range(index,size):
		string[i], string[index] = string[index], string[i]
		permutations(string,index+1,size)
		string[i], string[index] = string[index], string[i]


string = raw_input()
string = list(string)
size = len(string)
print permutations(string,0,size)
