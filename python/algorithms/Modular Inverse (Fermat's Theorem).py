'''input
8
17
'''

#~ @author = dwij28 (Abhinav Jha) ~#

def inv(n, mod): # mod is prime
	return pow(n, mod-2, mod)

n, mod = input(), input()
print inv(n, mod)