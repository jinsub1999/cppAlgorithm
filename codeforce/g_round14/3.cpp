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
    while (T--)
    {
        int n, m, x;
        cin >> n >> m >> x;
        vector<long long> Blocks(n);
        vector<int> MarkingBlocks(n, -1);
        for (int i = 0; i < n; i++)
            cin >> Blocks[i];

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> PQ;

        for (int i = 1; i <= m; i++)
            PQ.push({0, i});

        for (int i = 0; i < n; i++)
        {
            pair<long long, int> elem = PQ.top();
            PQ.pop();
            elem.first += Blocks[i];
            MarkingBlocks[i] = elem.second;
            PQ.push(elem);
        }

        int mini = PQ.top().first;
        while (PQ.size() != 1)
            PQ.pop();
        int maxi = PQ.top().first;

        if (maxi - mini <= x)
        {
            cout << "YES\n";
            copy(MarkingBlocks.begin(), MarkingBlocks.end(), ostream_iterator<int>(cout, " "));
            cout << '\n';
        }
        else
            cout << "NO'\n";
    }
}