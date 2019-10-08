// Problem Statement: https://practice.geeksforgeeks.org/problems/count-of-strings-that-can-be-formed-using-a-b-and-c-under-given-constraints/0

#include <iostream>
using namespace std;

void count_strings(int N){
    long long result = (N*N*N + 3*N + 2)/2;
    cout<<result<<endl;
}

int main() {
	// Enter number of test cases
	int T=0;
	
	cin>>T;
	
  // Enter N denoting the length of the string
	for(int i=0; i<T; i++){
	    int N=0;
	    cin>>N;
	    
	    count_strings(N);
	}
	return 0;
}
