#include <iostream>

using namespace std;

/* Evaluates a^b (mod 1000000007) */
unsigned long power(unsigned long a, unsigned long b) {
    static constexpr const unsigned long mod = 1000000007;
    if(b == 0)
        return 1ul;
    if(b == 1)
        return a;
    unsigned long hpower = power(a, b >> 1);
    return (hpower * ((hpower * (b % 2 == 1 ? a : 1)) % mod)) % mod;
}

int main() {

    unsigned long a, b;

    cin >> a >> b, cout << power(a, b) << endl;

    return 0;
}