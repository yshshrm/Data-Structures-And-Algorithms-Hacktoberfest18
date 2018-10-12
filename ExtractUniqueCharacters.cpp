#include<iostream>
#include<string>
#include<string.h>
#include<unordered_set>
using namespace std;
char* uniqueChar(char *str){
    // Write your code here
char *s1;
unordered_set <char> s;
for(int i=0;i<strlen(str);i++)
{
    s.insert(str[i]);
}
int j=0;
unordered_set <char>::iterator it;
for(it=s.begin();it!=s.end();it++){
    j++;
}
s1=new char[j];

int i=0;
for(it=s.begin();it!=s.end();it++){
    s1[i]=*it;
    i++;
}
char s2[j];
int k=0;
for(i=j-1;i>=0;i--){
    s2[k]=s1[i];
    k++;
}


return s1;
}
int main(){
char str[]="ababacd";
char *str1;
str1=uniqueChar(str);
for(int i=0;i<strlen(str1);i++)
{
    cout<<str1[i];
}


return 0;

}
