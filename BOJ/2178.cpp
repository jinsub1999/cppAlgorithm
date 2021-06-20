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
bool outofBound(int y, int x, int M, int N) { return y < 0 || x < 0 || y >= N || x >= M; }

typedef long long ll;
int n, m;

void bfs(vector<vector<int>> &miro)
{
    queue<pair<int, int>> Qu;
    Qu.push({0, 0});

    while (!Qu.empty())
    {
        auto popItem = Qu.front();
        Qu.pop();
        int y = popItem.first;
        int x = popItem.second;

        for (int d = 0; d < 4; d++)
        {
            int _dy = dy[d], _dx = dx[d];
            if (!outofBound(y + _dy, x + _dx, m, n) && miro[y + _dy][x + _dx] == 1)
            {
                miro[y + _dy][x + _dx] = miro[y][x] + 1;
                Qu.push({y + _dy, x + _dx});
            }
        }
    }
}
int main(void)
{
    fastIO;

    cin >> n >> m;

    vector<vector<int>> MIRO(n, vector<int>(m));

    for (int i = 0; i < n; i++)
    {
        string INPUT;
        cin >> INPUT;
        for (int j = 0; j < m; j++)
            MIRO[i][j] = INPUT[j] - '0';
    }
    bfs(MIRO);
    cout << MIRO[n - 1][m - 1];
    return 0;
}