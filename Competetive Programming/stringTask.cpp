#include <bits/stdc++.h>
using namespace std;

main(){
	string s;
	cin>>s;
	transform(s.begin(), s.end(), s.begin(), ::tolower);

	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='u' || s[i]=='y' || s[i]=='i'){
			continue;
		} else {
			cout<<'.'<<s[i];
		}
	}
	return 0;
}