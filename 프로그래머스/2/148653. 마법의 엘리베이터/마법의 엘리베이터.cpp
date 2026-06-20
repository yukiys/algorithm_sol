#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;

    while(storey > 0)
    {
        int digit = storey % 10;
        int nextDigit = (storey / 10) % 10;

        if(digit < 5)
            answer += digit;
        else if(digit > 5)
        {
            answer += (10 - digit);
            storey += 10;
        }
        else
        {
            if(nextDigit >= 5)
                storey += 10;
                
            answer += 5;
        }

        storey /= 10;
    }

    return answer;
}