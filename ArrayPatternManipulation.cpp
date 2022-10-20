#include <stdio.h>

int main()
{
    char a[100];
    printf("\nEnter the number: ");
    scanf("%s",a);

    int len;
    for(len=0;a[len]!='\0';len++);
    printf("Number of digits are : %d\n",len);
   

    char arr[len][len];
    int i,j;
    int fwd=len;
    for(i=0;i<len;i++)
    {
        int count=i;
        for(j=0;j<fwd;j++)
        {
            arr[i][j]=a[count];
            count++;
        }
        int set=0;
        for(j=fwd;j<len;j++)
        {
            arr[i][j]=a[set];
            set++;
        }
        fwd--;
        
    }
    
    for(i=0;i<len;i++)
    {
        for(j=0;j<len;j++)
        {
            printf("%c",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
