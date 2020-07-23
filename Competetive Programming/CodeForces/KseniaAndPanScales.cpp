#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	string s,t,l,r;
	cin>>s;
	int d = s.find('|');
	l = s.substr(0,d);
	r = s.substr(d+1);
	cin>>t;
	for (auto c : t)
		if (l.size() < r.size())
			l+=c;
		else
			r+=c;
	if(l.size() == r.size())
		cout<<l+'|'+r;
	else
		cout<<"Impossible";
	return 0;
}