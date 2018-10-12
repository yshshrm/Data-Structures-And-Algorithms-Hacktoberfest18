#include<stdio.h>

int gcd(int a, int b) {
    int r;
    while(b != 0) {
        r = a% b;
        a = b;
        b = r;
    }

    return a;
}

int main() {
int a,b;

printf("a: ");
scanf("%d", &a);
printf("b: ");
scanf("\n%d", &b);

printf("The gcd(%d,%d) = %d\n", a, b, gcd(a,b));
}