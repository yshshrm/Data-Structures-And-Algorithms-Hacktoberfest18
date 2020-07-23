#include<bits/stdc++.h>
using namespace std;

main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int x,y,n,k, temp;
        cin>>x>>y>>n;
        if(x>n){
            cout<<0<<endl;
        } else {
           // cout<<"temp"<<temp<<endl;
            k= n-((n-y)%x);
            cout<<k<<endl;
        }
    }
    return 0;
}
