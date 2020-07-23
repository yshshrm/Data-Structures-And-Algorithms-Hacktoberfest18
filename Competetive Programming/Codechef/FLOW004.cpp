#include<bits/stdc++.h>
using namespace std;

main(){
    int t,n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        string s = to_string(n);

        cout<<(int)(s[0]-'0') + (int) (s[s.length()-1]-'0')<<"\n";
    }
}
