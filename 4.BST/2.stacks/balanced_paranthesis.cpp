#include<bits/stdc++.h>
using namespace std;
bool check(char a, char b){
    if((a==')' && b=='(') || (a=='}' && b=='{') || (a==']' && b=='[')){
        return true;
    }
    return false;
}

bool ispar(string x)
{
    // Your code heres
    stack<char> st;
    for(int i=0;i<x.length();i++){
        if(x[i]=='(' || x[i]=='{' || x[i]=='['){
            st.push(x[i]);
        }
        else{
            if(st.empty()){
                return false;
            }
            else if(check(x[i],st.top())){
                st.pop();
            }
            else{
                return false;
            }
        }
    }
    return st.empty();
    
    
}

int main(){
  int test;
  cin>>test;
  while(test--){
    string paran;
    cin>>paran;
    if(ispar(paran)){
      cout<<"balanced"<<endl;
    }
    else{
      cout<<"unbalanced"<<endl;
    }
  }
}
