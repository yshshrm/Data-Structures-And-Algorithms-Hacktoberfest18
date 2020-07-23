#include<stdio.h>
int main( )
{
    char s1[7] = "1234", *p;
    p = s1 + 2;
    *p = '0' ;
    printf ("%s", s1);
}
