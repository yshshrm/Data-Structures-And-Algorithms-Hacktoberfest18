		
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
void main()
{
	clrscr();
	char strs[100], countw=0, strw[15];
	int i, len;
	cout<<"Write a sentence : ";
	gets(strs);
	len=strlen(strs);
	for(i=0; i<len; i++)
	{
		if(strs[i]==' ')
		{
			countw++;
		}
	}
	cout<<"Total number of words in the sentence is "<<countw+1;
	getch();
}
