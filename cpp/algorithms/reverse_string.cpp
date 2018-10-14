#include <iostream>
using namespace std;

int main() {
	string S;
	char a;
	int i,n;
	cout<<"Enter the String: ";
	cin>>S;
	n=S.length();
	i=0;
	while(i<n/2)
	{
	    a=S[i];
	    S[i]=S[n-i-1];
	    S[n-i-1]=a;
	    i++;
	}
	cout<<"\nThe Reversed String is:"<<S;
	return 0;
}

