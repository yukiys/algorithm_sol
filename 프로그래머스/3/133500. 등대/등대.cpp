#include <string>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> dp;
vector<int> visited;

void dfs(int);

int solution(int n, vector<vector<int>> lighthouse) {
    graph.assign(n + 1, vector<int>());
    dp.assign(n + 1, vector<int>(2, 0));
    visited.assign(n + 1, 0);

    for(auto& edge : lighthouse)
    {
        int a = edge[0];
        int b = edge[1];

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);

    return min(dp[1][0], dp[1][1]);
}

void dfs(int start)
{
    visited[start] = 1;

    dp[start][0] = 0;
    dp[start][1] = 1;

    for(int next : graph[start])
    {
        if(visited[next])
            continue;

        dfs(next);

        dp[start][0] += dp[next][1];
        dp[start][1] += min(dp[next][0], dp[next][1]);
    }
}