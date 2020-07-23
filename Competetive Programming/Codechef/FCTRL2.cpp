#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;

cpp_int fact(int n){
    if(n==0)
        return 1;
    return n * fact(n-1);
}
int t,n;

main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        cout<<fact(n)<<"\n";
    }
}
