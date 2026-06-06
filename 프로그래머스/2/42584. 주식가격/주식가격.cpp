#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer = vector<int>(n, 0);

    stack<int> S;

    for(int i = 0; i < n; i++)
    {
        int price = prices[i];

        while(!S.empty() and prices[S.top()] > price)
        {
            int idx = S.top();
            S.pop();

            answer[idx] = i - idx;
        }

        S.push(i);
    }

    while(!S.empty())
    {
        int idx = S.top();
        S.pop();

        answer[idx] = n - 1 - idx;
    }

    return answer;
}