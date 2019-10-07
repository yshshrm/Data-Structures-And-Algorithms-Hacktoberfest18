#include <stdio.h> 
#include <stdlib.h> 
#include <limits.h> 
    
// Find the maximum possible sum in arr[] auch that arr[m] is part of it 
int cross_sum(int arr[], int l, int m, int h) 
{ 
    // Include elements on left of mid. 
    int sum = 0; 
    int left_sum = INT_MIN; 
    for (int i = m; i >= 0; i--) 
    { 
        sum = sum + arr[i]; 
        if (sum > left_sum) 
          left_sum = sum; 
    } 
  
    // Include elements on right of mid 
    sum = 0; 
    int right_sum = INT_MIN; 
    for (int i = m+1; i <= h; i++) 
    { 
        sum = sum + arr[i]; 
        if (sum > right_sum) 
          right_sum = sum; 
    } 
  
    // Return sum of elements on left and right of mid 
    return left_sum + right_sum; 
} 
  
// Returns sum of maxium sum subarray in aa[l..h] 
int maxSubArraySum(int arr[], int l, int h) 
{ 
   // Base Case: Only one element 
   if (l == h) 
     return arr[l]; 
  
   // Find middle point 
   int m = (l + h)/2; 
  
  int max;
  
  int left = maxSubArraySum(arr, l, m);
  int right = maxSubArraySum(arr, m+1, h);
  
  if(left>right)
  	max=left;
  else
  	max=right;
  
  int cross = cross_sum(arr, l, m, h);
  
  if(cross>max)
  	max=cross;
  	
  return max;
} 

int main() 
{ 

	int n, i, *a;
	
	printf("Enter the size of the array:");
	scanf("%d",&n);
	a = (int *)malloc(n*sizeof(int));
	
	printf("Enter the elements of the array:");
	for(i=0;i<n;i++)
		scanf("%d", &a[i]);
	
	
	printf("\n\n");	
	
	int max_sum = maxSubArraySum(a, 0, n-1); 
   printf("Maximum contiguous sum is %d\n\n", max_sum); 

	
	return 0;
} 
