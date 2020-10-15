#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

bool compare(string a,string b){
	if(a.length()==b.length()){
		return a<b;
	}

	return a.length()>b.length();
}



int main(){
	int n,i;
	cin>>n;
	string s[100];
	cin.get();

	for (i = 0; i < n; ++i)
	{
		getline(cin,s[i]);
		
	}

	sort(s,s+n,compare);
	for (i = 0; i < n; ++i)
	{
      	cout<<s[i]<<endl;
	}

	return 0;
}