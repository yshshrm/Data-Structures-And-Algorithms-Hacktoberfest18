using namespace std;
#include <bits/stdc++.h>

vector<vector<int>> adj;
vector<vector<int>> rev_adj;
vector<int> C;
vector<pair<int, int>> F;
vector<int> S;
int t=0;
vector<int> temp;

void DFS(int e)
{
    C[e] = 1;
    S[e] = ++t;
    for (auto i: adj[e]) {
        if (C[i] == 0) {
            DFS(i);
        }
    }
    F[e].first = e;
    F[e].second = ++t;
    C[e] = 2;
}

void DFS_rev(int e) {
    C[e] = 1;
    temp.push_back(e);
    for (auto i: rev_adj[e]) {
        if (C[i] == 0) {
            DFS_rev(i);
        }
    }
    C[e] = 2;
}

bool comp(pair<int, int>a, pair<int, int>b) {
    return a.second > b.second;
}
int main()

{
    int N, M;
    cin >> N >> M;
    adj.resize(N + 1);
    C.resize(N + 1, 0);
    rev_adj.resize(N+1);
    S.resize(N+1);
    F.resize(N+1);

    for (int i = 1; i <= M; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
    {
        if (C[i] == 0)
        {
            DFS(i);
        }
    }
    
    sort(F.begin()+1, F.end(),comp);
    C.assign(N+1, 0);

    for(int i = 1; i<=N; i++) {
        if(C[F[i].first] == 0) {
            DFS_rev(F[i].first);
            for(auto i:temp) {
                cout << i <<" ";
            }
            cout << "     ";
            temp.clear();
        }
    }
    cout << endl;

    return 0;
}