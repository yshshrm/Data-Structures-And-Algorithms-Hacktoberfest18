#include<bits/stdc++.h>
using namespace std;

main(){
    int t, a, b;
    string x,y;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d", &a, &b);
        x=to_string(a);
        y=to_string(b);
        reverse(x.begin(), x.end());
        reverse(y.begin(), y.end());
        int sum = stoi(x) + stoi(y);
        string ssum = to_string(sum);
        reverse(ssum.begin(), ssum.end());
        int n = stoi(ssum);
        cout<<n<<endl;
    }
    return 0;
}
