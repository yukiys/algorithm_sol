#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string toBinary(long long);
bool isValid(const string&, int, int);

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;

    for(long long num : numbers)
    {
        string bin = toBinary(num);
        int len = 1;
        while(len < bin.size())
            len = len * 2 + 1;

        string tree = string(len - bin.size(), '0') + bin;

        if(isValid(tree, 0, tree.size() - 1))
            answer.push_back(1);
        else
            answer.push_back(0);
    }

    return answer;
}

string toBinary(long long num)
{
    string result = "";
    while(num > 0)
    {
        result += (num % 2) + '0';
        num /= 2;
    }

    reverse(result.begin(), result.end());
    return result;
}

bool isValid(const string& tree, int left, int right)
{
    if(left == right)
        return true;
        
    int mid = (left + right) / 2;
    if(tree[mid] == '0')
    {
        for(int i = left; i <= right; i++)
            if(tree[i] == '1')
                return false;

        return true;
    }

    return isValid(tree, left, mid - 1) && isValid(tree, mid + 1, right);
}