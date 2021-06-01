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

ll MOD = (int)1e9 + 7;

// (a / b) % MOD
// == (a % MOD * (b ^ (MOD - 2)) % MOD)
ll fastExp(int n, int d)
{
    if (d == 0)
        return 1LL;
    else if (d == 1)
        return n;
    else if (d % 2)
        return (n * fastExp(n, d - 1)) % MOD;
    else
    {
        ll ret = fastExp(n, d / 2) % MOD;
        return (ret * ret) % MOD;
    }
}

ll myCalc(int s, int n)
{
    return (s * (fastExp(n, MOD - 2) % MOD)) % MOD;
}

int main(void)
{
    ll m;
    cin >> m;
    vector<ll> S(m);
    vector<ll> N(m);
    for (int i = 0; i < m; i++)
        cin >> N[i] >> S[i];

    ll ret = 0;

    for (int i = 0; i < m; i++)
    {
        ret += myCalc(S[i], N[i]);
        ret %= MOD;
    }

    cout << ret;

    return 0;
}