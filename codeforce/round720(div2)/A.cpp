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

    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b;

        ll n, m, k;
        n = b * b - 1;
        m = 1;
        k = b;
        if (n)
        {
            cout << "YES" << '\n';
            cout << a * n << ' ' << a * m << ' ' << k * a * b << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }

    return 0;
}