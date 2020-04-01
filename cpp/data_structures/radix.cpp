#include<iostream>
using namespace std;

void radix(int a[],int n)
{
    int maxdata=getdata(a[],n);
    for(int exp=1;maxdata/exp>0;exp=exp*10)
    {
        countsort(a[],n,exp);
    }
}

void countsort(int a[],int n,int exp)
{
    int count[50]={0};
    int output[50];
    int i;
    for(i=0;i<n;i++)
    {
        count[(a[i]/exp)%10]++;
    }
    for(i=1;i<10;i++)
    {
        count[i]=count[i]+count[i-1];
    }
    for(i=n-1;i>0;i--)
    {
        output[count[(a[i]/exp)%10]-1]=a[i];
        count[(a[i]/exp)%10]--;
    }
    for(i=0;i<n;i++)
    {
        a[i]=output[i];
    }
}
int main()
{
    int a[20],i,n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    radix(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i];
    }
}
