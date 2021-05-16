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

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
int N;
bool OOB(int y, int x) { return y < 0 || x < 0 || y >= N || x >= N; }

typedef long long ll;

int bfs(int i, int j, vector<vector<bool>> &M, vector<vector<bool>> &visit)
{
    queue<pair<int, int>> Q;
    Q.push({i, j});

    while (!Q.empty())
    {
        auto P = Q.front();
        Q.pop();
        int Y = P.first, X = P.second;
        for (int d = 0; d < 4; d++)
        {
            int _dy = dy[d], _dx = dx[d];
            if (!OOB(Y + _dy, X + _dx) && !visit[Y + _dy][X + _dx] && M[Y + _dy][X + _dx])
            {
                visit[Y + _dy][X + _dx] = true;
                Q.push({Y + _dy, X + _dx});
            }
        }
    }
    return 1;
}

int main(void)
{
    fastIO;

    cin >> N;

    vector<vector<int>> V(N, vector<int>(N));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> V[i][j];

    int cnt = -1;
    for (int hei = 0; hei <= 100; hei++)
    {
        int currCnt = 0;
        vector<vector<bool>> boolMap(N, vector<bool>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                boolMap[i][j] = (hei < V[i][j]);
        vector<vector<bool>> visited(N, vector<bool>(N, false));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (!visited[i][j] && boolMap[i][j])
                {
                    visited[i][j] = true;
                    currCnt += bfs(i, j, boolMap, visited);
                }

        cnt = max(cnt, currCnt);
    }
    cout << cnt;

    return 0;
}