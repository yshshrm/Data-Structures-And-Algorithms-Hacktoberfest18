#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll fib(ll n) {
    vector<ll> f (n+2);
    f[0] = 0;
    f[1] = 1;
    
    for (ll i = 2; i <= n; i++) {
        f[i] = f[i-1] + f[i-2];
    }

    return f[n];
}


int main() {
    ll n;

    cout << "Fibonacci ?" << "\n";
    cin >> n;
    cout << fib(n) << "\n";
    
    return 0;
}
