#include<bits/stdc++.h>
using namespace std;

main(){
    int t,n, sum;
    scanf("%d", &t);
    while(t--){
        sum=0;
        scanf("%d", &n);
        for(int i=n; i>0; i/=10){
            sum += i%10;
        }
        cout<<sum<<"\n";
    }
}
