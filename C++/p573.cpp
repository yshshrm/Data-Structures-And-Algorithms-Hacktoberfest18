#include<bits/stdc++.h>
using namespace std;

int main()
{
	float H,D,U,F,sum=0;
	while(scanf("%f%f%f%f",&H,&U,&D,&F),H||D||U||F)
	{
		sum=0;
		F=(U*F)/100;
		for(int j=1;;j++)
		{
			sum+=U;
			if(sum>H)
			{
				printf("success on day %d\n",j);
				break;
			}
			sum-=D;
			if(sum<0)
			{
				printf("failure on day %d\n",j);
				break;
			}
			U-=F;
			if(U<0)
				U=0;
		}
	}
	return 0;
}
