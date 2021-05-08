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
#include <cassert>
using namespace std;

typedef long long ll;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)

int main(void)
{
    fastIO;

    int N;
    cin >> N;
    vector<ll> A(N);

    vector<ll> MOD200(200);

    for (int i = 0; i < N; i++)
    {
        ll &elem = A[i];
        cin >> elem;
        elem %= 200;

        MOD200[elem] += 1;
    }
    ll sum = 0;
    for (auto divs : MOD200)
    {
        if (divs)
            sum += (divs * (divs - 1)) / 2;
    }
    cout << sum;
    return 0;
}