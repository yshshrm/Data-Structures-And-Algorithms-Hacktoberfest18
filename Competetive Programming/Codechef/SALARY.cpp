#include<bits/stdc++.h>
using namespace std;

int n;
int a[100];

main(){
    int t;
    cin>>t;
    while(t--){
        int sum =0;
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>a[i];
            sum += a[i];
        }

        int moves = sum - (n * *(min_element(a, a+n)));

        cout<<moves<<endl;
    }
    return 0;
}
