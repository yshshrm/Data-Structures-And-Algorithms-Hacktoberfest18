#include<bits/stdc++.h>
using namespace std;

main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        char x;
        stack<char> stc;
        cin>>s;
        for(char *c : s){
           if(c=='(' || c=='{' || c=='[')
                stc.push(c);

            switch (c)
            {
                case ')':

                    x = stc.top();
                    stc.pop();
                    if (x=='{' || x=='[')
                        cout<<"not balanced"<<endl;
                    break;

                case '}':

                    x = stc.top();
                    stc.pop();
                    if (x=='(' || x=='[')
                        cout<<"not balanced"<<endl;
                    break;

                case ']':

                    x = stc.top();
                    stc.pop();
                    if (x =='(' || x == '{')
                        cout<<"not balanced"<<endl;
                    break;
            }
        }
            if(stc.empty())
                cout<<"balanced"<<endl;
            else
                cout<<"not balanced"<<endl;
    }
    return 0;
}
