#include<bits/stdc++.h>
using namespace std;

int t;
long a,b, countE;

main(){
    scanf("%d", &t);
    while(t--){
        countE=0;
        scanf("%d %d", &a, &b);
        if(a==0 || b==0){
            cout<<0<<endl;
            continue;
        }
        if(a>b){
            countE = a/2;
            b = b- countE;
            countE += b/3;
        } else {
            countE = b/2;
            a= a- countE;
            countE += a/3;
        }

        cout<<countE<<endl;
    }
    return 0;
}
