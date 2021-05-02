#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <set>
#include <numeric>

using namespace std;

int main(void)
{
    int R, C;
    cin >> R >> C;
    vector<vector<int>> A(R, vector<int>(C - 1));
    vector<vector<int>> B(R - 1, vector<int>(C));
    vector<vector<int>> G(R, vector<int>(C, (int)1e9 + 7));
    vector<vector<bool>> visited(R, vector<bool>(C, false));

    for (auto &row : A)
    {
        for (auto &col : row)
        {
            cin >> col;
        }
    }
    for (auto &row : B)
    {
        for (auto &col : row)
        {
            cin >> col;
        }
    }

    priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<>> PQ;

    PQ.push({0, {0, 0}});
    visited[0][0] = true;
    G[0][0] = 0;
    while (!PQ.empty())
    {
        auto popItem = PQ.top();
        PQ.pop();

        long long cost = popItem.first;
        long long r = popItem.second.first;
        long long c = popItem.second.second;
        if (r == R - 1 && c == C - 1)
        {
            cout << cost;
            return 0;
        }

        if (c < C - 1 && G[r][c + 1] > G[r][c] + A[r][c])
        {
            G[r][c + 1] = G[r][c] + A[r][c];
            PQ.push({A[r][c] + cost, {r, c + 1}});
        }
        if (c >= 1 && G[r][c - 1] > G[r][c] + A[r][c - 1])
        {
            G[r][c - 1] = G[r][c] + A[r][c - 1];
            PQ.push({A[r][c - 1] + cost, {r, c - 1}});
        }
        if (r < R - 1 && G[r + 1][c] > G[r][c] + B[r][c])
        {
            G[r + 1][c] = G[r][c] + B[r][c];
            PQ.push({B[r][c] + cost, {r + 1, c}});
        }
        for (int i = 1; i <= r; i++)
        {
            if (G[r - i][c] > G[r][c] + i + 1)
            {
                G[r - i][c] = G[r][c] + i + 1;
                PQ.push({cost + i + 1, {r - i, c}});
            }
        }
    }
    cout << G[R - 1][C - 1];
    return 0;
}