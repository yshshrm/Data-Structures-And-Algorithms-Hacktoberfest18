#include<bits/stdc++.h>
using namespace std;

main(){
    int t;
    scanf("%d", &t);
    while(t--){
        string s;
        cin>>s;
        for(int i=1; i<s.length(); i++){
            if(s[i]==s[i+1]){
                s.erase(s.begin()+i);
            }
        }
        cout<<s<<endl;
    }
}
