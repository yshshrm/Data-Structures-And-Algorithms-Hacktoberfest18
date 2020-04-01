#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    vector<int> v(n);
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	    }
	    vector<int> res;
	    list<int> x(k);
	    for (int i = 0; i < k; ++i){   
	        while (!x.empty() && v[i]>=v[x.back()])
                x.pop_back();  
            x.push_back(i);
        }
        for (int i=k ; i < n; ++i){
            res.push_back(v[x.front()]);
            while (!x.empty() && x.front()<=i-k)
                x.pop_front();
            while (!x.empty() && v[i]>=v[x.back()])
                x.pop_back();
            x.push_back(i);
        }
        res.push_back(v[x.front()]);
        for(int i=0;i<res.size();i++){
	        cout<<res[i]<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}