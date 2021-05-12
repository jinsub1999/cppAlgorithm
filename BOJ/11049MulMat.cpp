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

int matMul(pair<int, int> P1, pair<int, int> P2)
{
    return P1.first * P1.second * P2.second;
}

int main(void)
{
    int n;
    cin >> n;
    vector<pair<int, int>> Mats(n);

    for (auto &elem : Mats)
        cin >> elem.first >> elem.second;

    vector<vector<int>> DP(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        DP[i][i + 1] = matMul(Mats[i], Mats[i + 1]);
        for (int j = i + 2; j < n; j++)
        {
        }
    }
    // DP[n - 1] =

    return 0;
}