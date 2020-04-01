#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	scanf("%d%*c",&t);
	while(t--)
	{
		string S;
		getline(cin,S);
		int M=0,F=0;
		//cout<<S<<"\t";
		for(char c:S)
		{
			if(c=='M')
				M++;
			else if(c=='F')
				F++;	
		}
		//printf("%d %d\n",M,F);
		if(M==F&&M>1)
			printf("LOOP\n");
		else
			printf("NO LOOP\n");
	}
} 
				
