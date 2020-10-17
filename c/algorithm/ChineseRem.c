#include <stdio.h>
#include <stdlib.h>

int findMin(int num[],int rem[],int k);

int findMin(int num[],int rem[],int k){
	int p=1;
	while(1){
		int j;
		for(j=0;j<k;j++){
			if(p%num[j]!=rem[j]){
				break;
			}
		}
		
		if(j==k){
			return p;
		}
		p++;
	}
	return p;
}

int main(){
	printf("Enter the number of enteries: ");
	int n;scanf("%d",&n);
	int num[n],rem[n];
	printf("Enter the  numbers: ");
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	printf("Enter the respective remainders: ");
	for(int i=0;i<n;i++){
		scanf("%d",&rem[i]);
	}
	int k = sizeof(num)/sizeof(num[0]);
	printf("The minimum number will be: %d\n",findMin(num,rem,k));	
	return 0;
}
