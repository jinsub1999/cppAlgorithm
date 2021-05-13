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

int N;
int rupees[130][130];
int ZELDA[130][130];

typedef pair<int, pair<int, int>> P;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
bool OOB(int y, int x) { return y < 0 || x < 0 || y >= N || x >= N; }

typedef long long ll;

int main(void)
{
    fastIO;

    int t = 0;
    while (++t)
    {
        cin >> N;
        if (N == 0)
            break;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                cin >> rupees[i][j];
                ZELDA[i][j] = (int)1e9 + 7;
            }

        priority_queue<P, vector<P>, greater<>> PQ;
        PQ.push({rupees[0][0], {0, 0}});
        ZELDA[0][0] = rupees[0][0];
        while (!PQ.empty())
        {
            P p = PQ.top();
            PQ.pop();
            int cW = p.first, cY = p.second.first, cX = p.second.second;
            if (cY == N - 1 && cX == N - 1)
                break;
            for (int d = 0; d < 4; d++)
            {
                int _dy = dy[d], _dx = dx[d];
                if (!OOB(cY + _dy, cX + _dx) && ZELDA[cY + _dy][cX + _dx] > ZELDA[cY][cX] + rupees[cY + _dy][cX + _dx])
                {
                    ZELDA[cY + _dy][cX + _dx] = ZELDA[cY][cX] + rupees[cY + _dy][cX + _dx];
                    PQ.push({ZELDA[cY + _dy][cX + _dx], {cY + _dy, cX + _dx}});
                }
            }
        }
        cout << "Problem " << t << ": " << ZELDA[N - 1][N - 1] << '\n';
    }

    return 0;
}