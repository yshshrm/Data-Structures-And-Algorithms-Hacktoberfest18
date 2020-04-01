#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
void main()
{
	clrscr();
	char str[20];
	int len;
	cout<<"Enter a string : ";
	gets(str);
	len=strlen(str);
	cout<<"Length of the string is "<<len;
	getch();
}
