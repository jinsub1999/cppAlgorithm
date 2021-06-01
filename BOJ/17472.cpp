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

typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> PQnode;

int n, m;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
bool OOB(int y, int x) { return y < 0 || x < 0 || y >= n || x >= m; }

void islandDFS(int y, int x, vector<vector<bool>> &VIS, vector<vector<int>> &MAP, int islandNum)
{
    for (int d = 0; d < 4; d++)
    {
        int _dy = dy[d], _dx = dx[d];
        if (!OOB(y + _dy, x + _dx) && !VIS[y + _dy][x + _dx] && MAP[y + _dy][x + _dx] != 0)
        {
            MAP[y + _dy][x + _dx] = islandNum;
            VIS[y + _dy][x + _dx] = true;
            islandDFS(y + _dy, x + _dx, VIS, MAP, islandNum);
        }
    }
}

vector<int> UF;

void UFinit(int k)
{
    UF.resize(k + 1);
    for (int i = 1; i <= k; i++)
        UF[i] = i;
}

int UFfindParent(int a)
{
    if (UF[a] != a)
        UF[a] = UFfindParent(UF[a]);
    return UF[a];
}

void UFmerge(int a, int b)
{
    a = UFfindParent(a);
    b = UFfindParent(b);
    if (a > b)
        swap(a, b);
    UF[b] = a;
}

int main(void)
{
    fastIO;
    cin >> n >> m;
    int islandcnt = 1;
    vector<vector<int>> land(n, vector<int>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, 0));
    for (auto &elem : land)
        for (auto &e : elem)
            cin >> e;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (land[i][j] != 0 && !visited[i][j])
            {
                visited[i][j] = true;
                land[i][j] = islandcnt;
                islandDFS(i, j, visited, land, islandcnt);
                islandcnt++;
            }
        }
    }
    UFinit(islandcnt);
    priority_queue<PQnode, vector<PQnode>, greater<>> edges;
    for (int i = 0; i < n; i++)
    {
        int prev = 0;
        for (int j = 1; j < m; j++)
        {
            if (land[i][j] != 0)
            {
                if (land[i][prev] == 0)
                    prev = j;
                else if (land[i][j] == land[i][prev])
                    prev = j;
                else
                {
                    if (j - prev > 2)
                        edges.push({j - prev - 1, {land[i][prev], land[i][j]}});
                    prev = j;
                }
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        int prev = 0;
        for (int j = 1; j < n; j++)
        {
            if (land[j][i] != 0)
            {
                if (land[prev][i] == 0)
                    prev = j;
                else if (land[j][i] == land[prev][i])
                    prev = j;
                else
                {
                    if (j - prev > 2)
                        edges.push({j - prev - 1, {land[prev][i], land[j][i]}});
                    prev = j;
                }
            }
        }
    }
    int ans = 0;
    while (!edges.empty())
    {
        auto pqn = edges.top();
        int dist = pqn.first, a = pqn.second.first, b = pqn.second.second;
        edges.pop();

        if (UFfindParent(a) != UFfindParent(b))
        {
            UFmerge(a, b);
            ans += dist;
        }
    }
    for (int i = 1; i < islandcnt; i++)
    {
        for (int j = i + 1; j < islandcnt; j++)
        {
            if (UFfindParent(i) != UFfindParent(j))
            {
                cout << -1;
                return 0;
            }
        }
    }
    cout << ans;
    return 0;
}