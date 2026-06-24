#include <string>
#include <vector>

using namespace std;

int N, T;
vector<int> Nums;

int dfs(int, int);

int solution(vector<int> numbers, int target) {
    N = numbers.size();
    T = target;
    Nums = numbers;

    return dfs(0, 0);
}

int dfs(int idx, int total)
{
    if(idx == N)
    {
        if(total == T)
            return 1;
        return 0;
    }
        
    return dfs(idx + 1, total + Nums[idx]) + dfs(idx + 1, total - Nums[idx]);
}