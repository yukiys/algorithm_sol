#include<vector>
#include <algorithm>
using namespace std;

int n, N;
int targetIdx;
long long target, answer;

long long solution(vector<vector<int> > land, int P, int Q) {    
    n = land.size();
    N = n * n;

    vector<int> arr;
    arr.reserve(N);

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            arr.push_back(land[i][j]);

    for(int i = 0; i < N; i++)
    {
        if(P * (i + 1) >= Q * (N - i - 1))
        {
            targetIdx = i;
            break;
        }
    }
    
    nth_element(arr.begin(), arr.begin() + targetIdx, arr.end());

    target = arr[targetIdx];
    for(int i = 0; i < N; i++)
    {
        if(arr[i] < target)
            answer += 1LL * P * (target - arr[i]);
        else
            answer += 1LL * Q * (arr[i] - target);
    }

    return answer;
}