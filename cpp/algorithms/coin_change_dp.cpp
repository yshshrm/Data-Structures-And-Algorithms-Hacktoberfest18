#include<bits/stdc++.h>

using namespace std;
int n,k;
int a[51];
int ans[51][1005];

vector<int> v;
void fx(int val,int lft,int pre){
  if(val==0)
  {
    for(int i=0;i<v.size();i++)
      cout<<v[i]<<" ";
    cout<<"\n";
    return;
  }

  for(int i=pre;i<n;i++){
    if(a[i]>val)
      return;
    else if((1+ans[n-1][val-a[i]])==lft){
      v.push_back(a[i]);
      fx(val-a[i],lft-1,i);
      v.pop_back();
    }
  }
  return;

}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);


    cin>>n;
    //int a[n];
    for(int i=0;i<n;i++)
      cin>>a[i];
    cin>>k;
    sort(a,a+n);
    //int ans[n][k+1];
    for(int i=0;i<k+1;i++)
      ans[0][i]=i;
    for(int i=1;i<n;i++)
    {
      for(int j=0;j<k+1;j++)
      {
        if(j>=a[i])
          ans[i][j]=min(ans[i-1][j],ans[i][j-a[i]]+1);
        else
          ans[i][j]=ans[i-1][j];
      }
    }

    fx(k,ans[n-1][k],0);
}
