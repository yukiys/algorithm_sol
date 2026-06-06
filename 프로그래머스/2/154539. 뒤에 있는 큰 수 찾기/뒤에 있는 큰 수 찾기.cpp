#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer = vector<int>(numbers.size(), -1);

    stack<int> S;

    for(int i = 0; i < numbers.size(); i++)
    {
        int num = numbers[i];

        while(!S.empty() and numbers[S.top()] < num)
        {
            answer[S.top()] = num;
            S.pop();
        }

        S.push(i);
    }

    return answer;
}