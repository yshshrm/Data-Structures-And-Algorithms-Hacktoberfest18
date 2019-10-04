#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5+1;

int parent[MAX], size[MAX];

//find the parent
int find(int x) {
    return x == parent[x] ? x : parent[x] = find(parent[x]); // path compression
}

//union two nodes
void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return;
    if(size[a] < size[b]) swap(a,b); // union by rank
    size[a] += size[b];
    parent[b] = a;
}

// initialize the union find data structure
void init(int n) {
    for(int i = 0; i <= n; ++i) {
        parent[i] = i;
        size[i] = 1;
    }
}

int main() {
    int n = 5; // total number of nodes
    init(n);
    merge(1, 3);
    merge(5, 3);
    
    cout << "node\t" << "parent\n";
    for(int i = 1; i <= n; ++i) {
        cout << " " << i << "   ->   " << find(i) << '\n';
    }
    return 0;
}
