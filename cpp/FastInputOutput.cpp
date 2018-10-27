// Programme for Super Fast input and Output using buffers

#include<bits/stdc++.h>
using namespace std;

#define fastio std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)

int main(){

fastio;
cin>>a;
cout<<a<<endl;  //because cout is buffered by default, output is flushed/displayed on the console only on demand or when the buffer is full

return 0;
}
