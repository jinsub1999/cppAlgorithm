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

// dfs
// bfs
// DP
// segTree
// topological sort (indegree search)
set<long long> S;

int main(void)
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, l, r;

        cin >> n >> l >> r;
        int L = l, R = r;
        vector<int> Lsock(n + 1, 0);
        vector<int> Rsock(n + 1, 0);
        for (int i = 0; i < l; i++)
        {
            int t;
            cin >> t;
            Lsock[t]++;
        }
        for (int i = 0; i < r; i++)
        {
            int t;
            cin >> t;
            if (Lsock[t] > 0)
            {
                Lsock[t]--;
                L--, R--;
            }
            else
                Rsock[t]++;
        }
        // l >= r
        if (L < R)
        {
            swap(L, R);
            swap(Lsock, Rsock);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            while (L > R)
            {
                if (Lsock[i] >= 2)
                {
                    ans += 1;
                    L -= 2;
                    Lsock[i] -= 2;
                }
                else
                    break;
            }
        }
        ans += L;
        cout << ans << '\n';
    }
}