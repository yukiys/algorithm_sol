#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;

    long long start = a < b ? a : b;
    long long end = a > b ? a : b;
    
    answer = (start + end) * (end - start + 1) / 2;

    return answer;
}