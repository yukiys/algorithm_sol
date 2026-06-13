#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int yw = yellow, yh = 1;
    while(1)
    {
        int temp = 2 * yw + 2 * yh + 4;
        if(brown == temp)
        {
            answer.push_back(yw + 2);
            answer.push_back(yh + 2);
            break;
        }

        yh++;
        while(yellow % yh != 0)
            yh++;

        yw = yellow / yh;
    }

    return answer;
}