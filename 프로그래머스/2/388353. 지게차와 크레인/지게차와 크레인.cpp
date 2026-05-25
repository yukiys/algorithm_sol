#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int grid[52][52];
bool visited[52][52];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int, int, int);
void crane(int);

int solution(vector<string> storage, vector<string> requests) {
    N = storage.size();
    M = storage[0].size();
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            grid[i + 1][j + 1] = storage[i][j] - 'A' + 1;

    for(int i = 0; i < requests.size(); i++)
    {
        int target = requests[i][0] - 'A' + 1;
        if(requests[i].length() == 1)
            bfs(0, 0, target);
        else
            crane(target);
    }
    
    int answer = N * M;
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            if(grid[i][j] == 0)
                answer--;

    return answer;
}

void bfs(int a, int b, int target)
{
    memset(visited, 0, sizeof(visited));

    queue<pair<int, int>> q;
    q.push({a, b});
    visited[a][b] = true;

    while(!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(nx < 0 or nx > N + 1 or ny < 0 or ny > M + 1 or visited[nx][ny])
                continue;
            
            if(grid[nx][ny] == 0)
            {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
            else if(grid[nx][ny] == target)
            {
                visited[nx][ny] = true;
                grid[nx][ny] = 0;
            }
        }
    }
}

void crane(int target)
{
    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            if(grid[i][j] == target)
                grid[i][j] = 0;
}