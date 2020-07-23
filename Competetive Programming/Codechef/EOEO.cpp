#include<bits/stdc++.h>
using namespace std;

unsigned long long ts,js, temp, result, power;
int t;

main(){
    scanf("%d", &t);
    while(t--){
        scanf("%lld", &ts);
        temp=ts, power=0, result=0;

        while(temp%2==0){
            power++;
            temp/=2;
        }
        js = pow(2,power+1);
        if(js<=ts)
            result = ts/js;

        cout<<result<<endl;
    }
    return 0;
}
