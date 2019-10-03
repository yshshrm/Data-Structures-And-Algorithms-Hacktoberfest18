#include<bits/stdc++.h>
using namespace std;
int get(char S[])
{
	int sum=0,l=strlen(S);
	for(int i=0;i<l;i++)
	{
		if(isalpha(S[i]))
		{
			sum+=tolower(S[i])-'a'+1;
		}
	}
	int temp;
	while(sum>9)
	{
		temp=sum;
		sum=0;
		while(temp)
		{
			sum+=temp%10;
			temp/=10;
		}
	}
	return sum;
}
int main(int argc, char const *argv[])
{
	char A[100],B[100];
	while(scanf("%[^\n]%*c",A)!=EOF)
	{
		scanf("%[^\n]%*c",B);
		//printf("[%s\t%s]",A,B);
		int t1=get(A);
		int t2=get(B);
		double p=t1<t2?(double)t1/t2:(double)t2/t1;
		printf("%0.2f %\n",p*100);
	}
	return 0;
}