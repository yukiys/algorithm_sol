#include <vector>
#include <cstring>

using namespace std;

int MOD = 20170805;
int dp[500][500][2];

int solution(int m, int n, vector<vector<int>> city_map) {
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = 1;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == 0 and j == 0)
                continue;

            if(city_map[i][j] == 1)
                continue;

            if(i != 0)
            {
                dp[i][j][0] = dp[i - 1][j][0];
                if(city_map[i - 1][j] != 2)
                    dp[i][j][0] += dp[i - 1][j][1];
                
                dp[i][j][0] %= MOD;
            }
            if(j != 0)
            {
                dp[i][j][1] = dp[i][j - 1][1];
                if(city_map[i][j - 1] != 2)
                    dp[i][j][1] += dp[i][j - 1][0];

                dp[i][j][1] %= MOD;
            }
        }
    }

    int answer = (dp[m - 1][n - 1][0] + dp[m - 1][n - 1][1]) % MOD;
    return answer;
}