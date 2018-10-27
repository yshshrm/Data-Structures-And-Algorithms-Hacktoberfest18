// Programme t megr K-sorted Arrays

#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,m,a[50][50],b[10000]={0}; //init vars
	cin>>n>>m;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
		}
	}	

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			b[i*m + j]=a[i][j];
		}
		
	}
	
	set<int> s;

	for(int i=0;i<n*m;i++){
		s.insert(b[i]);
	}

	for(set<int >::const_iterator it=s.begin(); it!=s.end() ; it++){  //Set iterator's for loop
		cout<<*it<<" ";
	}
  
  return 0;
}
