#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

main(){
    int n;
    cin>>n;
    ll a[n], max_ = 0, count = 0;
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a, a+n);

    for(int i=0; i<n; i++){
        count = a[i] *(n-i);
        max_ = max(max_, count);
    }
    cout<<max_;
    return 0;
}
