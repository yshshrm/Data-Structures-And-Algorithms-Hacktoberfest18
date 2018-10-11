#include<stdio.h>
int count=0;
void move(int n,char source,char dest,char spare)
{
    count++;
    if(n==1)
        {
            printf("\nMove disk 1 from %c to %c",source,dest);
        }
    else
    {
        move(n-1,source,spare,dest);
        printf("\nMove disk %d from %c to %c",n,source,dest);
        //move(1,source,dest,spare);
        move(n-1,spare,dest,source);
    }
}
int main()
{
    int n;
    printf("Enter the number of disks\n");
    scanf("%d",&n);
    move(n,'A','C','B');
    printf("\nNumber of steps=%d",count);
    return  0;
}
