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

int R, C;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
bool OOB(int y, int x) { return y < 0 || x < 0 || y >= R || x >= C; }

typedef long long ll;

int dfs(int y, int x, int bitBool, vector<vector<char>> &T)
{
    int ret = 1;
    int temp = 0;
    for (int d = 0; d < 4; d++)
    {
        int _temp = -1;
        int _dy = dy[d], _dx = dx[d];
        if (!OOB(y + _dy, x + _dx) && !(bitBool & (1 << ((int)T[y + _dy][x + _dx] - 'A'))))
            _temp = dfs(y + _dy, x + _dx, (bitBool | (1 << ((int)T[y + _dy][x + _dx] - 'A'))), T);
        temp = max(_temp, temp);
    }
    return ret + temp;
}

int main(void)
{
    fastIO;

    cin >> R >> C;
    vector<vector<char>> V(R, vector<char>(C));

    for (auto &elem : V)
        for (auto &e : elem)
            cin >> e;

    cout << dfs(0, 0, (0 | (1 << ((int)V[0][0] - 'A'))), V);

    return 0;
}