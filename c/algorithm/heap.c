#include<stdio.h>

void create(int []);
void down_adjust(int [],int);

int main()
{
	int a[30],n=10,i,last,t;
    printf("\nEnter 10 elements:");
	for(i=1;i<=n;i++)
		scanf("%d",&a[i]);
		a[0]=n;
	   create(a);

	while(a[0] > 1)
	{
		last=a[0];
		t=a[1];
		a[1]=a[last];
		a[last]=t;
		a[0]--;
		down_adjust(a,1);
	}

	printf("\nArray after sorting:\n");
	for(i=1;i<=n;i++)
		printf("%d ",a[i]);

	return 0;
}

void create(int a[])
{
	int i,n;
	n=a[0]; 

	for(i=n/2;i>=1;i--)
		down_adjust(a,i);
}

void down_adjust(int a[],int i)
{
	int j,t,n,flag=1;
	n=a[0];

	while(2*i<=n && flag==1)
	{
		j=2*i;    
		if(j+1<=n && a[j+1] > a[j])
			j=j+1;
		if(a[i] > a[j])
			flag=0;
		else
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
			i=j;
		}
	}
}
