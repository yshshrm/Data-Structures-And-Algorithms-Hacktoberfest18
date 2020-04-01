#include <bits/stdc++.h>
using namespace std;
void exchange(int *m, int *n)
{
	int temp = *m;
	*m = *n;
	*n = temp;
}
void max_heapify(int a[], int i, int n)
{
	int l = 2*i+1, r = 2*i+2;
	int largest;
	if(l<n&&a[l]>a[i])
	{
		largest = l;
	}
	else largest = i;
	if (r<n&&a[r]>a[largest])
	{
		largest = r;
	}
	if(largest!=i)
	{
		exchange(&a[i], &a[largest]);
		max_heapify(a, largest, n);
	}
}
void build_max_heap(int a[], int n)
{
	for (int i = n/2; i >=0; --i)
	{
		max_heapify(a, i, n);
	}
}
void heap_sort(int a[], int n)
{
	build_max_heap(a, n);
	for (int i = n-1; i >0 ; --i)
	{
		exchange(&a[0], &a[i]);
		n = n-1;
		max_heapify(a,0, n);
	}
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		cin>>a[i];
	}
	heap_sort(a,n);
	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
