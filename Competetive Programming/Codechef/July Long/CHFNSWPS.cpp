#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t,n;

void a(){
	cin >> n;
        vector<ll> a(n), b(n);
        unordered_map<ll, ll> total;

        ll minimum = INT_MAX;
        for(int i=0; i<n; i++){
            cin>>a.at(i);
            total[a[i]]++;
            minimum = min(minimum, a[i]);
        }

        for(int i=0; i<n; i++){
            cin>>b.at(i);
            total[b[i]]++;
            minimum = min(minimum, b[i]);
        }

        bool check = false;
        unordered_map<ll,ll> correct;

        for(auto it=total.begin(); it!=total.end(); it++){
            if(it->second % 2 == 1){
                check = true;
                break;
            }else{
                correct[it->first] = it->second/2;
            }
        }
        if(check){
            cout << -1 << endl;
            return;
        }
        unordered_map<ll,ll> copy = correct;
        vector<ll> s1,s2;
        for(ll i=0; i<n; i++){
            if(copy[a[i]])
                copy[a[i]]--;
            else
                s1.push_back(a[i]);
        }

        copy = correct;
        for(ll i=0; i<n; i++){
            if(copy[b[i]])
                copy[b[i]]--;
            else
                s2.push_back(b[i]);
        }
        if(s1.size() == 0){
            cout << 0 << endl;
            return;
        }
        if(s1.size() != s2.size()){
            cout << -1 << endl;
            return;
        }
        int cost = 0;
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end(), greater<>());
        for(ll i=0; i<s1.size(); i++){
            cost += min(2*minimum, min(s1[i],s2[i]));
        }
        cout << cost << endl;
}

int main(){
    cin>>t;
    while(t--){
        a();
    }
    return 0;
}
