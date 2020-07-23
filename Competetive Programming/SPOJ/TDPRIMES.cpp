#include <bits/stdc++.h>
using namespace std;

vector<int> primes;
int spf[100];

void sieve(int LIM) {
	for (int i = 2; i <= LIM; i++) {
		if (spf[i] == 0) {
			spf[i] = i;
			primes.push_back(i);
		}
		for (int j = 0; j < primes.size() && primes[j] <= spf[i] && i * primes[j] <= LIM; j++)
			spf[i * primes[j]] = primes[j];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	sieve(100);
	for (int i = 0; i < primes.size(); i++)
		cout << primes[i] << '\t';
}
