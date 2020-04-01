#include <bits/stdc++.h>
using namespace std;

int *seg, *arr;

void build(int pos, int lo, int hi)
{
    if (lo == hi)
    {
        seg[pos] = arr[hi];
    }
    else
    {
        int mid = (lo + hi) / 2;
        build(2 * pos, lo, mid);
        build((2 * pos) + 1, mid + 1, hi);
        seg[pos] = seg[2 * pos] + seg[(2 * pos) + 1];
    }
}

int query(int pos, int l, int r, int lo, int hi)
{
    int sum = 0;
    if (lo > r || hi < l)
    {
        return 0;
    }
    else if (l <= lo && r >= hi)
    {
        return seg[pos];
    }
    else
    {
        int mid = (lo + hi) / 2;
        sum += query(2 * pos, l, r, lo, mid);
        sum += query((2 * pos) + 1, l, r, mid + 1, hi);
        return sum;
    }
}

void update(int pos, int lo, int hi, int i, int val)
{
    if (lo == i && hi == i)
    {
        seg[pos] = val;
        return;
    }
    else
    {
        if(lo > i || hi < i) {
            return;
        }
        int mid = (lo + hi) / 2;
        update(2 * pos, lo, mid, i, val);
        update((2 * pos) + 1, mid + 1, hi, i, val);
        seg[pos] = seg[2 * pos] + seg[(2 * pos) + 1];
    }
}

int main()
{
    int N;
    cin >> N;
    arr = new int[N + 1];
    seg = new int[4 * N];

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    build(1, 1, N);

    int q;
    cout << "Enter the no. of queries: ";
    cin >> q;
    while (q--)
    {
        int i, val;
        cin >> i >> val;
        update(1, 1, N, i, val);
    }
}