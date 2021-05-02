#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;

    for (int tc = 0; tc < t; tc++)
    {
        int n, m;
        cin >> n >> m;
        vector<long long> W(n * m);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> PQ;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> W[m * i + j];
                PQ.push({W[m * i + j], m * i + j});
            }
        }

        for (int i = 0; i < m; i++)
        {
            auto popItem = PQ.top();
            long long val = popItem.first;
            int Y = popItem.second / m;
            int X = popItem.second % m;

            if (val != W[m * Y + X])
            {
                for (int K = m * Y + i; K < m * Y + m; K++)
                {
                    if (val == W[K])
                    {
                        Y = K / m;
                        X = K % m;
                        break;
                    }
                }
            }
            long long temp = W[m * Y + i];
            W[m * Y + i] = W[m * Y + X];
            W[m * Y + X] = temp;

            PQ.pop();
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout << W[m * i + j] << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}