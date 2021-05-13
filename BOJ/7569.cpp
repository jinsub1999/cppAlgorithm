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

#define Triple pair<int, pair<int, int>>

int dz[6] = {0, 0, -1, 1, 0, 0};
int dy[6] = {0, 0, 0, 0, -1, 1};
int dx[6] = {-1, 1, 0, 0, 0, 0};

int Tomato[100][100][100];

int M, N, H;

bool OOB(int z, int y, int x)
{
    return z < 0 || y < 0 || x < 0 || z >= H || y >= N || x >= M;
}

void bfs(queue<Triple> &Q)
{
    while (!Q.empty())
    {
        Triple popItem = Q.front();
        Q.pop();
        int cZ = popItem.first, cY = popItem.second.first, cX = popItem.second.second;

        for (int d = 0; d < 6; d++)
        {
            int _dz = dz[d], _dy = dy[d], _dx = dx[d];
            if (!OOB(cZ + _dz, cY + _dy, cX + _dx) && Tomato[cZ + _dz][cY + _dy][cX + _dx] == 0)
            {
                Tomato[cZ + _dz][cY + _dy][cX + _dx] = Tomato[cZ][cY][cX] + 1;
                Q.push({cZ + _dz, {cY + _dy, cX + _dx}});
            }
        }
    }
}

typedef long long ll;

int main(void)
{
    fastIO;
    cin >> M >> N >> H;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < M; k++)
                cin >> Tomato[i][j][k];
    queue<Triple> Qu;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < M; k++)
                if (Tomato[i][j][k] == 1)
                {
                    Qu.push({i, {j, k}});
                }
    bfs(Qu);
    int maxi = -1;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < M; k++)
                if (Tomato[i][j][k] == 0)
                {
                    cout << -1;
                    return 0;
                }
                else
                {
                    maxi = max(maxi, Tomato[i][j][k]);
                }

    cout << maxi - 1;
    return 0;
}