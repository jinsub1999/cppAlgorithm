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
#include <bitset>
#include <string>

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
typedef pair<ll, ll> p;
typedef pair<p, int> PQnode;

vector<vector<p>> course;
vector<vector<ll>> lift;
vector<vector<bool>> visited;
vector<vector<ll>> dist;

int main(void)
{
    fastIO;
    ll n, m, k, s, t;

    cin >> n >> m >> k >> s >> t;

    course.resize(n + 1);
    lift.resize(n + 1);
    dist.resize(11, vector<ll>(n + 1, -1e9));
    visited.resize(11, vector<bool>(n + 1, false));

    dist[0][s] = 0;
    visited[0][s] = true;

    for (int i = 0; i < m; i++)
    {
        int a, b, t_;
        cin >> a >> b >> t_;
        course[b].push_back({t_, a});
        lift[a].push_back(b);
    }

    vector<ll> afterLifted(n + 1, -1e9);
    int lifttttt = 0;

    for (int lif = 0; lif <= k; lif++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (auto elem : course[i])
                if (dist[lif][elem.second] >= 0)
                    dist[lif][i] = max(dist[lif][i], elem.first + dist[lif][elem.second]);
        }
        if (lif < k)
            for (int i = 1; i <= n; i++)
            {
                for (auto elem : lift[i])
                    dist[lif + 1][i] = max(dist[lif][elem], dist[lif + 1][i]);
            }
    }

    ll ans = -1;

    for (int i = 0; i <= k; i++)
        ans = max(ans, dist[i][t]);

    cout << ans;

    return 0;
}