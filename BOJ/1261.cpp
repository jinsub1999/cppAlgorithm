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

int n, m;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
bool OOB(int y, int x) { return y < 0 || x < 0 || y >= n || x >= m; }

typedef long long ll;
typedef pair<int, pair<int, int>> P;

int miro[100][100];
int Break[100][100];

int main(void)
{
    fastIO;

    cin >> m >> n;

    for (int i = 0; i < n; i++)
    {
        string K;
        cin >> K;

        for (int j = 0; j < m; j++)
            miro[i][j] = K[j] - '0';
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            Break[i][j] = (int)1e9 + 7;

    priority_queue<P, vector<P>, greater<>> PQ;

    PQ.push({0, {0, 0}});
    Break[0][0] = 0;
    while (!PQ.empty())
    {
        P p = PQ.top();
        PQ.pop();
        int cW = p.first, cY = p.second.first, cX = p.second.second;
        if (cY == n - 1 && cX == m - 1)
        {
            cout << cW << '\n';
            return 0;
        }
        for (int d = 0; d < 4; d++)
        {
            int _dy = dy[d], _dx = dx[d];

            if (!OOB(cY + _dy, cX + _dx) && Break[cY + _dy][cX + _dx] > Break[cY][cX] + miro[cY][cX])
            {
                Break[cY + _dy][cX + _dx] = Break[cY][cX] + miro[cY][cX];
                PQ.push({Break[cY + _dy][cX + _dx], {cY + _dy, cX + _dx}});
            }
        }
    }

    return 0;
}