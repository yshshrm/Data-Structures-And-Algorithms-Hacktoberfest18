#include<bits/stdc++.h>
using namespace std;

main(){
    int t;
    vector<char> sol;
    stack<char> stc;
    char s;
    scanf("%d",&t);

    while(t--){
        sol.clear();
        int count =0;
        cin>>s;
        count++;
        while(count!=0){
            cin>>s;
            if(s=='('){
                count++;
            } else {
                if(s==')'){
                    count--;
                    sol.push_back(stc.top());
                    stc.pop();
                } else {
                    if(s=='+' || s=='-' || s=='*' || s=='/' || s=='^' || s=='%' || s=='_' || s=='|' || s==';' || s=='?'|| s=='~') {
                        stc.push(s);
                    } else {
                        sol.push_back(s);
                    }
                }
            }
        }
        for(int i=0; i<sol.size(); i++){
            cout<<sol.at(i);
        }
        cout<<endl;
    }

    return 0;
}
