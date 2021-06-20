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

int dfs(int indx, vector<int> &V, vector<int> &path, vector<bool> &vis)
{
    if (vis[indx])
    {
        for (auto it = path.rbegin(); it != path.rend(); it++)
            if (*it == indx)
                return it - path.rbegin() + 1;
        return 0;
    }
    vis[indx] = true;
    path.push_back(indx);
    return dfs(V[indx], V, path, vis);
}

int main(void)
{
    fastIO;

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> V(n + 1);
        for (int i = 1; i <= n; i++)
        {
            int temp;
            cin >> temp;
            V[i] = temp;
        }
        vector<bool> visited(n + 1, false);
        int ans = n;
        for (int i = 1; i <= n; i++)
            if (!visited[i])
            {
                vector<int> temp;
                ans -= dfs(i, V, temp, visited);
            }
        cout << ans << '\n';
    }

    return 0;
}