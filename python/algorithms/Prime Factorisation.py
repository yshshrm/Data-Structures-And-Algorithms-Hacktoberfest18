# Program for finding prime factorisation of any number.

import math

def primeFactorisation(n):
	lst = []
	while n % 2 == 0:
		lst.append(2)
		n /= 2
	for i in range(3, int(math.sqrt(n))+1, 2):
		while n % i == 0:
			lst.append(i)
			n /= i
	if n > 2:
		lst.append(int(n))
	return lst

def main():
	print("Enter any number: ")
	n = int(input())
	lst = primeFactorisation(n)
	print("Prime factorisation of %d is: " % n)
	for x in sorted(set(lst)):
		print("%d^%d" % (x, lst.count(x)), end= " ")

if __name__ == '__main__':
	main()
