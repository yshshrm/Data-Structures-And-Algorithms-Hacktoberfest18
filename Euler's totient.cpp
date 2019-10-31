#include <iostream>
using namespace std;
int main()
{
	// Number of test cases
	int t;
	cin>>t;
	long arr[t];
	long largest = 0;
	for (int i=0;i<t;i++){
		cin>>arr[i];
		if (largest < arr[i]){
			largest = arr[i];
		}
	}

	long series[largest+1]; 
    for (long i=1; i<=largest; i++) 
        series[i] = i;
    // Create the series
    for (long p=2; p<=largest; p++) 
    { 
        // If series[i] is not computed already, 
        // then number i is prime 
        if (series[p] == p) 
        { 
            // value of a prime number i is 
            // always equal to i-1. 
            series[p] = p-1; 

            for (long i = 2*p; i<=largest; i += p) 
            {
               series[i] = (series[i]/p) * (p-1); 
            } 
        } 
    } 

    for (int i = 0; i<t; i++){
        // cout<<series[arr[i]];

        for (long j=1;j<=arr[i]; j++){
            cout<<series[j]<<" ";
        }
        cout<<endl;
    }
}
