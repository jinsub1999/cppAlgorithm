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

vector<int> houses;

vector<vector<bool>> visited(25, vector<bool>(25, false));
vector<vector<int>> M(25, vector<int>(25, 0));

int n;
pair<int, int> dydx[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool outOfBound(int i, int j)
{
    return i < 0 || j < 0 || i >= n || j >= n;
}

int dfs(int i, int j)
{
    int ret = 1;
    for (auto elem : dydx)
    {
        int dy = elem.first, dx = elem.second;

        if (!outOfBound(i + dy, j + dx) && !visited[i + dy][j + dx] && M[i + dy][j + dx] == 1)
        {
            visited[i + dy][j + dx] = true;
            ret += dfs(i + dy, j + dx);
        }
    }
    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string S;
        cin >> S;
        for (int j = 0; j < n; j++)
        {
            M[i][j] = S[j] - '0';
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && M[i][j] == 1)
            {
                visited[i][j] = true;
                houses.push_back(dfs(i, j));
            }
        }
    }
    sort(houses.begin(), houses.end());
    cout << houses.size() << '\n';
    copy(houses.begin(), houses.end(), ostream_iterator<int>(cout, "\n"));
    return 0;
}