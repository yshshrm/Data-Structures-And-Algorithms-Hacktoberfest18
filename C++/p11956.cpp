#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d%*c",&t);
	for(int k=1;k<=t;k++)
	{
		printf("Case %d:",k);
		int ptr=0;
		string S;
		cin>>S;
		int A[100]={0};
		for(int i=0;i<S.length();i++)
		{
			switch(S[i])
			{
				case '+':
					A[ptr]=(A[ptr]+1)%256;
					break;
				case '-':
					A[ptr]=(A[ptr]+255)%256;
					break;
				case '>':
					ptr=(ptr + 1)%100;
					break;
				case '<':
					ptr = (ptr + 99)%100;
			}
		}
		for(int i=0;i<100;i++)
			printf(" %.2X",A[i]%256);
		printf("\n");
	}
}
