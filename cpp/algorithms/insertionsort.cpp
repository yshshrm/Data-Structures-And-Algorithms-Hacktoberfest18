//INSERT SORT ALGORITHM IN C++
#include<iostream>
using namespace std;
int main()
{
    int n;cin>>n;
    int a[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>a[i];

    }
    for(int i=1;i<n;i++)
    {
        int current=a[i];
        int j=i-1;
        while(a[j]>current && j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=current;
    }




    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" "<<endl;
    }
} 