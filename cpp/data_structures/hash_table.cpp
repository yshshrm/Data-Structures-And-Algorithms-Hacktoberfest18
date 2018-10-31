#include <bits/stdc++.h>

struct pair
{
	int key;
	int value;
};

void insert(struct pair* table, int max, int k, int v)
{
	while (table[k % max].key)
		k = (k + 1) % max;

	table[k % max].key = k;
	table[k % max].value = v;
}

bool keyExists(struct pair* table, int max, int k)
{
	if (table[k % max].key) {
		while (table[k % max].key && table[k % max].key != k)
			k = (k + 1) % max;

		return (k == max);
	}
	return false;
}

int main()
{
	struct pair table[100] = {};
	insert(table, 100, 1, 2);
	cout << keyExists(table, 100, 1) << endl;
	return 0;
}
