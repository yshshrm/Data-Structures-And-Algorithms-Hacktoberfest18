#include<bits/stdc++.h>
using namespace std;

int t,n,k,row;

main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		cout<<"O";
		k=n-1;
        row=7;
		for(int i=0; i<k; i++){
			cout<<".";
			row--;
			if(row==0){
				cout<<endl;
				row=8;
			}
		}

		k=64-n;
		for(int i=0; i<k; i++){
			cout<<"X";
			row--;
			if(row==0){
				cout<<endl;
				row=8;
			}
		}
		cout<<endl;
	}
}
