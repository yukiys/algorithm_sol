#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> nums;
    for(int n : numbers)
        nums.push_back(to_string(n));

    sort(nums.begin(), nums.end(), [](const string& a, const string& b){
        return a + b > b + a;
    });

    if(nums[0] == "0")
        return "0";

    for(const string& s : nums)
        answer += s;

    return answer;
}