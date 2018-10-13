#include <stdbool.h>

bool is_sorted(int *a, size_t n) {
	// checks whether a given int array a of size n is nondecreasing
	for (size_t i = 0; i < n - 1; i++)
		if (a[i] > a [i+1])
			return false;
	return true;
}
