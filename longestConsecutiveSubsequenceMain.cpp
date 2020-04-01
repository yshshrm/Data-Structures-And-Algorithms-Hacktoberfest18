#include<iostream>
#include<set>
#include<string>
using namespace std;
char* uniqueChar(char *str){
    // Write your code here
string s1,s2;
  set <char> s;
for(int i=0;i<7;i++){

  s.insert(str[i]);

}
  set <char>:: iterator it;
  int i=0;
  for(it=s.begin();it!=s.end();it++){
    s1[i]=*it;
  }
  return s1;
}

int main(){
string s="ababacd";
string s1;
s1=uniqueChar(s);
cout<<s1;

return 0;
}
