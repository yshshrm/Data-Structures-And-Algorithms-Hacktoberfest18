#include<bits/stdc++.h>
using namespace std;

main(){
	string str;
	cin>>str;
	str.erase(remove(str.begin(), str.end(), '+'), str.end());
	sort(str.begin(), str.end());
	for (int i = 0; i < str.length(); ++i)
	{
		cout<<str[i];
		if(i<str.length()-1)
			cout<<"+";
	}
	return 0;
}