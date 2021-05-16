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

typedef long long ll;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

void checkV(vector<vector<int>> &V, int n, int m)
{
    vector<int> Minis(n, 0);
    vector<int> pushes(n, 0);
    for (auto &elem : V)
        sort(elem.begin(), elem.end());

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = m; i >= 1; i--)
    {
        int mini = (int)1e9 + 1;
        int miniIndx = -1;
        for (int j = 0; j < n; j++)
        {
            if (mini > V[j][0])
            {
                miniIndx = j;
                mini = V[j][0];
            }
        }
        rotate(V[miniIndx].begin(), V[miniIndx].begin() + 1, V[miniIndx].begin() + i);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> V(n, vector<int>(m));

        for (auto &elem : V)
            for (auto &e : elem)
                cin >> e;

        checkV(V, n, m);
        for (auto &elem : V)
        {
            for (auto &e : elem)
                cout << e << ' ';
            cout << '\n';
        }
    }
    return 0;
}