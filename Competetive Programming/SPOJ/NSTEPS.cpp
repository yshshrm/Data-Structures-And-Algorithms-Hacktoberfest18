#include<bits/stdc++.h>
using namespace std;

main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int x,y;
        cin>>x>>y;
        if(x==y){
            if(y%2==0){
                cout<<x+y<<endl;
            } else{
                cout<<(x+y)-1<<endl;
            }
        } else if(x-y==2) {
            if(y%2==0){
                cout<<x+y<<endl;
            } else{
                cout<<(x+y)-1<<endl;
            }
        } else{
            cout<<"No Number"<<endl;
        }
    }
    return 0;
}
