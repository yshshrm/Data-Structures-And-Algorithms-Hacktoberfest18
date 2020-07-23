#include<bits/stdc++.h>
using namespace std;

main(){
	int n,k;
	scanf("%d %d", &n, &k);
	int arr[n], flag=0;
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}

	for(int i=0; i<n; i++){
		if(arr[i]>0 && arr[i] >=arr[k-1])
			flag++;
	}
	cout<<flag;
}