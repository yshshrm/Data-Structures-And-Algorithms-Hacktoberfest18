#include <iostream>
#include <cstring>
using namespace std;

int static arr[11][51];

int minattempts(int n, int k)
{
    
    
    if(k==0||k==0)
    return k;
    if(n==1)
    return k;
    if(arr[n][k] != -1)
    return arr[n][k];
    
    int mn= INT_MAX;
    for(int z=1;z<=k;z++)
    {
        int temp = 1+ max(minattempts(n-1,z-1),minattempts(n,k-z));
        
        if(temp<mn)
        mn=temp;
    }
    return arr[n][k] =mn;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    memset(arr,-1,sizeof(arr));
	    cout<<minattempts(n,k)<<endl;
	    
	}
	return 0;
}
