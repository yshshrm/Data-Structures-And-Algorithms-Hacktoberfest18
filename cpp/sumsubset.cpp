#include<iostream>
using namespace std;

// k = sum, s = sum till now, r = remaining sum, x = number included or not

void sumSubsetToK(int a[], int x[], int s, int i, int r, int n, int k)
{
	x[i] = 1;

	if(s + a[i] == k)
	{
		cout<<"{";
		for (int j = 0; j <= i; ++j)
			if(x[j] == 1)
			{
				cout << a[j];
				if(j !=i)   cout << ", ";
			}
		
		cout << "}\n";
		return;
	}

	else if(s + a[i] + a[i+1] <= k)
	{
		sumSubsetToK(a, x, s + a[i], i+1, r - a[i], n, k);
	}

	if( (r - a[i] >=  k - s) && ( s + a[i+1] <= k) )
	{
		x[i] = 0;
		sumSubsetToK(a, x, s, i+1, r - a[i], n, k);
	} 

}

int main()
{
	int n = 9, sum = 0, k;
	int a[n] = {7, 8, 10, 13, 15, 19, 20, 23, 25};
	int x[n];

	cout << "This is your set: {5, 10, 12, 13, 15, 18} \nEnter a number: ";
	cin >> k;

	cout << "The subsets whose sum is "<<k <<" are:\n";

	for (int i = 0; i < n; ++i)
		sum += a[i];

	sumSubsetToK(a, x, 0, 0, sum, n, k );
}