#include<algorithm>
#include<iostream>
using namespace std;

int main() {
    int t,n,l,r,trap,right_max,left_max;int w[101];
    cin>>t;
    while(t--)
    {   trap = 0;right_max=0;left_max=0;
        cin>>n;
        l=0;r=n-1;
        for(int i=0;i<n;i++)
            cin>>w[i];
        while(l<=r)
        {   if(w[l] <= w[r])
            {
                if(w[l]>left_max)
                    left_max = w[l];
                else
                    trap += left_max - w[l];
                l++;    
            }
            else
            {
                if(w[r]>right_max)
                    right_max = w[r];
                else
                    trap += right_max - w[r];
                r--;    
            }
        }    
        cout<<trap<<endl;
            
    }
	return 0;
}
