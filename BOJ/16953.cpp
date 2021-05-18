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

    ll A, B;
    cin >> A >> B;

    queue<pair<ll, int>> Q;
    Q.push({A, 0});
    while (!Q.empty())
    {
        auto p = Q.front();
        Q.pop();

        ll curr = p.first;
        int cnt = p.second;
        if (curr == B)
        {
            cout << cnt + 1;
            exit(0);
        }
        if (curr * 2 <= B)
        {
            Q.push({curr * 2, cnt + 1});
        }

        if (curr * 10 + 1 <= B)
        {
            Q.push({curr * 10 + 1, cnt + 1});
        }
    }
    cout << -1;
    return 0;
}