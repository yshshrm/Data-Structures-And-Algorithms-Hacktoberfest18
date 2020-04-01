#include <iostream>
#include <cstring>
using namespace std;
int memo[205][205][205];
int LCS3str(string a, string b, string c, int m, int n, int o){
    if(m==0||n==0||o==0){
        return 0;
    }
    if(memo[m-1][n-1][o-1]!= -1) return memo[m-1][n-1][o-1];
    
    if(a[m-1] == b[n-1] && b[n-1] == c[o-1]){
        memo[m-1][n-1][o-1] = 1 + LCS3str(a, b, c, m-1, n-1, o-1);
    }
    else{
        memo[m-1][n-1][o-1] = max(LCS3str(a, b, c, m-1, n, o), max(LCS3str(a, b, c, m, n-1, o), LCS3str(a, b, c, m, n, o-1)));
    }
    
    return memo[m-1][n-1][o-1];
}
//bottom up
int LCS3str_BU(string a, string b, string c, int m, int n, int o){
    int dp[m+1][n+1][o+1];
    memset(dp, 0, sizeof(dp));
    
    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=o; k++){
                if(a[i-1]==b[j-1] && b[j-1]==c[k-1]){
                    dp[i][j][k] = 1+dp[i-1][j-1][k-1];
                }
                else{
                    dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
                }
            }
        }
    }
    return dp[m][n][o];
}
int main() {
	string a, b, c;
	cin>>a>>b>>c;
	int m = a.size();
	int n = b.size();
	int o = c.size();
	memset(memo, -1, sizeof(memo));
	cout<<LCS3str_BU(a, b, c, m, n, o);
	return 0;
}