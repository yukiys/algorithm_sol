#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    for(char n : number)
    {
        while(!answer.empty() and k > 0 and answer.back() < n)
        {
            answer.pop_back();
            k--;
        }
        answer.push_back(n);
    }

    if(k > 0)
        answer.erase(answer.end() - k, answer.end());

    return answer;
}