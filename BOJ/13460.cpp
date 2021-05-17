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

typedef pair<int, vector<vector<char>>> P;

typedef pair<int, int> Coor;
typedef pair<Coor, Coor> RBcoor;
typedef pair<int, RBcoor> Qnode;

int N, M;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
bool OOB(int y, int x) { return y < 0 || x < 0 || y >= N || x >= M; }

typedef long long ll;

int main(void)
{
    cin >> N >> M;
    vector<vector<char>> V(N, vector<char>(M));
    Coor R, B, O;
    for (int i = 0; i < N; i++)
    {
        string INPUT;
        cin >> INPUT;
        for (int j = 0; j < M; j++)
        {
            V[i][j] = INPUT[j];
            if (INPUT[j] == 'B')
            {
                B = {i, j};
                V[i][j] = '.';
            }
            else if (INPUT[j] == 'R')
            {
                R = {i, j};
                V[i][j] = '.';
            }
            else if (INPUT[j] == 'O')
            {
                O = {i, j};
            }
        }
    }
    queue<Qnode> Q;
    Q.push({0, {R, B}});
    while (!Q.empty())
    {
        int cnt = Q.front().first;
        RBcoor RB = Q.front().second;
        Q.pop();
        Coor currR = RB.first;
        Coor currB = RB.second;
        int _rY = currR.first, _rX = currR.second;
        int _bY = currB.first, _bX = currB.second;

        if (currB == pair<int, int>(-1, -1))
            continue;
        else if (currR == pair<int, int>(-1, -1))
        {
            cout << cnt;
            exit(0);
        }
        if (cnt == 10)
            continue;
        for (int d = 0; d < 4; d++)
        {
            int _dy = dy[d], _dx = dx[d];
            int rY = _rY, rX = _rX, bY = _bY, bX = _bX;
            while (V[bY + _dy][bX + _dx] != '#' && make_pair(bY + _dy, bX + _dx) != make_pair(rY, rX))
            {
                bY += _dy;
                bX += _dx;
                if (V[bY][bX] == 'O')
                {
                    bY = -1, bX = -1;
                    break;
                }
            }
            while (V[rY + _dy][rX + _dx] != '#' && make_pair(rY + _dy, rX + _dx) != make_pair(bY, bX))
            {
                rY += _dy;
                rX += _dx;
                if (V[rY][rX] == 'O')
                {
                    rY = -1, rX = -1;
                    break;
                }
            }
            if (make_pair(bY, bX) != pair<int, int>(-1, -1) && V[bY][bX] != 'O')
                while (V[bY + _dy][bX + _dx] != '#' && make_pair(bY + _dy, bX + _dx) != make_pair(rY, rX))
                {
                    bY += _dy;
                    bX += _dx;
                    if (V[bY][bX] == 'O')
                    {
                        bY = -1, bX = -1;
                        break;
                    }
                }

            Q.push({cnt + 1, {{rY, rX}, {bY, bX}}});
        }
    }
    cout << -1;
    return 0;
}