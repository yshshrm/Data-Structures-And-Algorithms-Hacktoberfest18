#include<bits/stdc++.h>
using namespace std;

int x,y,k,n;
int p,c;
bool flag;

main(){
    int t;
    scanf("%d", &t);
    while(t--){
        flag = false;
        cin>>x>>y>>k>>n;
        for(int i=0; i<n; i++){
            cin>>p>>c;
            if(c<=k && p>=(x-y)){
                flag = true;
            }
        }
        if(flag)
            cout<<"LuckyChef\n";
        else
            cout<<"UnluckyChef\n";
    }
    return 0;
}
