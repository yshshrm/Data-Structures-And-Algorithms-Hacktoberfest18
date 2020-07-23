#include<bits/stdc++.h>
using namespace std;

main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n,p;
        scanf("%d", &n);
        p = (pow(n,2) + n + 2)/2;
        printf("%d\n", p);
    }
    return 0;
}
