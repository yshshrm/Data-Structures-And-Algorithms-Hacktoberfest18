#include <stdio.h>

int fibonacci(int i) {
    int a[i+1];
    a[0] = 0;
    if(i >= 1){
        a[1] = 1;
    }
    if(i >=2) {
        a[2] = 1;
    }
    for (int j = 3; j <= i ; j++) {
        a[j] = a[j-2]+a[j-1];
    }


    return a[i];
}
