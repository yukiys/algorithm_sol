#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
using ll = long long;

ll normalize(ll x, ll m)
{
    if((x %= m) < 0)
        x += m;
    return x;
}

ll extendedGCD(ll a, ll b, ll& x, ll& y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1;
    ll g = extendedGCD(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return g;
}

bool crtMerge(ll a1, ll m1, ll a2, ll m2, ll& mergedA, ll& mergedM)
{
    ll g = gcd(m1, m2);
    ll diff = a2 - a1;

    if(diff % g != 0)
        return false;

    ll p = m1 / g;
    ll q = m2 / g;

    ll x, y;
    extendedGCD(p, q, x, y);

    ll inv = normalize(x, q);
    ll k = normalize((diff / g) * inv , q);

    mergedM = m1 * q;
    mergedA = normalize(a1 + m1 * k, mergedM);

    return true;
}

int solution(vector<vector<int>> signals) {
    ll answer = -1;

    vector<pair<ll, ll>> candidates;
    candidates.push_back({0, 1});

    for(auto& signal : signals)
    {
        int G = signal[0];
        int Y = signal[1];
        int R = signal[2];

        ll period = G + Y + R;

        vector<pair<ll, ll>> nextCandidates;
        for(auto [curA, curM] : candidates)
        {
            for(int i = 1; i <= Y; i++)
            {
                ll yellowA = G + i;

                ll mergedA, mergedM;
                if(crtMerge(curA, curM, yellowA, period, mergedA, mergedM))
                    nextCandidates.push_back({mergedA, mergedM});
            }
        }

        sort(nextCandidates.begin(), nextCandidates.end());
        nextCandidates.erase(unique(nextCandidates.begin(), nextCandidates.end()), nextCandidates.end());

        candidates = nextCandidates;
        if(candidates.empty())
            return -1;
    }

    for(auto [a, m] : candidates)
    {
        ll temp = (a == 0 ? m : a);

        if(answer == -1 or temp < answer)
            answer = temp;
    }

    return (int)answer;
}