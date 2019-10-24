#include<iostream>

using namespace std;

int fact(int n)
{
	
	if(n==1 || n==0)
		return 1;
	else
		return (n*fact(n-1));
}

int main()
{   int m;
    cin>>m;
	int result = fact(m);
	cout<<result;
}