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
using namespace std;
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)

typedef long long ll;

int dy[4] = {0, 0, 1, -1};
int dx[4] = {-1, 1, 0, 0};
vector<vector<int>> roads(500, vector<int>(500, 0));
vector<vector<ll>> DP(500, vector<ll>(500, -1));
vector<vector<bool>> visited(500, vector<bool>(500, 0));
int M, N;

bool OOB(int y, int x, int m, int n) { return y < 0 || x < 0 || y >= m || x >= n; }

ll DFS(int y, int x)
{
    ll &ret = DP[y][x];
    if (y == M - 1 && x == N - 1)
    {
        ret = 1;
        return 1;
    }
    if (ret != -1)
        return ret;
    ret = 0;
    for (int d = 0; d < 4; d++)
    {
        if (!OOB(y + dy[d], x + dx[d], M, N) && roads[y][x] > roads[y + dy[d]][x + dx[d]])
            ret += DFS(y + dy[d], x + dx[d]);
    }
    return ret;
}

int main(void)
{
    fastIO;

    cin >> M >> N;

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> roads[i][j];
    }

    DFS(0, 0);
    cout << DP[0][0];
    return 0;
}