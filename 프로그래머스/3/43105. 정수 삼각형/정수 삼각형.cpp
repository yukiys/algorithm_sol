#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;

    vector<vector<int>> dp = triangle;
    for(int i = 1; i < triangle.size(); i++)
    {
        for(int j = 0; j < triangle[i].size(); j++)
        {
            if(j == 0)
                dp[i][j] += dp[i - 1][j];
            else if(j == triangle[i].size() - 1)
                dp[i][j] += dp[i - 1][j - 1];
            else
                dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j]);
        }
    }

    for(int j = 0; j < triangle[triangle.size() - 1].size(); j++)
        answer = max(answer, dp[triangle.size() - 1][j]);

    return answer;
}