#include <bits/stdc++.h>
using namespace std;
int query(int x,int tree[],int start,int end,int a[],int l, int r);
int update(int x,int tree[],int start,int end,int a[],int idx,int val);
int build(int x,int tree[],int start,int end,int a[]);
int main()
{
    int n,q;
    cin>>n>>q;
    int l=1;
    while(l<n)
    {
        l=l*2;
    }
    //cout<<l<<endl;
    int a[l];
    int tree[2*l-1];
    for(int i=0;i<l;i++)
    {
        if(i<n)
        {
            cin>>a[i];
        }
        else 
        {
            a[i]=INT_MAX;   
        }
        //cout<<a[i]<<" ";
    }
    /*cout<<endl;*/
    build(0,tree,0,l-1,a);
    /*for(int i=0;i<2*l;i++)
    {
      cout<<tree[i]<<" ";   
    }
    cout<<endl;*/
    for(int i=0;i<q;i++)
    {
       char c;
       cin>>c;
       if(c=='q')
       {
           int x,y;
           cin>>x>>y;
           x--;
           y--;
           cout<<query(0,tree,0,l-1,a,x,y)<<endl;;
       }
       else if(c=='u')
       {
          int x,y;
          cin>>x>>y;
          x--;
          update(0,tree,0,l-1,a,x,y);
       }
    }
return 0;    
}
int build(int x,int tree[],int start,int end,int a[])
{
    if(start==end)
    {
        tree[x]=a[start];
    }
    else 
    {
        int mid=(start+end)/2;
        build(2*x+1,tree,start,mid,a);
        build(2*x+2,tree,mid+1,end,a);
        tree[x]=min(tree[2*x+1],tree[2*x+2]);
    }
    return 0;
}
int query(int x,int tree[],int start,int end,int a[],int l, int r)
{
    if(r<start||end<l)
      return INT_MAX;
    if(l<=start&&end<=r) 
    {
        return tree[x];
    }
    else 
    {
        int mid=(start+end)/2;
        int p1=query(2*x+1,tree,start,mid,a,l,r);
        int p2=query(2*x+2,tree,mid+1,end,a,l,r);
        return min(p1,p2);
    }
}
int update(int x,int tree[],int start,int end,int a[],int idx,int val)
{
    if(start==end)
    {
        a[idx]=val;
        tree[x]=val;
    }
    else
    {
        int mid=(start+end)/2;
        if(idx>=start&&mid>=idx)
        update(2*x+1,tree,start,mid,a,idx,val);
        else 
        update(2*x+2,tree,mid+1,end,a,idx,val);
        
        tree[x]=min(tree[2*x+1],tree[2*x+2]);
    }
return 0;    
}