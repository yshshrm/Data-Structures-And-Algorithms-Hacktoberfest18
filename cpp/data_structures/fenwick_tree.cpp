#include <bits/stdc++.h>
using namespace std;
const int r = 1e5 + 5; // maximum array size.
long long n, arr[r], BIT[r];
long long get_sum(int idx){ // returns sum of 0....idx
    long long ret = 0;
    idx++;
    while (idx > 0){
        ret += BIT[idx];
        idx -= idx & (-idx);
    }
    return ret;
}
void update_idx(int idx, int val){
    idx++;
    while(idx <= n){
        BIT[idx] += val;
        idx += idx & (-idx);
    }
}
void build_bit(){
    for (int i = 0; i < n; i++)
        update_idx(i, arr[i]);
}
int main(){
    //test on size n.
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    build_bit(); // building BIT tree.
    for (int i = 0; i < n; i++) // printing prefixes sum from 0 to n - 1.
        cout << get_sum(i) << ' ';
    return 0;
}
