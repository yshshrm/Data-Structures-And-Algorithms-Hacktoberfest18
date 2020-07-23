#include <bits/stdc++.h>
using namespace std;

main(){
	string str;
	cin>>str;

	str.erase(remove(str.begin(), str.end(), '+'), str.end());

	sort(str.begin(), str.end()) ;
	
	char s[200];
	for (int i = 0; i < str.length(); ++i) {
		s[i] = str[i]+'+';
	}

	for (int i = 0; i < ; ++i) {
		cout<<s[i];
	}	
	
	return 0;
}