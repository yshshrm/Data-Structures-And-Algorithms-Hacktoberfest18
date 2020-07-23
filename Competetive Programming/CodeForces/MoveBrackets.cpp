#include<bits/stdc++.h>
using namespace std;

main(){
    int t;
    scanf("%d", &t);
    while(t--){
        string s;
        int n, cnt=0;
        stack<char> stk;
        scanf("%d", &n);
        cin>>s;

        for(int i=0; i<n; i++){
            if(s[i] == '(')
                stk.push(s[i]);
            else if(stk.empty() && s[i] == ')'){
                //stk.push();
                cnt++;
            } else{
                stk.pop();
            }
        }
        cout<<cnt<<endl;
    }
}
