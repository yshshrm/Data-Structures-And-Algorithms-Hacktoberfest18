#include<bits/stdc++.h>
using namespace std;
void convert(int A[]){
	int temp[6];
	memcpy(temp, A, 6*sizeof(int));
	sort(temp, temp+6);
	unordered_map<int,int> U;
	int val = 0;
	for(int i = 0; i<6; i++){
		U[temp[i]] = val++;
	}
	for(int i = 0; i<6; i++){
		A[i] = U[A[i]];
	}
}
int main(){
	int arr[] = {89,43,255,12,90,5};
	convert(arr);
	for(int i = 0; i<6; i++){
		cout << arr[i] << " ";
	}
}
