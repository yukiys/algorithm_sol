#include <vector>
#include <string>
using namespace std;

const int INF = 1e9;

int solution(vector<string> arr)
{
    int N = arr.size() / 2 + 1;

    vector<int> nums(N);
    vector<char> ops(N - 1);

    for(int i = 0; i < N; i++)
        nums[i] = stoi(arr[2 * i]);

    for(int i = 0; i < N - 1; i++)
        ops[i] = arr[2 * i + 1][0];

    vector<vector<int>> minDP(N, vector<int>(N, INF));
    vector<vector<int>> maxDP(N, vector<int>(N, -INF));

    for(int i = 0; i < N; i++)
        minDP[i][i] = maxDP[i][i] = nums[i];

    for(int len = 2; len <= N; len++)
    {
        for(int l = 0; l + len - 1 < N; l++)
        {
            int r = l + len - 1;

            for(int i = l; i < r; i++)
            {
                if(ops[i] == '+')
                {
                    int maxValue = maxDP[l][i] + maxDP[i + 1][r];
                    int minValue = minDP[l][i] + minDP[i + 1][r];

                    maxDP[l][r] = max(maxDP[l][r], maxValue);
                    minDP[l][r] = min(minDP[l][r], minValue);
                }
                else
                {
                    int maxValue = maxDP[l][i] - minDP[i + 1][r];
                    int minValue = minDP[l][i] - maxDP[i + 1][r];

                    maxDP[l][r] = max(maxDP[l][r], maxValue);
                    minDP[l][r] = min(minDP[l][r], minValue);
                }
            }
        }
    }
        
    return maxDP[0][N - 1];
}