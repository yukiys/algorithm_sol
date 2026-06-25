#include <string>
#include <vector>

const int MOD = 1000000007;

using namespace std;

int dp[101][101];

int solution(int m, int n, vector<vector<int>> puddles) {
    for(int i = 0; i < puddles.size(); i++)
        dp[puddles[i][1]][puddles[i][0]] = -1;

    dp[1][1] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(dp[i][j] == -1)
                continue;

            int a = (dp[i - 1][j] != -1 ? dp[i - 1][j] : 0);
            int b = (dp[i][j - 1] != -1 ? dp[i][j - 1] : 0);
            
            dp[i][j] += (a + b);
            dp[i][j] %= MOD;
        }
    }

    return dp[n][m];
}