#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define test int t; cin >> t; while(t--)
#define debug(x) cout << '>' << #x << ':' << x << "\n";
#define endl '\n'

// Counter for inversions
int total = 0;
// Auxiliary array for merging
int aux[1000];

// Function for Conquering
void join(int* a, int low, int high) {
  int mid = (low + high) >> 1;
	int k = 0, i, j;
	
	for(i = low, j = mid + 1; i < mid + 1 && j < high + 1;) {
		if (a[i] > a[j]) {
			aux[k] = a[j];
			j++;
			k++;
			total += mid - i + 1;
		}
		else {
			aux[k] = a[i];
			i++;
			k++;
		}
	}

	while(i < mid+1) {
		aux[k] = a[i];
		k++;
		i++;
	}
	while(j < high+1) {
		aux[k] = a[j];
		j++;
		k++;
	}

	rep(z, k) {
		a[z+low] = aux[z];
	}
}

// Function for Dividing
void half(int* a, int low, int high) {
	if (high <= low) {
		return;
	}
	int mid = (low + high) >> 1;
	half(a, low, mid);
	half(a, mid+1, high);
	join(a, low, high);
}

int main() {
	int a[100007];
	test {
		int n;
		cin >> n;
		rep(i, n) {
			cin >> a[i];
		}

		half(a, 0, n-1);
		cout << total << endl;
	}
  	return 0;
}
