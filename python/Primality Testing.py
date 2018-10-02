# Program for checking whether given number is a prime or not(Primality Testing) in O(sqrt(n)).

import math

def isPrime(n):
	if n < 2:
		return False
	if n == 2:
		return True
	if(n % 2 == 0):
		return false
	for i in range(3, int(math.sqrt(n)), 2):
		if n % i == 0:
			return False
	return True

def main():
	print("Enter any number: ")
	n = int(input())
	if isPrime(n):
		print("It is a prime number.")
	else:
		print("It's not a prime number!")

if __name__ == '__main__':
	main()
