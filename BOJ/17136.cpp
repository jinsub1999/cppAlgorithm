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
bool OOB(int y, int x, int N) { return y < 0 || x < 0 || y >= N || x >= N; }

typedef long long ll;
vector<vector<int>> papers(10, vector<int>(10));
vector<vector<bool>> visited(10, vector<bool>(10, false));
vector<int> colors(6, 5);

int bruteForce(int k)
{
    if (k == 100)
        return 0;
    int ret = (int)1e9;
    int y = k / 10;
    int x = k % 10;
    if (papers[y][x] && !visited[y][x])
    {
        for (int d = 0; d < 5; d++)
        {
            if (!OOB(y + d, x + d, 10))
            {
                bool flag = true;
                for (int _y = y; _y <= y + d; _y++)
                    for (int _x = x; _x <= x + d; _x++)
                        flag = flag && papers[_y][_x] && (!visited[_y][_x]);

                if (flag && colors[d])
                {
                    colors[d]--;
                    for (int _y = y; _y <= y + d; _y++)
                        for (int _x = x; _x <= x + d; _x++)
                            visited[_y][_x] = true;

                    ret = min(ret, bruteForce(k + 1) + 1);

                    for (int _y = y; _y <= y + d; _y++)
                        for (int _x = x; _x <= x + d; _x++)
                            visited[_y][_x] = false;
                    colors[d]++;
                }
            }
        }
    }
    else
        ret = min(ret, bruteForce(k + 1));
    return ret;
}

int main(void)
{
    for (auto &elem : papers)
        for (auto &e : elem)
            cin >> e;

    int ans = bruteForce(0);

    if (ans < 3000)
        cout << ans;
    else
        cout << -1;
    return 0;
}