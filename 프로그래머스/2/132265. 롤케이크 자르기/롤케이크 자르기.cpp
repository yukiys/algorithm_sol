#include <string>
#include <vector>

using namespace std;

int left[10001], right[10001];
int leftCnt, rightCnt;

int solution(vector<int> topping) {
    int answer = 0;

    for(int x : topping)
        if(left[x]++ == 0)
            leftCnt++;

    for(int i = 0; i < topping.size() - 1; i++)
    {
        int x = topping[i];

        if(right[x]++ == 0)
            rightCnt++;

        if(--left[x] == 0)
            leftCnt--;

        if(leftCnt == rightCnt)
            answer++;
    }

    return answer;
}