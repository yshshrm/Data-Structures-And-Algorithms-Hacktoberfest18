#include<iostream>
#include<utility>
#include<stack>
using namespace std;

int* stockSpan(int *price, int size){
int *s;
s=new int[size];
s[0]=1;
pair <int,int> p;
stack <pair <int,int> > s1;
p=make_pair(price[0],1);
s1.push(p);
for(int i=1;i<size;i++){
    p=make_pair(price[i],1);
    while(!s1.empty()){
        if(s1.top().first<p.first){
            p.second+=s1.top().second;
            s1.pop();

        }
        else{
            break;
        }



    }
    s1.push(p);
    s[i]=s1.top().second;
}
for(int i=0;i<7;i++){
    cout<<s[i]<<endl;

}

return s;

}

int main(){
int price[]={6,5,9,10,4,3,7};
int *s1;
s1=stockSpan(price,7);


return 0;
}
