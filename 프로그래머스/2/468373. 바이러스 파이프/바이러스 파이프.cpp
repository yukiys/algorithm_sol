#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, K, answer;

vector<int> graph[4][101];
vector<int> reach[4][101];

void makeReach(int, int, vector<int>&, vector<int>&);
int count(const vector<int>&);
vector<int> spread(const vector<int>&, int);
void dfs(int, vector<int>);

int solution(int n, int infection, vector<vector<int>> edges, int k)
{
    N = n, K = k, answer = 1;

    for(auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int type = edge[2];

        graph[type][u].push_back(v);
        graph[type][v].push_back(u);
    }

    for(int type = 1; type <= 3; type++)
    {
        for(int start = 1; start <= N; start++)
        {
            vector<int> visited(N + 1, 0);
            makeReach(type, start, visited, reach[type][start]);
        }
    }

    vector<int> infected(N + 1, 0);
    infected[infection] = 1;

    dfs(0, infected);

    return answer;
}

void makeReach(int type, int cur, vector<int>& visited, vector<int>& result)
{
    visited[cur] = 1;
    result.push_back(cur);

    for(int i : graph[type][cur])
        if(!visited[i])
            makeReach(type, i, visited, result);
}

int count(const vector<int>& infected)
{
    int cnt = 0;
    for(int i = 1; i <= N; i++)
        if(infected[i])
            cnt++;
    return cnt;
}

vector<int> spread(const vector<int>& infected, int type)
{
    vector<int> next = infected;

    for(int node = 1; node <= N; node++)
    {
        if(!infected[node])
            continue;

        for(int r : reach[type][node])
            next[r] = 1;
    }

    return next;
}

void dfs(int depth, vector<int> infected)
{
    answer = max(answer, count(infected));

    if(depth == K)
        return;
    if(answer == N)
        return;

    for(int type = 1; type <= 3; type++)
    {
        vector<int> next = spread(infected, type);

        if(next == infected)
            continue;

        dfs(depth + 1, next);
    }
}