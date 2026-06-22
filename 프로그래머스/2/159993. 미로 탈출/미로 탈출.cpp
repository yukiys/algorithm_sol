#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
char grid[100][100];
int dp[100][100];
pair<int, int> Spos, Lpos, Epos;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(pair<int, int>, pair<int, int>);

int solution(vector<string> maps) {
    N = maps.size();
    M = maps[0].size();
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            grid[i][j] = maps[i][j];
            if(grid[i][j] == 'S')
                Spos = {i, j};
            else if(grid[i][j] == 'L')
                Lpos = {i, j};
            else if(grid[i][j] == 'E')
                Epos = {i, j};
        }
    }

    int d1 = bfs(Spos, Lpos);
    if(d1 == -1)
        return -1;

    int d2 = bfs(Lpos, Epos);
    if(d2 == -1)
        return -1;

    return d1 + d2;
}

int bfs(pair<int, int> start, pair<int, int> end)
{
    for(int i = 0; i < N; i++)
        fill(dp[i], dp[i] + M, -1);

    queue<pair<int, int>> q;
    q.push({start.first, start.second});
    dp[start.first][start.second] = 0;

    while(!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        if(x == end.first and y == end.second)
            return dp[x][y];

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 or nx >= N or ny < 0 or ny >= M)
                continue;

            if(grid[nx][ny] == 'X' or dp[nx][ny] != -1)
                continue;

            q.push({nx, ny});
            dp[nx][ny] = dp[x][y] + 1;
        }
    }

    return -1;
}