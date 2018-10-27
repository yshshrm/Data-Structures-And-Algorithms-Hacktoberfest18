#include <bits/stdc++.h>
using namespace std;

// Kadane's Algorithm

//Largest Sum Contiguous Subarray

int maxSubArraySum(int a[], int size)
{
    int c=a[0],m=a[0];
	    
	    for(int i=1;i<size;i++){

            c=max(a[i],c+a[i]);
            m=max(m,c);
	        
	    }
    return m;
}

/*Driver program to test maxSubArraySum*/
int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}
