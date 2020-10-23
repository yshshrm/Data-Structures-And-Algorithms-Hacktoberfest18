//Find the number of islands

// Input
// 2
// 3 3
// 1 1 0 0 0 1 1 0 1
// 4 4
// 1 1 0 0 0 0 1 0 0 0 0 1 0 1 0 0

// Output
// 2
// 2

#include <bits/stdc++.h>
using namespace std;

int findIslands(vector<int> A[], int N, int M);

int main() {

    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<int> A[N];
        for (int i = 0; i < N; i++) {
            vector<int> temp(M);
            A[i] = temp;
            for (int j = 0; j < M; j++) {
                cin >> A[i][j];
            }
        }
        cout << findIslands(A, N, M) << endl;
    }
    return 0;
}

void dfs(vector<int> v[], int i,int j, vector<vector<bool>> &vis, int n, int m)
{
    vis[i][j] = true;
    
    int row[8] = {-1,1,0,1,-1,0,1,-1};
    int col[8] = {-1,1,1,0,0,-1,-1,1};
    
    for(int k=0;k<8;k++)
        {
            int x = i+row[k];
            int y = j+col[k];
            
            if(x>=n or y>=m or x<0 or y<0)
                continue;
            
            if(v[x][y]==0 or vis[x][y]==true)
                continue;
            
            else
            dfs(v,x,y,vis,n,m);
        }
}

int findIslands(vector<int> v[], int n, int m) 
{
    vector<vector<bool>>vis(n, vector<bool> (m,false));
    int count=0;
    
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(v[i][j]==1 and vis[i][j]==false)
            {
                count++;
                dfs(v,i,j,vis,n,m);
            }
        }
    }
    
    return count;
}
