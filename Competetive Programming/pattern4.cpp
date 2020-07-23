#include<iostream>
using namespace std;

main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=n; j>i; j--){
            cout<<j;
        }
        cout<<"$";
    }
    return 0;
}
