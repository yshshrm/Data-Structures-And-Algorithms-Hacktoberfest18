#include<bits/stdc++.h>
using namespace std;

vector<int> vect;
int arr[10000];

void sieve(int n){
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
    int n;
    cin>>n;
    sieve(n);
    for(int i=0; i<vect.size(); i++){
        cout<<vect[i]<<"\t";
    }
}
