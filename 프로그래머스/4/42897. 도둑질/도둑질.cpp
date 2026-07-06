#include <string>
#include <vector>

using namespace std;

int dp1[1000001];
int dp2[1000001];

int solution(vector<int> money) {
    int n = money.size();

    dp1[0] = money[0];
    dp1[1] = max(money[0], money[1]);
    for(int i = 2; i < n - 1; i++)
        dp1[i] = max(dp1[i - 1], dp1[i - 2] + money[i]);

    dp2[1] = money[1];
    for(int i = 2; i < n; i++)
        dp2[i] = max(dp2[i - 1], dp2[i - 2] + money[i]);

    return max(dp1[n - 2], dp2[n - 1]);
}