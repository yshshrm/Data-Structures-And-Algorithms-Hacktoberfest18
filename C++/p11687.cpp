#include<bits/stdc++.h>
using namespace std;

int Count(int t)
{
	int c=0;
	while(t)
	{
		t/=10;
		c++;
	}
	return c;
}

int get(int a,int n)
{
	int c1=Count(a);

	if(c1==a)
		return n+1;

	return get(c1,n+1);
}

int main()
{
	string S;
	while(cin>>S, S!="END")
	{
		int a=S.length();
		if(a==1&&a==stoi(S))
			printf("1\n");
		else
			printf("%d\n",get(a,1));
	}
}
