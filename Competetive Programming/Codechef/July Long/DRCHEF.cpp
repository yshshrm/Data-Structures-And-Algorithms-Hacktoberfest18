#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void test(){
    ll n, x, days = 0;
    cin >> n >> x;
    vector<ll> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    vector<ll>::iterator it = lower_bound(a.begin(), a.end(), x);
    ll lb = it - a.begin();

    for(int i=lb; i<n; i++)
    {
        if(x<a[i])
        {
            while(x<a[i])
            {
                x = 2*x;
                days++;
            }
            days++;
        }
        else
        days++;
        x = 2*a[i];
    }
        ll tot = lb + days;
        if(lb != 0)
        {
            days = 0;
            lb--;
            for(int i=lb; i<n; i++)
            {
                if(x < a[i])
                {
                    while(x<a[i])
                    {
                        x = 2*x;
                        days++;
                    }
                    days++;
                }
                else
                days++;
                x = 2*a[i];
            }
            if(days+lb<tot)
                cout << days+lb << endl;
            else
                cout << tot << endl;
        }
        else
            cout << tot << endl;
}

int main(){
    int t; cin >> t;
    while(t--)
        test();
    return 0;
}
