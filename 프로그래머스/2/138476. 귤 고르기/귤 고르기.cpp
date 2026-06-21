#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;

    unordered_map<int, int> cnt;
    for(int t : tangerine)
        cnt[t]++;

    vector<int> counts;
    for(auto c : cnt)
        counts.push_back(c.second);

    sort(counts.begin(), counts.end(), greater<int>());

    int sum = 0;
    for(int count : counts)
    {
        sum += count;
        answer++;

        if(sum >= k)
            return answer;
    }
}