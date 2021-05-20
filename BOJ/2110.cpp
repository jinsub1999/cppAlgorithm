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
    vector<int> V;
    int n, c;
    cin >> n >> c;
    V.resize(n);

    for (int &i : V)
        cin >> i;

    sort(V.begin(), V.end());

    int l = 1;
    int r = 1000000000;

    while (l + 1 < r)
    {
        int mid = (l + r) / 2;
        int cnt = 1;
        int curr = 0;
        int next = 1;
        while (curr + next < n)
        {
            if (V[curr + next] - V[curr] >= mid)
            {
                cnt++;
                curr = curr + next;
                next = 1;
            }
            else
                next++;
        }
        if (cnt < c)
            r = mid;
        else
            l = mid;
    }

    cout << l;
    return 0;
}