#include<bits/stdc++.h>
using namespace std;

vector<int> vect;

void sieve(int n){
    vect.clear();
    int arr[100000000] = {0};
    for(int i=2; i<=n; i++){
        if(arr[i]==0){
            arr[i]=i;
            vect.push_back(i);
        }

        for(int j=0; j<vect.size() && vect[j]<=arr[i] && i*vect[j]<=n; j++)
            arr[i*vect[j]] = vect[j];
    }
}

main(){
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        sieve(n);
        int i=0;
        while(i<vect.size() && vect[i]<=n && vect[i]>=m){
            cout<<vect[i]<<endl;
            i++;
        }
    }
}
