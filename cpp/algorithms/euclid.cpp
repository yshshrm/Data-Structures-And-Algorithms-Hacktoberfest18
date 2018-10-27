#include <iostream>

using namespace std;
int a,b;
int cmmdc(int a,int b)
{
    if(!b) return a;
    return cmmdc(b,a%b);
}

int main()
{
    int c,d;

    cin>>c>>d;
    cout<<cmmdc(c,d);
    return 0;
}
