#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int x, y;
    int num;
    int left, right;
};

vector<Node> bTree;

void insertNode(int, int);
void preOrder(int, vector<int>&);
void postOrder(int, vector<int>&);

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;

    for(int i = 0; i < nodeinfo.size(); i++)
    {
        bTree.push_back({
            nodeinfo[i][0], nodeinfo[i][1],
            i + 1,
            -1, -1
        });
    }

    sort(bTree.begin(), bTree.end(), [](const Node& a, const Node& b){
        if(a.y == b.y)
            return a.x < b.x;
        return a.y > b.y;
    });

    int root = 0;
    for(int i = 1; i < nodeinfo.size(); i++)
        insertNode(root, i);
    
    vector<int> pre;
    vector<int> post;

    preOrder(root, pre);
    postOrder(root, post);

    answer.push_back(pre);
    answer.push_back(post);

    return answer;
}

void insertNode(int parent, int child)
{
    if(bTree[child].x < bTree[parent].x)
    {
        if(bTree[parent].left == -1)
            bTree[parent].left = child;
        else
            insertNode(bTree[parent].left, child);
    }
    else
    {
        if(bTree[parent].right == -1)
            bTree[parent].right = child;
        else
            insertNode(bTree[parent].right, child);
    }
}

void preOrder(int cur, vector<int>& result)
{
    if(cur == -1)
        return;

    result.push_back(bTree[cur].num);
    preOrder(bTree[cur].left, result);
    preOrder(bTree[cur].right, result);
}

void postOrder(int cur, vector<int>& result)
{
    if(cur == -1)
        return;

    postOrder(bTree[cur].left, result);
    postOrder(bTree[cur].right, result);
    result.push_back(bTree[cur].num);
}