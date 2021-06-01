#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <set>
#include <deque>
#include <numeric>
#include <iterator>
#include <map>
#include <cmath>

using namespace std;
#define PI 3.14159265358979323846
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)

// int dy[4] = {0, 0, -1, 1};
// int dx[4] = {-1, 1, 0, 0};
// bool OOB(int y, int x, int N){return y < 0 || x < 0 || y >= N || x >= N;}

typedef long long ll;
typedef pair<int, int> P;

int n, m, x;

vector<int> dijk(int start, vector<vector<P>> &ADJ)
{
    priority_queue<P, vector<P>, greater<>> PQ;
    vector<int> DIST(n + 1, (int)1e9);
    DIST[start] = 0;
    PQ.push({0, start});
    while (!PQ.empty())
    {
        P p = PQ.top();
        PQ.pop();
        int curr = p.second;
        for (auto elem : ADJ[curr])
        {
            int nextV = elem.second;
            int nextD = elem.first;
            if (DIST[nextV] > DIST[curr] + nextD)
            {
                DIST[nextV] = DIST[curr] + nextD;
                PQ.push({DIST[nextV], nextV});
            }
        }
    }

    return DIST;
}

int main(void)
{
    fastIO;
    cin >> n >> m >> x;
    vector<vector<P>> adj(n + 1);
    vector<vector<P>> rev_adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, t;
        cin >> a >> b >> t;
        adj[a].push_back({t, b});
        rev_adj[b].push_back({t, a});
    }
    auto toParty = dijk(x, rev_adj);
    auto toHome = dijk(x, adj);
    int maxi = -1;
    for (int i = 1; i <= n; i++)
        maxi = max(maxi, toParty[i] + toHome[i]);
    cout << maxi;
    return 0;
}