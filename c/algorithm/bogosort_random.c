#include <time.h>
#include <stdlib.h>
#include <bool.h>

srand(time(NULL));

void swap (int *a, size_t n1, size_t n2) {
	// swaps the elements n1 and n2 of int array a
	int temp = a[n1];
	a[n1] = a[n2];
	a[n2] = temp;
}

void shuffle (int *a, size_t n) {
	// pseudo-randomizes the order of a given int array a of size n
	// warning: this only works for arrays of size smaller than RAND_MAX,
	// and the order of the array is not truely random
	size_t j;
	for (size_t i = 0; i < n; i++) {
		j = i + rand() % (n - i);
		if (j != i)
			swap(a, i, j);
	}
}

bool is_sorted(int *a, size_t n) {
	// checks whether a given int array a of size n is nondecreasing
	for (size_t i = 0; i < n - 1; i++)
		if (a[i] > a [i+1])
			return false;
	return true;
}

void bogosort(int* a, size_t n) {
	// sorts an int array a of size n using the random bogosort algorithm
	// warning: this only works for arrays of size smaller than RAND_MAX
	while (!is_sorted(a, n))
		shuffle(a, n);
}
