#include <bits/stdc++.h>

using namespace std;

void reverse(int *arr, int start, int end)
{
	cout << start << " "<<end<<endl;
	for(int i = 0; i <= (end-start)/2 ; i++)
	{
		int temp = arr[i+start];
		arr[i+start] = arr[end-i];
		arr[end-i] = temp;
	}
		for (int i = 0; i <= 19; ++i)
		cout <<arr[i] << " ";
}

void rotate(int *arr, int n, int l)
{
	reverse(arr, 0, l-1);
	cout << endl;
	reverse(arr, l, n-1);
	cout << endl;
	reverse(arr, 0, n-1);
}

int main()
{
	int n, l;
	cin >> n >> l;
	int a[n];

	for (int i = 0; i < n; ++i)
		cin >> a[i];
	
	rotate(a,n,l);

	cout << endl;
	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";

}