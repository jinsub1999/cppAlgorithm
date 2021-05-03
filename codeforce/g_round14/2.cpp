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
// segTree
// topological sort (indegree search)
set<long long> S;

int main(void)
{
    int T;
    cin >> T;

    long long pow22 = 2;
    long long pow44 = 4;
    int i = 1;
    while (pow22 < (long long)1e9 + 1)
    {
        S.insert(pow22);
        i++;
        pow22 = 2 * i * i;
    }
    i = 1;
    while (pow44 < (long long)1e9 + 1)
    {
        S.insert(pow44);
        i++;
        pow44 = 4 * i * i;
    }
    for (int i = 0; i < T; i++)
    {
        long long n;
        cin >> n;
        if (S.count(n))
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
    return 0;
}