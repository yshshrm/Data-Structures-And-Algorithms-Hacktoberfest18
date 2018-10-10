#include<stdio.h>

int arr[10];

int ternary_search(int l,int r, int x)
{
    if(r>=l)
    {
        int mid1 = l + (r-l)/3;
        int mid2 = r -  (r-l)/3;
        if(arr[mid1] == x)
            return mid1;
        if(arr[mid2] == x)
            return mid2;
        if(x<arr[mid1])
            return ternary_search(l,mid1-1,x);
        else if(x>arr[mid2])
            return ternary_search(mid2+1,r,x);
        else
            return ternary_search(mid1+1,mid2-1,x);

    }
    return -1;
}

int main()
{
    int i,item;
    printf("Enter 10 Elements:");
    for(i = 0; i < 10 ; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter Element to Search:");
    scanf("%d",&item);
    printf("pos : %d",ternary_search(0,9, item));
    return 0;
}