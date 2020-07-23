#include<bits/stdc++.h>
using namespace std;

int bsort(int *arr, int n){
	int countx=0;
	bool swapped = true;

	while(swapped){
		swapped = false;
		countx++;
		for (int i = 1; i < n; ++i)
		{
			if (arr[i] > arr[i+1])
			{
				swap(arr[i], arr[i+1]);
				swapped = true;
			}
		}
	}
	return countx;
}

main(){
	int n;
	scanf("%d", &n);
	int arr[n];
	for(int i=0; i<n; i++)
		scanf("%d", &arr[i]);

	cout<<bsort(arr,n)<<endl;
}
