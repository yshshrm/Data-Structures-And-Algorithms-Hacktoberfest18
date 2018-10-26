
#include<cstdio>
#include<queue>
#include<iostream>
using namespace std;

int maze[1000][1000]; /*input maze*/
int points = 1;
int BFS(int n, int sx, int sy) {
    int dr[] = {-1 ,0 ,1 , 0}; /*row movements*/
    int dc[] = { 0 ,1 ,0 ,-1}; /*col movements*/


    int inf=(1LL << 31)-1;
    int dist[n][n];
    for(int i=0; i<n; i++)
        for (int j=0;j<n;j++)
            dist[i][j] = inf;

    queue<int> q;

    dist[sx][sy] = 0;
    q.push(sx);
    q.push(sy);
    while( !q.empty() )
    {

        int x = q.front(); q.pop();
        int y = q.front(); q.pop();
  int f = 0;
        for(int i=0; i<4; i++)
        {

            int r = x + dr[i];
            int c = y + dc[i];


            if (r>=0 && c>=0 && r<n && c<n)
            {
                    if( dist[r][c] == inf && maze[r][c]>=0)
                    {
                        dist[r][c] = dist[x][y] + 1;

                      if (maze[r][c] == 0) {
                            return points;


                        }

                        q.push(r);
                        q.push(c);
                    }
               return -1;
            }

        }



    }


}
int main() {
    int sz;
    scanf("%d", &sz);

    int meR, meC;

    for (int i=0; i<sz; i++){
        for (int j=0; j<sz; j++) {
            int x; cin>>x;
            maze[i][j] = x;


        }
    }
    maze[0][0]=1;

    int ans;
    ans = BFS(sz, 0, 0);

    cout<<"\nhealth point is "<<ans<<endl;

    return 0;
}
