// String Class Example to replace the vovels in string
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; // initalize the string in c++
    cin>>s;

//Remove vovels in string
    for(int i=0;i<s.length();i++){
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||
            s[i]=='O'||s[i]=='U'){
            s.replace(i,1,"");
            i--;
        }
    }
    cout<<s;
}
