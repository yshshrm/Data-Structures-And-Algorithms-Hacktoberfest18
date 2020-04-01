// Problem Statement: https://practice.geeksforgeeks.org/problems/modular-exponentiation-for-large-numbers/0

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long mod_exponentiation(long long A, long long B, long long C){
    if(B==0){
        return 1;
    }
    else{
        return (A*mod_exponentiation(A, B-1, C))%C;
    }
}

int main() {
  // Enter number of test cases
	int T=0;
	cin>>T;
	
  // Enter the three numbers -> pow(A,B)%C for each test case
	for(int i=0; i<T; i++){
	    long long A=0, B=0, C=0;
	    cin>>A>>B>>C;
	    cout<<mod_exponentiation(A, B, C)<<endl;
	}
	return 0;
}
