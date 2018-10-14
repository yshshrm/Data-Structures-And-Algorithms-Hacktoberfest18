/*
***********************************************************
***********************************************************
NAME-BHONESH CHAWLA
REGNO-20164017
BATCH-CS-1
CONTACT-+918619127663
EMAIL-rajachawla778@gmail.com
***********************************************************
***********************************************************
*/

//---------------------------------------------------------------------------------------------------------------------------------------

#include<bits/stdc++.h>
#define pf printf
#define sf scanf
#define db double 
#define z long long int 
using namespace std ;
#define MAXN 100001
#define xx 12345678901
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
z i,j;

//---------------------------------------------------------------------------------------------------------------------------------------
// function to construct segment tree in form of array 
void ct(z a[],z *seg,z low,z high ,z pos) 
{
    if(low==high)
    {
        seg[pos]=a[low];
        return;
    }
    z mid = (low+high)/2;

    ct(a,seg,low,mid,2*pos+1); // recursive call for left child
    ct(a,seg,mid+1,high,2*pos+2); // recursive call for right child
    seg[pos]=(seg[2*pos+1]+seg[2*pos+2]); // addition of left and right child will become parent 
}
//---------------------------------------------------------------------------------------------------------------------------------------
// function to answer range sum queries 
z range(z seg[],z ql,z qh,z low,z high,z pos)
{
    // TOTAL OVERLAP
    if(low>=ql && qh>=high ) 
    {
        return seg[pos]; // return the value which is available on given node
    }
    //NO OVERLAP
    if(low>qh || high <ql) 
    {
        return 0; // just return 0 because non overlapped nodes can not contribute in sum
    }
    // PARTIAL OVERLAP
    z mid =(low+high)/2;
    // in partial case go below and see for left and right child 
    // in partial case we won't stop here , we will go to left and right child and in future we will get case of either total overlap or non    overlap 
    return (range(seg,ql,qh,low,mid,2*pos+1)+range(seg,ql,qh,mid+1,high,2*pos+2));
    
}
//---------------------------------------------------------------------------------------------------------------------------------------
int main() 
{

    fast;
    z n;
    cin>>n; //  size of array
    z a[n];
    for(i=0;i<n;i++)
     cin>>a[i]; // elements of array  
 z maxs;
    // if array.size == 2^k for some integer k then segment.size == 2*(array.size)-1
    // if array.size != 2^k for some integer k then segment.size == 2*(next_power_of_two_of_array.size)-1
    // for example array.size == 4 then segment.size == 2*(4)-1==7
    // for example array.size == 5 then segment.size == 2*(8)-1==15

    // setting size of segment tree    
    if( ! ( n&(n-1) ) )
    {
        maxs=2*n-1;
    }
    else
    {
        z p = pow(2,ceil(log2(n)));
        maxs=2*p-1;
    }

    z *seg = new z[maxs]; 

    for(i=0;i<maxs;i++)
        seg[i]=INT_MAX;

    ct(a,seg,0,n,0); // building a segment tree 

    z t;
    cin>>t;
    while(t--)
    {
        z l,r;
        cin>>l>>r;
        cout <<range(seg,l,r,0,n,0)<<endl;
    }
    
    
   return 0;
}
