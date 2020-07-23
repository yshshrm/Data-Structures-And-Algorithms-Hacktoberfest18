#include<iostream>
using namespace std;

main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(j==i || j==0)
                cout<<"#";
            else
                cout<<" ";
        }
        cout<<endl;
    }

    for(int i=n; i>0; i--){
        for(int j=0; j<=i; j++){
            if(j==i || j == 0)
                cout<<"#";
            else
                cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}
