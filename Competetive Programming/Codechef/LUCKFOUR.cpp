#include<bits/stdc++.h>
using namespace std;

int t, rem;
long long n;

main(){
    scanf("%d", &t);
    while(t--){
        scanf("%lld", &n);
        string s = to_string(n);
        int countf=0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='4')
                countf++;
        }
        cout<<countf<<endl;
    }
}
