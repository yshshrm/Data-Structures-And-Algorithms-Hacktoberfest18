#include <stdio.h>
char str1[100];

char *fun(char str[])
{
    static int i = 0;
    if (*str)
    {
        fun(str+1);
        str1[i] = *str;
        i++;
    }
    return str1;
}

int main()
{
    char str[] = "GATE CS 2015 Mock Test";
    printf("%s", fun(str));
    return 0;
}
