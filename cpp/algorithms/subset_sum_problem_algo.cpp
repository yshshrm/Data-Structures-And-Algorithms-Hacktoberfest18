	//In subset sum problem we are given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum
	
	#include <bits/stdc++.h>
	using namespace std;
	 
	  
	// checking if there is a subset of set[] with sun equal to given sum 
	bool isSubsetSum(int a[], int n, int sum) 
	{ 
	   // Base Cases 
	   if (sum == 0) 
	     return true; 
	   if (n == 0 && sum != 0) 
	     return false; 
	  
	   // If last element is greater than sum, then ignore it 
	   if (a[n-1] > sum) 
	     return isSubsetSum(a, n-1, sum); 
	  
	   /* else, check if sum can be obtained by any of the following 
	      (a) including the last element 
	      (b) excluding the last element   */
	   return isSubsetSum(a, n-1, sum) ||  
	                        isSubsetSum(a, n-1, sum-a[n-1]); 
	} 
	  
	
	int main() 
	{ 
	//n is no. of elements you want to insert
	 int n;
	 cin>>n;
	 int a[n];
	 cout<<"enter array elemets"<<endl;
	 for(int i=0;i<n;i++)
	 cin>>a[i];
	 cout<<"enter sum u want to check:\t";
	  int sum;
	  cin>>sum; 
	  if (isSubsetSum(a, n, sum) == true) 
	     printf("Found a subset with given sum"); 
	  else
	     printf("No subset with given sum"); 
	  return 0; 
	} 
