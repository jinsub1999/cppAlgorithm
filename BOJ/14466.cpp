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

int dy[4] = {0, 1, -1, 0};
int dx[4] = {-1, 0, 0, 1};
int N, K, R;

bool OOB(int y, int x) { return y < 0 || x < 0 || y >= N || x >= N; }

typedef long long ll;
typedef pair<int, int> qn;

int bfs(int y, int x, vector<vector<bool>> &vis, vector<vector<int>> &v, vector<vector<int>> &road)
{
    queue<qn> Q;
    int ret = 0;
    Q.push({y, x});
    vis[y][x] = true;
    while (!Q.empty())
    {
        qn poped = Q.front();
        Q.pop();
        int ny = poped.first, nx = poped.second;
        if (v[ny][nx])
            ret++;
        for (int d = 0; d < 4; d++)
        {
            if (!OOB(ny + dy[d], nx + dx[d]) && (road[ny][nx] & (1 << d) && (!vis[ny + dy[d]][nx + dx[d]])))
            {
                Q.push({ny + dy[d], nx + dx[d]});
                vis[ny + dy[d]][nx + dx[d]] = true;
            }
        }
    }
    return ret;
}

int main(void)
{
    fastIO;

    cin >> N >> K >> R;
    vector<vector<int>> V(N, vector<int>(N));
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<vector<int>> bitsRoad(N, vector<int>(N, 15)); // 1111
    for (int i = 0; i < R; i++)
    {
        int r, c, r_, c_;
        cin >> r >> c >> r_ >> c_;
        r--, c--, r_--, c_--;
        for (int d = 0; d < 4; d++)
        {
            if (r_ - r == dy[d] && c_ - c == dx[d])
            {
                bitsRoad[r][c] = bitsRoad[r][c] & (~(1 << d));
                bitsRoad[r_][c_] = bitsRoad[r_][c_] & (~(1 << (3 - d)));
                break;
            }
        }
    }
    for (int i = 0; i < K; i++)
    {
        int r, c;
        cin >> r >> c;
        r--, c--;
        V[r][c]++;
    }
    vector<int> cows;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (!visited[i][j] && V[i][j])
                cows.push_back(bfs(i, j, visited, V, bitsRoad));

    int ans = 0;

    for (int i = 0; i < cows.size() - 1; i++)
        ans += cows[i] * accumulate(cows.begin() + i + 1, cows.end(), 0);

    cout << ans;

    return 0;
}