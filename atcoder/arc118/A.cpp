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
    ll t;
    ll N;
    cin >> t >> N;
    vector<bool> check(10000, false);
    int T = (100 + t);
    for (int i = 1; i <= 1000; i++)
        check[T * i / 100] = true;

    vector<int> Q;
    for (int i = 1; i < (100 + t); i++)
    {

        if (!check[i] && check[i - 1])
        {
            Q.push_back(i);
            if (i > 200)
                break;
        }
    }
    int Qsize = (int)Q.size();
    ll adding = 100 + t;
    ll res = 0;
    N--;
    res += (100LL + t) * (N / Qsize);
    N %= Qsize;
    res += Q[N];
    cout << res;
    return 0;
}