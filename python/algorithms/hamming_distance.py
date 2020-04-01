#!/usr/bin/env python

# Calculate the hamming distance of two strings - the number of positions with mismatching characters

def hamming_distance(a, b):
	# Check if the two strings have the same length, if not return False and don't calculate
	if len(a) != len(b):
		return False

	diff = 0

	for c1, c2 in zip(a, b):
		if c1 != c2:
			diff += 1

	return diff

def main():
	a = "ATGCATCG"
	b = "AAGCCTCC"

	print hamming_distance(a, b)

if __name__ == '__main__':
	main()
