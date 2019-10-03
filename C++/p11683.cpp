#include<bits/stdc++.h>

using namespace std;

int main()
{
	int a,c;

	while(scanf("%d",&a),a)
	{
		scanf("%d",&c);
		int temp;		
		vector< int > V (c+2,0);
		for(int i=1;i<=c;i++)
		{
			scanf("%d",&temp);
			V[i]=a-temp;
		}
		/*for(int i: V)
			printf("%d ",i);
		printf("\n");*/
		int pc=0,count=1;

		do
		{
			int prev=0;
			count=1;
			for(int i=1;i<c+2;i++)
			{
				if(V[i])
					V[i]-=1;
				else 
				{
					if(i>prev+1)
						pc++;
					count++;
					prev=i;
				}
			}
			
			/*for(int i: V)
				printf("%d ",i);
			printf("\n");*/
		}while(count<c+2);

		printf("%d\n",pc);
	}

	return 0;

}
