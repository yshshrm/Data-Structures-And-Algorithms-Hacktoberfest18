#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of element you want to store: ";
    cin>>n;
    int arr[n],i,j;
    cout<<"Enter array values:\n";
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    //sort
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    cout<<"After sort the array is:\n";
    for(i=0;i<n;i++)
    cout<<arr[i]<<" ";
    return 0;
}
