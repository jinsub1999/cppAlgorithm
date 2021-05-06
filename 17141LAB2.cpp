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

using namespace std;

int n, m;

vector<vector<int>> LAB(50, vector<int>(50, 0));
vector<pair<int, int>> Virus;
vector<bool> combi(10);
pair<int, int> dydx[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int ans = -1;
bool checkOutBound(int y, int x)
{
    return y < 0 || x < 0 || y >= n || x >= n;
}

void dfs(int y, int x)
{
    for (auto elem : dydx)
    {
        int dy = elem.first, dx = elem.second;

        if (!checkOutBound(y + dy, x + dx) && LAB[y + dy][x + dx] > LAB[y][x] + 1)
        {
            LAB[y + dy][x + dx] = LAB[y][x] + 1;
            dfs(y + dy, x + dx);
        }
    }
}

void makeCombi(int vi_indx, int cnt)
{
    if (cnt == m)
    {
        int ret = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (LAB[i][j] > (int)1e9)
                    return;

                if (LAB[i][j] < (int)1e9 && LAB[i][j] > ret)
                    ret = LAB[i][j];
            }
        }
        if (ans == -1)
            ans = ret;
        else
            ans = min(ans, ret);
        return;
    }

    if (vi_indx + 1 < Virus.size())
    {
        makeCombi(vi_indx + 1, cnt);
        vector<vector<int>> temp = LAB;
        int vy = Virus[vi_indx + 1].first, vx = Virus[vi_indx + 1].second;
        LAB[vy][vx] = 0;
        dfs(vy, vx);
        LAB[vy][vx] = -1;
        makeCombi(vi_indx + 1, cnt + 1);
        LAB = temp;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> LAB[i][j];
            if (LAB[i][j] == 2)
            {
                Virus.push_back({i, j});
                LAB[i][j] = (int)1e9 + 1;
            }
            else if (LAB[i][j] == 0)
            {
                LAB[i][j] = (int)1e9 + 1;
            }
            else if (LAB[i][j] == 1)
            {
                LAB[i][j] = -1;
            }
        }
    }
    //LABbackup = LAB;
    //LAB[Virus[0].first][Virus[0].second] = 0;
    //dfs(Virus[0].first, Virus[0].second);

    makeCombi(-1, 0);
    cout << ans;
    return 0;
}