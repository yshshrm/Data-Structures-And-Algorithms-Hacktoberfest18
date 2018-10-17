#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include<stdio.h>
int main(){


    int n,smallest,i,count=0,temp,j;
    scanf("%d",&n);
    int a[n];
    for( i = 0; i < n; i++)
    {
       scanf("%d",&a[i]);
    }

    for(i=0;i<n-1;i++)
        {
        for(j=0;j<n-1-i;j++)
            {
            if(a[j]>a[j+1])
                {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
       }

    count=n;

    while(count!=0)
        {
    printf("%d\n",count);
    count=0;


                    for(i=0;i<n;i++)
            {
                if(a[i]>0)
                 {
                 smallest=a[i];
                 break;
                 }

            }

        for(i=0;i<n;i++)
        {
        a[i]=a[i]-smallest;
        if(a[i]>0)
            {
            count++;

        }
        }

}
}
