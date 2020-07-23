#include<bits/stdc++.h>
using namespace std;

int n,k;
int a[100];

main(){
    int t;
    cin>>t;
    while(t--){
        int count =0;
        cin>>n>>k;
        for(int i=0; i<n; i++){
            cin>>a[i];
            a[i] += k;
        }

        for(int i=0; i<n; i++)
            if(a[i]%7 == 0)
                count++;

        cout<<count<<endl;
    }
    return 0;
}
