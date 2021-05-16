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

int dy[8] = {1, 1, -1, -1, 2, 2, -2, -2};
int dx[8] = {-2, 2, -2, 2, -1, 1, -1, 1};
bool OOB(int y, int x, int N) { return y < 0 || x < 0 || y >= N || x >= N; }

typedef long long ll;

int main(void)
{
    fastIO;
    int T;
    cin >> T;
    while (T--)
    {
        int l;
        cin >> l;
        vector<vector<int>> V(l, vector<int>(l, (int)1e9));
        pair<int, int> S;
        cin >> S.first >> S.second;
        pair<int, int> E;
        cin >> E.first >> E.second;
        queue<pair<int, int>> Q;
        V[S.first][S.second] = 0;
        Q.push(S);
        while (!Q.empty())
        {
            auto P = Q.front();

            if (P == E)
            {
                break;
            }
            int Y = P.first, X = P.second;
            Q.pop();

            for (int d = 0; d < 8; d++)
            {
                int _dy = dy[d], _dx = dx[d];
                if (!OOB(Y + _dy, X + _dx, l) && V[Y + _dy][X + _dx] > V[Y][X] + 1)
                {
                    V[Y + _dy][X + _dx] = V[Y][X] + 1;
                    Q.push({Y + _dy, X + _dx});
                }
            }
        }

        cout << V[E.first][E.second] << '\n';
    }

    return 0;
}