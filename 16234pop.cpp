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
#include <cassert>
using namespace std;

typedef long long ll;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)

int N, L, R;

bool OOB(int y, int x)
{
    return y < 0 || x < 0 || y >= N || x >= N;
}

int dfs(int y, int x, vector<vector<bool>> &vis, vector<pair<int, int>> &V, vector<vector<int>> &land)
{
    int ret = land[y][x];
    for (int d = 0; d < 4; d++)
    {
        if (!OOB(y + dy[d], x + dx[d]) && !vis[y + dy[d]][x + dx[d]])
        {
            int AB = land[y + dy[d]][x + dx[d]] - land[y][x];
            AB = abs(AB);
            if (AB >= L && AB <= R)
            {
                vis[y + dy[d]][x + dx[d]] = true;
                V.push_back({y + dy[d], x + dx[d]});
                ret += dfs(y + dy[d], x + dx[d], vis, V, land);
            }
        }
    }
    return ret;
}

int main(void)
{
    fastIO;

    cin >> N >> L >> R;
    vector<vector<int>> land(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> land[i][j];

    bool flag = true;
    int cnt = 0;
    while (flag)
    {
        flag = false;
        vector<vector<bool>> VIS(N, vector<bool>(N, false));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (!VIS[i][j])
                {
                    VIS[i][j] = true;
                    vector<pair<int, int>> Q(1, {i, j});
                    dfs(i, j, VIS, Q, land);
                    if (Q.size() != 1)
                    {
                        flag = true;
                        int SUMM = 0;
                        for (auto elem : Q)
                        {
                            int Y = elem.first, X = elem.second;
                            SUMM += land[Y][X];
                        }
                        SUMM /= Q.size();

                        for (auto elem : Q)
                        {
                            int Y = elem.first, X = elem.second;
                            land[Y][X] = SUMM;
                        }
                    }
                }
        if (flag)
            cnt++;
    }
    cout << cnt;
    return 0;
}