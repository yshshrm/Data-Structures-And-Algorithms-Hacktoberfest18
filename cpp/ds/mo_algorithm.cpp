#include <iostream>
#include<bits/stdc++.h>
using namespace std;
// Mo's algorithm is a SQRT decomposition algorithm that
// solves some range queries problems offline in O((N+Q).sqrt(N))

// This code is an example of Mo's algorithm that requires
// for each query (L, R) to find the number of distinct values in the array from L to R.
// Other problems solved by Mo's algorithm have essentially similar code.
// What actually need to be changed are function insert and function remove below.

const int bsize=sqrt(100005);
int arr[100005], ans[100005],curAns;
int cnt[10000005];
int n, m ;
// Mo's query struct
struct Block
{
    int l, r, id;
}BL[100005];
bool cmp(Block a, Block b)
{
    if(a.l / bsize == b.l / bsize)
        return a.r / bsize < b.r / bsize;
    return a.l / bsize < b.l / bsize;
}

// Inserts the given index into our current answer
void insert(int k) {
    curAns += (++cnt[arr[k]] == 1);
}

// Removes the given index from our current answer
void remove(int k) {
    curAns -= (--cnt[arr[k]] == 0);
}

int main()
{
    cin >> n >> m;

    // Read problem data
    for (int i = 0; i < n; ++i) {
        scanf("%d", arr + i);
    }

    // Read problem queries
    for (int i = 0; i < m; ++i) {
        Block& q = BL[i];
        q.id = i;
        scanf("%d %d", &q.l, &q.r);
    }
//solve query
    sort(BL, BL + m, cmp);
    int l = 0, r = 0;

    for(int i = 0; i < m; i++)
    {
        while(l < BL[i].l)
            remove(l ++);
        while(l > BL[i].l)
            insert(-- l);
        while(r < BL[i].r)
            insert(++ r);
        while(r > BL[i].r)
            remove(r --);
        ans[BL[i].id] = curAns;
    }
    for(int i = 0; i < m; i++)
        cout << ans[i] << '\n';
}