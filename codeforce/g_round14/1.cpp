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

using namespace std;

// dfs
// bfs
// DP
// topological sort (indegree search)
// BruteForce
// DijkStra, Belman-Ford, Floyd

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
    {
        int n, x;

        cin >> n >> x;
        vector<int> GOLD(n);
        for (int i = 0; i < n; i++)
            cin >> GOLD[i];

        sort(GOLD.rbegin(), GOLD.rend());

        if (GOLD[0] <= x)
        {
            vector<int> newG;
            vector<int> remain;

            int SUM = 0;
            int indx = 0;
            for (int i = 0; i < GOLD.size(); i++)
            {
                SUM += GOLD[i];
                if (SUM < x)
                    newG.push_back(GOLD[i]);
                else if (SUM == x)
                {
                    remain.push_back(GOLD[i]);
                    SUM -= GOLD[i];
                }
                else if (SUM > x)
                    newG.push_back(GOLD[i]);
            }
            if (accumulate(GOLD.begin(), GOLD.end(), 0) == x)
            {
                cout << "NO" << '\n';
            }
            else
            {
                cout << "YES" << '\n';
                copy(newG.begin(), newG.end(), ostream_iterator<int>(cout, " "));
                copy(remain.begin(), remain.end(), ostream_iterator<int>(cout, " "));
                cout << '\n';
            }
        }
        else
        {
            cout << "YES" << '\n';
            copy(GOLD.begin(), GOLD.end(), ostream_iterator<int>(cout, " "));
            cout << '\n';
        }
    }
    return 0;
}