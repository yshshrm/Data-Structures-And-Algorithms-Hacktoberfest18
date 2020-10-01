#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
	int n,sum = 0;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(sum>=0){
		cout<<"YES\n";
	}
	else
		cout<<"NO\n";
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
