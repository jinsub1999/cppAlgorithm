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

int main(void)
{
    fastIO;
    int n;
    cin >> n;
    vector<int> hitter(8);
    vector<vector<int>> battings(n);
    for (int i = 0; i < n; i++)
    {
        vector<int> bats(9);
        for (auto &elem : bats)
            cin >> elem;
        battings[i] = bats;
    }
    for (int i = 0; i < 8; i++)
        hitter[i] = i + 1;
    int ans = -1;
    do
    {
        int sco = 0;
        int inning = 0;
        int outs = 0;
        int currBatter = 0;
        int bases = 0; // bitmask;
        while (inning < n)
        {
            int cB;
            if (currBatter == 3)
                cB = battings[inning][0];
            else if (currBatter > 3)
                cB = battings[inning][hitter[currBatter - 1]];
            else
                cB = battings[inning][hitter[currBatter]];
            if (cB)
            {
                bases <<= 1;
                bases += 1;
                bases <<= cB - 1;
                if (bases >= 8)
                {
                    for (int home = 3; home < 8; home++)
                        if (bases & (1 << home))
                        {
                            bases &= ~(1 << home);
                            sco++;
                        }
                }
            }
            else
                outs++;

            if (outs == 3)
            {
                outs = 0;
                inning++;
                bases = 0;
            }
            currBatter = (currBatter + 1) % 9;
        }
        ans = max(ans, sco);
    } while (next_permutation(hitter.begin(), hitter.end()));
    cout << ans;
    return 0;
}