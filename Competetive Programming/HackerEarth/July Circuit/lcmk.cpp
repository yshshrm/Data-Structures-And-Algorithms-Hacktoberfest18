#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long findlcm(vector<long long> arr, long long n)
{
    long long ans = arr[0];
    for (long long i = 1; i < n; i++)
        ans = (((arr[i] * ans)) / (gcd(arr[i], ans)));
    return ans;
}

main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        long long n,m,k,x;
        cin>>n>>m>>k;
        vector<long long> vect;
        for(long long i=0; i<n; i++){
            cin>>x;
            vect.push_back(round(pow(x,k)));
        }
        cout<<findlcm(vect,n)%m;
    }
    return 0;
}
