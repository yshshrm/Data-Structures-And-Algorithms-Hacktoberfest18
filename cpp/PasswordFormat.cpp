#include<stdio.h>
#include<conio.h>
# define max 20 
main()
{
	char a,pwd[max];
	int i=0 ; 
	printf("Enter your Password\n");
	while(((a=getch())!='\r')&&(i<max))
	{
		pwd[i++]=a;
		printf("*");
	}
	pwd[i]='\0';
	printf("\n%s",pwd);
	getch();
}
