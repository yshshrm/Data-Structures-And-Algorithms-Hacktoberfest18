#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int arr[100005];
int ST[100005][(int)log2(100005)];
int LG[100005];
int PW[60];
// Computes the floor of the log of integer from 1 to n
//O(n)
void computeLOG(int n)
{
    LG[0]=-1;
    for(int i=1;i<=n;i++)LG[i]=LG[i-1]+!(i&(i-1));
    PW[0]=1;
    for(int i=1;i<=50;i++)
        PW[i]=PW[i-1]*2;
}
//build sparse table for computing min/max/gcd/lcm....
//for any contigus sub-segmentof the array

//This is Example for sparse table calculating the minimum value
void buildST(int n)
{
    for(int i=0;i<100005;i++)ST[i][0]=arr[i];
    for(int i=1;PW[i]<=n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j+PW[i]-1>=n)break;
            long long x=ST[j][i-1];
            long long y=ST[j+PW[i-1]][i-1];
            ST[j][i]=min(x,y);
        }
    }
}
//Queries the sparse table for the value interval from l to r
//O(1)
long long query(int l,int  r)
{
    int len=r-l+1;
    int  i=LG[len];
    int x=ST[l][i];
    int y=ST[r-PW[i]+1][i];
    return min(x,y);
}
int main() {
    computeLOG(9);

    arr[0]=7;
    arr[1]=2;
    arr[2]=3;
    arr[3]=0;
    arr[4]=5;
    arr[5]=10;
    arr[6]=3;
    arr[7]=12;
    arr[8]=18;

    buildST(9);
    cout << query(0, 4) << endl;
    cout << query(4, 7) << endl;
    cout << query(7, 8) << endl;

    return 0;
}