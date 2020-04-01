/* An algorithm to find an element in a rotated array * /

#include<bits/stdc++.h>
using namespace std;

int binarySearch(int *arr,int s,int l,int k)
{
    if(l>=s)
    {int mid=(s+(l-1))/2;
   if(arr[mid]==k)
    return mid;
   else if(arr[mid]>k)
     return binarySearch(arr,s,mid-1,k);
   else if(arr[mid]<k)
     return binarySearch(arr,mid+1,l,k);
    }
    return -1;
}
int main()
{
    int n,arr[10006],k,index;
    cin>>n;
    for(int i=0;i<n;i++)
     cin>>arr[i];
    cin>>k;
    for(int i=0;i<n;i++)
    {
       if(arr[i]>arr[i+1])
           {
               index=i;
            break;
           }
    }
    int a;
    if(arr[0]<=k)
       a=binarySearch(arr,0,index,k);
    else a=binarySearch(arr,index+1,n-1,k);

        cout<<a<<endl;


}
