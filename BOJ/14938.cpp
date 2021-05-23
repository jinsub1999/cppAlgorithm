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

typedef pair<int, int> P;
typedef long long ll;
int n, m, r;

int dijk(int start, vector<int> &items, vector<vector<P>> &adj)
{
    vector<int> DIST(n + 1, (int)1e9);
    DIST[start] = 0;
    priority_queue<P, vector<P>, greater<>> PQ;
    vector<bool> visited(n + 1, false);
    visited[start] = true;
    PQ.push({0, start});
    while (!PQ.empty())
    {
        P p = PQ.top();
        PQ.pop();
        int curr = p.second;
        int currdist = p.first;
        for (auto elem : adj[curr])
        {
            if (currdist + elem.first <= m && DIST[elem.second] > currdist + elem.first)
            {
                DIST[elem.second] = currdist + elem.first;
                PQ.push({DIST[elem.second], elem.second});
                visited[elem.second] = true;
            }
        }
    }
    int ret = 0;
    for (int i = 1; i <= n; i++)
        if (visited[i])
            ret += items[i];
    return ret;
}

int main(void)
{
    fastIO;
    cin >> n >> m >> r;
    vector<int> V(n + 1);
    vector<vector<P>> ADJ(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> V[i];
    for (int i = 0; i < r; i++)
    {
        int a, b, l;
        cin >> a >> b >> l;
        ADJ[a].push_back({l, b});
        ADJ[b].push_back({l, a});
    }
    int maxi = -1;
    for (int i = 1; i <= n; i++)
        maxi = max(maxi, dijk(i, V, ADJ));
    cout << maxi;
    return 0;
}