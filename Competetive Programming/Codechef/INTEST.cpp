#include<bits/stdc++.h>
using namespace std;

int n,k;
long long l;

main(){
    int count=0;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++){
        scanf("%lld", &l);
        if(l%k==0)
            count++;
    }
    printf("%d", count);
}
