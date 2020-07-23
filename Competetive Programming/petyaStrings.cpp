#include <bits/stdc++.h>
using namespace std;

main(){
	string s1,s2;
	cin>>s1>>s2;

	transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
	transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

	if(string(s1) > s2) cout<<1<<endl;
	if(string(s1) < s2) cout<<-1<<endl;
	if(string(s1) == s2) cout<<0<<endl;

	return 0;
}