#include <stdio.h>

void Sieve(int num);

void Sieve(int num){
	int arr_prime[num+1];
	for(int i=0;i<num+1;i++){
		arr_prime[i]=1;
	}
	for(int p=2;p<=num;p++){
		if(arr_prime[p]==1){
			for(int i=p*2;i<=num;i+=p){
				arr_prime[i] = 0;
			}
		}
	}
	for(int i=2;i<=num;i++){
		if(arr_prime[i]==1){
			printf("%d ",i);
		}
	}
}

int main(){
	int n;printf("Enter the number: ");scanf("%d",&n);
	printf("Prime Nos. less than %d : ",n);
	Sieve(n);
	printf("\n");
	return 0;
}
