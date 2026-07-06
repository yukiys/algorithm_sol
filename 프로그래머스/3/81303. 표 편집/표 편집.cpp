#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    vector<int> prev(n), next(n);
    stack<int> S;

    for(int i = 0; i < n; i++)
    {
        prev[i] = i - 1;
        next[i] = i + 1;
    }
    next[n - 1] = -1;

    int cur = k;
    for(const string& c : cmd)
    {
        if(c[0] == 'U')
        {
            int x = stoi(c.substr(2));
            for(int i = 0; i < x; i++)
                cur = prev[cur];
        }
        else if(c[0] == 'D')
        {
            int x = stoi(c.substr(2));
            for(int i = 0; i < x; i++)
                cur = next[cur];
        }
        else if(c[0] == 'C')
        {
            S.push(cur);

            int P = prev[cur];
            int N = next[cur];
            if(P != -1)
                next[P] = N;
            if(N != -1)
                prev[N] = P;

            if(N != -1)
                cur = N;
            else
                cur = P;
        }
        else
        {
            int z = S.top();
            S.pop();

            int P = prev[z];
            int N = next[z];
            if(P != -1)
                next[P] = z;
            if(N != -1)
                prev[N] = z;
        }
    }

    string answer(n, 'O');
    while(!S.empty())
    {
        answer[S.top()] = 'X';
        S.pop();
    }

    return answer;
}