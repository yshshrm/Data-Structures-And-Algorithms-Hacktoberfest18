#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int arr[n], s=0, d=0, count =0, l=0, r=n-1;
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	while(l < r+1){
		count++;
		if (arr[l] < arr[r]){
			if (count%2)
				s+=arr[r];
			else
				d+=arr[r];
			r--;
		} else {
			if (count%2)
				s+=arr[l];
			else
				d+=arr[l];
			l++;
		}
	}

	cout<<s<<" "<<d<<endl;
	return 0;
}