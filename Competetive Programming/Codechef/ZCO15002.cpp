#include<bits/stdc++.h>
using namespace std;

int n,k;

main(){
    cin>>n>>k;
    int a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    sort(a, a+n);
    long long ans = 0;
	int i = 0, j = 0;
	while (i < n) {
		if (j < i)
			j = i;
		else if (j >= n)
			break;
		if (a[j] - a[i] >= k) {
			i++;
			ans += n - j;
		}
		else
			j++;
	}
    cout<<ans<<endl;
    return 0;
}
