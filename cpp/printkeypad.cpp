#include<iostream>
#include<string>
using namespace std;
void printKeypad(int number,string s)
{
  string code[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
  
  if(number==0)
  {
    cout<<s<<endl;
    return;
  }
  string code2=code[number%10];
  int len=code2.length();
  for(int i=0;i<len;i++)
    printKeypad(number/10,code2[i]+s);
}


void printKeypad(int number) {
	printKeypad(number,"");
}



