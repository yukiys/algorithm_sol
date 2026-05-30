#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> graph;
vector<long long> weight;
long long answer;

long long dfs(int, int);

long long solution(vector<int> a, vector<vector<int>> edges) {
    int n = a.size();

    long long sum = 0;
    weight.resize(n);
    for(int i = 0; i < n; i++)
    {
        weight[i] = a[i];
        sum += weight[i];
    }
    if(sum != 0)
        return -1;

    graph.assign(n, vector<int>());
    for(auto& edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(0, -1);

    return answer;
}

long long dfs(int cur, int parent)
{
    for(int next : graph[cur])
    {
        if(next == parent)
            continue;

        long long child = dfs(next, cur);

        weight[cur] += child;
        answer += llabs(child);
    }

    return weight[cur];
}