#include <stdio.h>
int main(int argc, char const *argv[])
{
	int n,a[n];
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&a[i]);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (a[i]>a[j])
			{
				int b=a[i];
				a[i]=a[j];
				a[j]=b;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}