/*

	You are given two integers N and i. You need to make ith bit of binary representation of N to 1 and return the updated N.
	Counting of bits start from 0 from right to left.

	Input Format :
	Two integers N and i (separated by space)

	Output Format :
	Updated N

	Sample Input 1 :
	4 1
	Sample Output 1 :
	6

*/

#include<iostream>
using namespace std;

int turnOnIthBit(int n, int i){
   
  	return n | (1 << i);
  
}

int main()
{
	int N, i;
	cin >> N;
	cin >> i;
	cout << turnOnIthBit(N, i) << endl;
}



