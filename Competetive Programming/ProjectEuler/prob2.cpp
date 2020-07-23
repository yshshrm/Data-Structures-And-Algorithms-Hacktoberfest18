#include<iostream>
using namespace std;

main(){
    int t1 = 1, t2 = 2;
    long long nextTerm = 0, n = 4000000, sum =0;
    printf("Fibonacci Series: %d, %d, ", t1, t2);
    nextTerm = t1 + t2;

    while (nextTerm <= n) {
        //printf("%d, ", nextTerm);
        if(nextTerm%2==0)
            sum += nextTerm;
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
    }
    cout<<sum+2;
    return 0;
}
