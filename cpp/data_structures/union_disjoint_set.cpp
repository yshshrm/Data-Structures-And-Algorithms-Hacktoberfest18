/**
 * This is implementation of Disjoint Set Union data structure.
 * See https://en.wikipedia.org/wiki/Disjoint-set_data_structure 
 */

#include<iostream>
#include<cstdio>
#include<vector>

using namespace std;

#define ii pair<int, int>

class DisjointSet {
    private:
        vector<int> parent, rank;
    public:
        DisjointSet(int n) {
            rank.assign(n, 0);
            parent.assign(n, 0);
            for(int i = 0; i < n; i++)
                parent[i] = i;
        }

        int findSet(int i) {
            return (parent[i] == i) ? i : parent[i] = findSet(parent[i]);
        }

        bool isSameSet(int i, int j) {
            return findSet(i) == findSet(j);
        }

        void unionSet(int i, int j) {
            if (!isSameSet(i, j)) {
                int a = findSet(i);
                int b = findSet(j);
                if (rank[a] > rank[b]) {
                    parent[b] = a;
                }
                else {
                    parent[a] = b;
                    if (rank[a] == rank[b])
                        rank[b]++;
                }
            }
        }
};

int main() {
    DisjointSet disjointSet(10);
    
    //merge set 0 and set 1
    disjointSet.unionSet(0, 1);

    //find set id given member
    cout<<disjointSet.findSet(0)<<endl;
    cout<<disjointSet.findSet(1)<<endl;
    cout<<disjointSet.findSet(3)<<endl;
    
    //check if 2 member belong to same set
    cout<<disjointSet.isSameSet(0, 1)<<endl;
    cout<<disjointSet.isSameSet(0, 2)<<endl;
    
    return 0;
}