#include <bits/stdc++.h>
using namespace std;

int main()
{
	string arr[] = {"abc", "adf", "chicku", "bablu","aa", "bulbul", "swayang", "sanu", "padu"};
	int n = sizeof(arr)/sizeof(arr[0]);

	sort(arr, arr+n);

	cout << "\nArray after sorting using "
		"default sort is : \n";
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";

	return 0;
}

