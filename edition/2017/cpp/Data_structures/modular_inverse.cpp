// Complexity: O(log(n))
// Computes the modular inverse of n modulo P

#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;

ull P;

// Fast Exponentiation technique calculates n^factor with O(log(n)) complexity.
ull fast_exponentiation(ull n,ull factor){
  ull x;

  if(factor==0) return 1;
  if(factor==1) return n;

  if(factor%2==0){
    x = fast_exponentiation(n,factor/2)%P;
    return (x*x)%P;
  }else{
    return (n*fast_exponentiation(n,factor-1))%P;
  }
}

// Fermat's little theorem =>  a^(p-1)= 1 mod p
// therefore =>  a*a^(p-2)=1 mod p  => inv(a) = a(p-2) mod p
ull modular_inverse(ull n){
  return fast_exponentiation(n,P-2);
}

int main(){
  ull n;
  cin >> n >> P;

  cout << modular_inverse(n) << endl; 

  return 0;
}
