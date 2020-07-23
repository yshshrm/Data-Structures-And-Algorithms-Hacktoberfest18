#include<bits/stdc++.h>
using namespace std;

main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int v,e;
        scanf("%d %d", &v, &e);
        vector<vector<int>> adj(e);
        for(int i=0; i<e; i++){
            int a,b;
            scanf("%d %d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for(int i=0;i<v;i++){
	        cout<<i;
	        for(int j=0;j<adj[i].size();j++){
	            cout<<"-> "<<adj[i][j];
	        }
	        cout<<endl;

	    }
    }
}
