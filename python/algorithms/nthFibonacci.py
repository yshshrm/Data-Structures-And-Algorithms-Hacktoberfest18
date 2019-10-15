'''
Fast doubling method: https://www.hackerearth.com/practice/notes/fast-doubling-method-to-find-nth-fibonacci-number/

Fibonacci series: 0 1 1 2 3 ...
NthFibonacci(n, mod) -> int
mod: We find modulo of number (usually with 1e9+7) as it is too big.
'''

def NthFibonacci(n, mod):
	return int(NthFibonacciHelper(n, mod)[0])

def NthFibonacciHelper(n, mod):
	if not n:
		return (0, 1)
	else:
		a, b = NthFibonacciHelper(n // 2, mod)
		c = (a%mod * ((b*2)%mod - a%mod))%mod
		d = ((a%mod * a%mod)%mod + (b%mod * b%mod)%mod)%mod

		if not n&1:
			return (c, d)
		else:
			return (d, c + d)
