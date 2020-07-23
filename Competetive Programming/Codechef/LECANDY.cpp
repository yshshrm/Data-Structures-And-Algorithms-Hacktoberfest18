#include<bits/stdc++.h>
using namespace std;

int n,c,a;

main(){
    int t;
    scanf("%d", &t);
    while(t--){

        scanf("%d %d", &n, &c);
        int sum=0;
        for(int i=0; i<n; i++){
            scanf("%d", &a);
            sum += a;
        }

        if(sum<=c)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
