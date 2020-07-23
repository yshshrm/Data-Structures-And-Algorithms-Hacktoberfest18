#include<bits/stdc++.h>
using namespace std;

int t, n;

main(){
    cin >> t;
    while(t--){
        cin>>n;
        n = 4*n-1;
        vector<int> x(n), y(n);
        for(int i = 0; i < n; ++i)
           cin>>x.at(i)>>y.at(i);

        int res = accumulate(x.begin(), x.end(), 0L, bit_xor<int>());
        int res1 = accumulate(y.begin(), y.end(), 0L, bit_xor<int>());
        cout<<res<<" "<<res1;
    }
    return 0;
}
