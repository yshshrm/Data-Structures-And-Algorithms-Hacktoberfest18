#include<iostream.h>
#include<conio.h>
void main()
{
	clrscr();
	int a=0, b=1, c=0, limit;
	cout<<"Upto How many term ? ";
	cin>>limit;
	cout<<"Fabonacci Series : "<<a<<" "<<b<<" ";  // first two term
	c=a+b;
	limit=limit-2;   // decrease the limit by 2. since two numbers already printed
	while(limit)
	{
		cout<<c<<" ";
		a=b;
		b=c;
		c=a+b;
		limit--;
	}
	getch();
}
