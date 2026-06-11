#include <string>
#include <vector>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;

    vector<long long> count(1001, 0);
    for(int w : weights)
        count[w]++;

    for(int w = 100; w <= 1000; w++)
    {
        long long cnt = count[w];
        if(cnt == 0)
            continue;

        answer += cnt * (cnt - 1) / 2;

        int target;
        if((w * 3) % 2 == 0)
        {
            target = w * 3 / 2;
            if(target <= 1000)
                answer += cnt * count[target];
        }

        if((w * 4) % 3 == 0)
        {
            target = w * 4 / 3;
            if(target <= 1000)
                answer += cnt * count[target];
        }

        target = w * 2;
        if(target <= 1000)
            answer += cnt * count[target];
    }

    return answer;
}