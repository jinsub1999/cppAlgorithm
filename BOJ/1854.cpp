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
typedef pair<int, P> PQnode;

int main(void)
{
    fastIO;
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<P>> ADJ(n + 1);
    vector<priority_queue<int>> KthDist(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        ADJ[a].push_back({c, b});
    }

    priority_queue<P, vector<P>, greater<>> PQ;
    PQ.push({0, 1});
    while (!PQ.empty())
    {
        P p = PQ.top();
        PQ.pop();
        int totDist = p.first;
        int curr = p.second;
        if (KthDist[curr].size() < k)
        {
            KthDist[curr].push(totDist);
            for (auto elem : ADJ[curr])
            {
                int next = elem.second;
                int nextDist = elem.first;
                PQ.push({totDist + nextDist, next});
            }
        }
        else
            continue;
    }
    for (int i = 1; i <= n; i++)
    {
        if (KthDist[i].size() != k)
            cout << -1 << '\n';
        else
            cout << KthDist[i].top() << '\n';
    }
    return 0;
}