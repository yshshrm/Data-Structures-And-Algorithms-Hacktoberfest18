#include<bits/stdc++.h>
using namespace std;

main(){
	int n,count=0;
	scanf("%d", &n);
	stack<char> s;
	string str;
	cin>>str;
	for (int i = 0; i < n; ++i)
	{
	    if(!s.empty()){
            if (s.top()==str[i])
                count++;
	    }
	    s.push(str[i]);
	}
	cout<<count<<endl;
	return 0;
}
