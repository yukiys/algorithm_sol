#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> clothes(n + 1, 1);
    
    for(int l : lost)
        clothes[l]--;
    for(int r : reserve)
        clothes[r]++;

    for(int i = 1; i <= n; i++)
    {
        if(clothes[i] == 0)
        {
            if(i > 1 and clothes[i - 1] == 2)
            {
                clothes[i]++;
                clothes[i - 1]--;
            }
            else if(i < n and clothes[i + 1] == 2)
            {
                clothes[i]++;
                clothes[i + 1]--;
            }
        }
    }

    for(int i = 1; i <= n; i++)
        if(clothes[i] >= 1)
            answer++;

    return answer;
}