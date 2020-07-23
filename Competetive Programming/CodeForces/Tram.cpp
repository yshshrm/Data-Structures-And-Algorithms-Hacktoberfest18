#include <bits/stdc++.h>
using namespace std;

main(){
	int n,a,b, total=0, maxx=0;
	cin>>n;
	while(n--){
		cin>>a>>b;
		total=(total-a)+b;
		maxx = max(maxx, total);
	}
	cout<<maxx<<endl;
	return 0;
}