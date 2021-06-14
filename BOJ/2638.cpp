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

int N, M;
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
bool OOB(int y, int x) { return y < 0 || x < 0 || y >= N || x >= M; }

typedef long long ll;

void bfs(vector<vector<bool>> &Map)
{
    queue<pair<int, int>> Q;
    vector<vector<int>> aired(N, vector<int>(M, 0));
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    Q.push({0, 0});
    visited[0][0] = true;

    while (!Q.empty())
    {
        auto P = Q.front();
        Q.pop();
        int ny = P.first, nx = P.second;

        for (int d = 0; d < 4; d++)
        {
            int _dy = dy[d], _dx = dx[d];
            int _ny = ny + _dy, _nx = nx + _dx;

            if (!OOB(_ny, _nx) && !visited[_ny][_nx])
            {
                if (Map[_ny][_nx])
                    aired[_ny][_nx]++;
                else
                {
                    visited[_ny][_nx] = true;
                    Q.push({_ny, _nx});
                }
            }
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            if (aired[i][j] >= 2)
                Map[i][j] = false;
        }
}

int main(void)
{
    fastIO;

    cin >> N >> M;

    vector<vector<bool>> V(N, vector<bool>(M));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            int temp;
            cin >> temp;
            V[i][j] = (temp == 1);
        }
    }
    int cnt = 0;
    bool flag = true;

    while (flag)
    {
        flag = false;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (V[i][j])
                {
                    bfs(V);
                    cnt++;
                    flag = true;
                }
    }
    cout << cnt;
    return 0;
}