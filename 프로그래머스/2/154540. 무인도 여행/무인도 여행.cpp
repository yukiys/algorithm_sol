#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
bool visited[100][100];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(int, int, vector<string>&);

vector<int> solution(vector<string> maps) {
    vector<int> answer;

    N = maps.size();
    M = maps[0].size();

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if(!visited[i][j] and maps[i][j] != 'X')
                answer.push_back(bfs(i, j, maps));

    if(answer.empty())
        answer.push_back(-1);
    else
        sort(answer.begin(), answer.end());

    return answer;
}

int bfs(int a, int b, vector<string>& maps)
{
    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = true;

    int sum = maps[a][b] - '0';

    while(!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 or nx >= N or ny < 0 or ny >= M)
                continue;

            if(visited[nx][ny] or maps[nx][ny] == 'X')
                continue;

            q.push({nx, ny});
            visited[nx][ny] = true;
            sum += maps[nx][ny] - '0';
        }
    }

    return sum;
}