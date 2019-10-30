#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&a[i]);
	}
	int x, f = -1;
	scanf("%d",&x);
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == x)
		{
			f = i;
			break;
		}
	}
	if (f != -1)
	{
		printf("Found At %d\n", f);
	}
	else
		printf("Not Found\n");
	return 0;
}