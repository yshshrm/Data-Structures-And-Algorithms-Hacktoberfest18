#include<bits/stdc++.h>

using namespace std;

map<int,int> f;

int fact(int n){

	if(n==1 || n==0)
		return 1;
	else if(f[n])
		return f[n];
	else
		return f[n]=n*fact(n-1);
}
int f[1000]=0;
f[0]=1;
long long myFact(int num)
{
	if(num>=0)
	{
		for(int i=0;i<num;i++)
			f[i]=i*f[i-1];
	}
	return f[num];
}
int main(){
	cout<<fact(5);
}
