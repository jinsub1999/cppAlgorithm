#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <set>
#include <deque>
#include <numeric>

using namespace std;

typedef vector<int> STAT;

int n;
vector<STAT> stats;
bool canUnderT(int T)
{
    set<int> bitmaskPossi;
    for (auto st : stats)
    {
        int bitmasked = 0;
        for (int i = 0; i < 5; i++)
        {
            if (st[i] >= T)
                bitmasked |= (1 << i);
        }
        bitmaskPossi.insert(bitmasked);
    }

    for (auto x : bitmaskPossi)
        for (auto y : bitmaskPossi)
            for (auto z : bitmaskPossi)
                if ((x | y | z) == 31)
                    return true; // 11111
    return false;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    stats.resize(n, STAT(5));
    for (int i = 0; i < n; i++)
    {
        for (auto &elem : stats[i])
            cin >> elem;
    }

    int mini = 0;
    int maxi = (int)1e9 + 7;

    while (mini + 1 < maxi)
    {
        int mid = (mini + maxi) / 2;
        if (canUnderT(mid))
        {
            mini = mid;
        }
        else
        {
            maxi = mid;
        }
    }
    cout << mini;
    return 0;
}