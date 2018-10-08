//Function to calculate the maximum sum of a sub-array of a given array
#include<stdio.h>
int maxSumarray(int a[], int size){
    int i;
    int max_sum_so_far=0;
    int max_ending_here = 0;
    for(i=0;i<size;i++){
    	max_ending_here = max_ending_here + a[i];
        if(max_ending_here < 0){
        	max_ending_here =0;
		}
		if(max_sum_so_far < max_ending_here){
			max_sum_so_far = max_ending_here;
		}
	}
	return max_sum_so_far;
}

//Driver program to test above function
int main(){
	int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int size = sizeof(a)/sizeof(a[0]);
	printf("Given array is \n"); 
	for(int i=0;i<size;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	int max_sum = maxSumarray(a,size);
	printf("The Maximum Sum of the Sub Array is : %d\n",max_sum);
	return 0;
}
