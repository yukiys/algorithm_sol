#include <string>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int N, M;
int dp[100][100];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int, int, const vector<string>&);

int solution(vector<string> board) {
    N = board.size();
    M = board[0].size();
    memset(dp, -1, sizeof(dp));

    pair<int, int> R, G;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(board[i][j] == 'R')
                R = {i, j};
            if(board[i][j] == 'G')
                G = {i, j};
        }
    }
    
    bfs(R.first, R.second, board);
    
    return dp[G.first][G.second];
}

void bfs(int a, int b, const vector<string>& board)
{
    queue<pair<int, int>> q;
    q.push({a, b});
    dp[a][b] = 0;

    while(!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x;
            int ny = y;
            while(1)
            {
                int tx = nx + dx[i];
                int ty = ny + dy[i];

                if(tx < 0 or tx >= N or ty < 0 or ty >= M or board[tx][ty] == 'D')
                    break;
                nx = tx;
                ny = ty;
            }
            if(dp[nx][ny] != -1)
                continue;
            
            q.push({nx, ny});
            dp[nx][ny] = dp[x][y] + 1;
        }
    }
}