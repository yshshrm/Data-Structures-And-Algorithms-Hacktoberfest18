#include<bits/stdc++.h>
using namespace std;

main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            if(j==0 || j==i)
                cout<<1;
            else
                cout<<0;
        }
        cout<<endl;
    }
    return 0;
}
