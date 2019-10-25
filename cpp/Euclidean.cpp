#include <bits/stdc++.h>
//Euclidean algorithm for C++

using namespace std;

//Just take the remainder until there is 0, the other is greatest common divisor
int gcd(int x,int y){//basic one
    if(x==0)
        return y;
    return gcd(y%x,x);
}


//This is more complicated
int gcd_ext(int a,int b,int x,int y){// extended one
    if(a==0){
        x=0;
        y=1;
        return b;
    }
    int x1=1;
    int y1=1;
    int gcd=gcd_ext(b%a,a,x1,y1);

    x=y1-(b/a) * x1;
    y=x1;
    return gcd;
}


int main(void){


    return 0;
}
