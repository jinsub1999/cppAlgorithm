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

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> V(3);
    for (auto &elem : V)
        cin >> elem;
    vector<int> mini(3);
    vector<int> prevMini(3);
    vector<int> maxi(3);
    vector<int> prevMaxi(3);

    for (int i = 0; i < 3; i++)
        maxi[i] = mini[i] = prevMini[i] = prevMaxi[i] = V[i];
    for (int height = 1; height < n; height++)
    {
        prevMini = mini;
        prevMaxi = maxi;
        for (auto &elem : V)
            cin >> elem;
        maxi[0] = V[0] + max({prevMaxi[0], prevMaxi[1]});
        maxi[1] = V[1] + max({prevMaxi[0], prevMaxi[1], prevMaxi[2]});
        maxi[2] = V[2] + max({prevMaxi[2], prevMaxi[1]});
        mini[0] = V[0] + min({prevMini[0], prevMini[1]});
        mini[1] = V[1] + min({prevMini[0], prevMini[1], prevMini[2]});
        mini[2] = V[2] + min({prevMini[2], prevMini[1]});
    }
    int maxII = max({maxi[0], maxi[1], maxi[2]});
    int minII = min({mini[0], mini[1], mini[2]});

    cout << maxII << ' ' << minII;

    return 0;
}