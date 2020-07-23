#include <bits/stdc++.h>
using namespace std;

main(){
	int t;
	scanf("%d", &t);
	int a[t], b[t], diff[t];

	for (int i = 0; i < t; ++i)
	{
		scanf("%d %d", &a[i], &b[i]);
	}

	for (int i = 1; i < t; ++i)
	{
		a[i] = a[i]+ a[i-1];
		b[i] = b[i]+ b[i-1];
	}

	for (int i = 0; i < t; ++i)
	{
		diff[i] = a[i] - b[i];
	}

	sort(diff, diff+t);

	if (abs(diff[0])>abs(diff[t-1]))
	{
		cout<<2<<" "<<abs(diff[0]);
	} else {
		cout<<1<<" "<<abs(diff[t-1]);
	}
	return 0;
}
