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

// int dy[4] = {0, 0, -1, 1};
// int dx[4] = {-1, 1, 0, 0};
// bool OOB(int y, int x, int N){return y < 0 || x < 0 || y >= N || x >= N;}

typedef long long ll;
int N;

int dfs(int y, int x, int direction, vector<vector<int>> &Blocks)
{
    if (y >= N || x >= N)
        return 0;
    else if (y == N - 1 && x == N - 1)
        return 1;
    else
    {
        int ret = 0;
        if (direction != 1 && x + 1 < N && Blocks[y][x + 1] != 1) // toRight
            ret += dfs(y, x + 1, 0, Blocks);
        if (direction != 0 && y + 1 < N && Blocks[y + 1][x] != 1) // toDown
            ret += dfs(y + 1, x, 1, Blocks);
        if (x + 1 < N && y + 1 < N && Blocks[y + 1][x + 1] != 1 && Blocks[y + 1][x] != 1 && Blocks[y][x + 1] != 1)
            ret += dfs(y + 1, x + 1, 2, Blocks);
        return ret;
    }
}
int main(void)
{
    fastIO;
    cin >> N;
    vector<vector<int>> V(N, vector<int>(N));
    for (auto &elem : V)
        for (auto &e : elem)
        {
            cin >> e;
        }
    cout << dfs(0, 1, 0, V);
    return 0;
}