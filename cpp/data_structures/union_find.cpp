#include <iostream>
#include<bits/stdc++.h>

using namespace std;
class UnionFind {
private:
    vector<int> parent, rank;


public:
    //initialize n-sets
    UnionFind(int N) {

        parent.assign(N+9, 0);
        for (int i = 0; i < N; i++) {
            parent[i] = i;


        }
    }
    //return id of given element
    int find(int i) {
        while(i != parent[i]) i = parent[i];
        return i;
    }
//check if given element in same set
    bool isSameSet(int i, int j) {
        return find(i) == find(j);
    }
//union both elemts if they are not in same set
    void unionSet (int i, int j, int w) {
        if (isSameSet(i, j)) return;
        int x = find(i), y = find(j);
        if (rank[x] < rank[y]) swap(x,y);
        parent[y] = x;

        if (rank[x] == rank[y]) rank[x]++;
    }
};

