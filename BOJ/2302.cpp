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
int fibo[41];
int main(void)
{
    fastIO;

    int n;
    cin >> n;
    int m;
    cin >> m;

    fibo[0] = 1;
    fibo[1] = 1;
    fibo[2] = 2;
    for (int i = 3; i < 41; i++)
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    vector<int> Q(m);
    for (int i = 0; i < m; i++)
        cin >> Q[i];
    vector<int> sector;
    if (Q.size())
    {
        sector.push_back(Q[0] - 0 - 1);
        for (int i = 0; i < m - 1; i++)
            sector.push_back(Q[i + 1] - Q[i] - 1);
        sector.push_back(n - Q[Q.size() - 1]);
    }
    else
        sector.push_back(n);
    int ans = 1;

    for (auto elem : sector)
        ans *= fibo[elem];
    cout << ans;
    return 0;
}