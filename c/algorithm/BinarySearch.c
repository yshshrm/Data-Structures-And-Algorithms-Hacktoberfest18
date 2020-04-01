#include<stdio.h>
#include<conio.h>
void main()
{
	clrscr();
	int a[10],i,j,ch,large,f=0,small,mid;
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	scanf("%d",&ch);
	large=9;small=0;mid=4;
	while(mid!=ch&&small!=large)
	{
		if(ch<mid)
		large=mid-1;
		else
		small=mid+1;
		mid=(large+small)/2;
		if(ch==mid)
		{
			f=1;
			break;
		}
	}
	if(f)
		printf("Choice Found");
	else
		printf("Choice not found");
	getch();
}
