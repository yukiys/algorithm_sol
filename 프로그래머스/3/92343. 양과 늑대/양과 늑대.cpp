#include <string>
#include <vector>

using namespace std;

vector<int> animal;
vector<vector<int>> child;
int answer;

void dfs(int, int, vector<int>);

int solution(vector<int> info, vector<vector<int>> edges) {
    animal = info;
    child.assign(animal.size(), vector<int>());
    
    for(auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];

        child[u].push_back(v);
    }

    vector<int> candidates;
    for(int next : child[0])
        candidates.push_back(next);

    dfs(1, 0, candidates);

    return answer;
}

void dfs(int sheep, int wolf, vector<int> candidates)
{
    if(answer < sheep)
        answer = sheep;

    for(int i = 0; i < candidates.size(); i++)
    {
        int now = candidates[i];

        int nextSheep = sheep;
        int nextWolf = wolf;

        if(animal[now] == 0)
            nextSheep++;
        else
            nextWolf++;

        if(nextWolf >= nextSheep)
            continue;
        
        vector<int> nextCandidates = candidates;
        nextCandidates.erase(nextCandidates.begin() + i);

        for(int next : child[now])
            nextCandidates.push_back(next);

        dfs(nextSheep, nextWolf, nextCandidates);
    }
}