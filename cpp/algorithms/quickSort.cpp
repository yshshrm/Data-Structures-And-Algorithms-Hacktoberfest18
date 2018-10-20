

#include <stdio.h>


#include<vector>
#include<time.h>
#include<iostream>

using namespace std;

int quickpartition(vector<int>&v,int l,int r)
{
   int x=v[r];
   int i=l-1,j=l;
   
   for(;j<r;j++)
   {
       if(v[j]<=x)
       {
           swap(v[++i],v[j]);
       }
   }
   
   swap(v[++i],v[r]);
   
   return i;
   
   
}

void quicksort(vector<int>& v,int l,int r)
{
   if(l<r)
   {
   int pi=quickpartition(v,l,r);
   
   quicksort(v, l, pi-1);
   quicksort(v, pi+1,r);
   }
}


void randomisedquicksort(vector<int>&v,int l,int r)
{
   if(l<r)
   {
       
       int k=(rand()%(r-l+1))+l;
       swap(v[k],v[r]);
       
       int pi=quickpartition(v,l,r);
       
       randomisedquicksort(v, l, pi-1);
       randomisedquicksort(v, pi+1,r);
       
   }
}


void printvec(const vector<int>& v)
{
   
   for(int j=0;j<v.size();j++)
       cout<<v[j]<<' ';
   
   cout<<endl;
}
int main()
{
   srand((int)time(NULL));
   
   vector<int>v1;
   
   for(int i=0;i<10;i++)
   {
       v1.push_back(rand()%101);
   }
   
   vector<int>v2;
   
   for(int i=0;i<10;i++)
   {
       v2.push_back(rand()%101);
   }
   printvec(v2);
   
   printvec(v1);
   quicksort(v2, 0, (int)v2.size()-1);
   
   randomisedquicksort(v1, 0, (int)v1.size()-1);
   
   printvec(v2);
   
   printvec(v1);
   
   
   
   
   
   
   
   
   
   return 0;
}
