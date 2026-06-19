#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> dp(1000001, -1);
int Y, N;

void bfs(int);

int solution(int x, int y, int n) {
    Y = y, N = n;
    
    bfs(x);
    
    return dp[y];
}

void bfs(int x)
{
    queue<int> q;
    q.push(x);
    dp[x] = 0;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        if(cur == Y)
            break;

        int next;
        next = cur * 2;
        if(next <= Y and dp[next] == -1)
        {
            dp[next] = dp[cur] + 1;
            q.push(next);
        }

        next = cur * 3;
        if(next <= Y and dp[next] == -1)
        {
            dp[next] = dp[cur] + 1;
            q.push(next);
        }

        next = cur + N;
        if(next <= Y and dp[next] == -1)
        {
            dp[next] = dp[cur] + 1;
            q.push(next);
        }
    }
}