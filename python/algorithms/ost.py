# Implementing the problem of Optimal Storage on a single Tape in Python

def ost(lengths):
	l = len(lengths)
	lengths.sort()
	t = [0 for i in range(l)]

	for i in range(l):
		for j in range(i+1):
			t[j] = t[j] + lengths[j]

	mrt = sum(t) / l;
	print('Order to store programs: ', ','.join(map(str, lengths)))
	print('Mean Retrieval Time: ', str(mrt))

L = [int(x) for x in input('Enter the length of programs: ').split()]

ost(L)
