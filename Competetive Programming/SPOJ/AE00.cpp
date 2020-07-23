#include<bits/stdc++.h>
using namespace std;

main(){
    int n, sum=0;
    cin>>n;

    for(int i=1; i<=sqrt(n); i++){
        sum = sum+n/i - i + 1;
    }
    cout<<sum;
    return 0;
}
