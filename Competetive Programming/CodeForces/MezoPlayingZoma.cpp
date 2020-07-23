#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, plusx=0, minusx=0, minn=0, maxx=0;
	string s;
	cin>>n>>s;

	for (int i = 0; i < n; ++i)
	{
		if (s[i]=='L'){
			minusx--;
			minn = min(minn,minusx);
		} else {
			plusx++;
			maxx = max(maxx,plusx);
		}

	}

	cout<<maxx-minn+1<<endl;
	return 0;
}