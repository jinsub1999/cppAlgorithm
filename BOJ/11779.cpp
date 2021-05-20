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

int main(void)
{
    fastIO;

    int n, m;
    cin >> n >> m;
    vector<vector<P>> graph(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b, d;
        cin >> a >> b >> d;
        graph[a].push_back({d, b});
    }

    int s, e;
    cin >> s >> e;
    vector<int> previous(n + 1, -1);
    vector<int> Distance(n + 1, (int)1e9);
    Distance[s] = 0;
    priority_queue<P, vector<P>, greater<>> PQ;

    PQ.push({0, s});
    while (!PQ.empty())
    {
        P p = PQ.top();
        PQ.pop();
        int curr = p.second;

        for (auto elem : graph[curr])
        {
            int next = elem.second;
            int nextdist = elem.first;
            if (Distance[next] > nextdist + Distance[curr])
            {
                Distance[next] = nextdist + Distance[curr];
                PQ.push({Distance[next], next});
                previous[next] = curr;
            }
        }
    }
    cout << Distance[e] << '\n';
    stack<int> St;
    int bt = e;
    while (bt != s)
    {
        St.push(bt);
        bt = previous[bt];
    }
    St.push(s);
    cout << St.size() << '\n';
    while (!St.empty())
    {
        cout << St.top() << ' ';
        St.pop();
    }

    return 0;
}