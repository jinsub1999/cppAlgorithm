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

vector<int> V(100001, (int)1e9);

int main(void)
{
    fastIO;
    int n, k;
    cin >> n >> k;
    if (n == k)
    {
        cout << "0\n1";
        return 0;
    }
    V[n] = 0;
    queue<int> Q;
    int cnt = 0;
    Q.push(n);
    while (!Q.empty())
    {
        int curr = Q.front();
        Q.pop();

        if (curr + 1 < 100001 && V[curr + 1] >= V[curr] + 1)
        {
            if (curr + 1 == k && V[curr + 1] == V[curr] + 1)
                cnt++;
            else if (curr + 1 == k && V[curr + 1] > V[curr] + 1)
                cnt = 1;
            V[curr + 1] = V[curr] + 1;
            Q.push(curr + 1);
        }
        if (curr - 1 >= 0 && V[curr - 1] >= V[curr] + 1)
        {
            if (curr - 1 == k && V[curr - 1] == V[curr] + 1)
                cnt++;
            else if (curr - 1 == k && V[curr - 1] > V[curr] + 1)
                cnt = 1;
            V[curr - 1] = V[curr] + 1;
            Q.push(curr - 1);
        }
        if (curr * 2 < 100001 && V[curr * 2] >= V[curr] + 1)
        {
            if (curr * 2 == k && V[curr * 2] == V[curr] + 1)
                cnt++;
            else if (curr * 2 == k && V[curr * 2] > V[curr] + 1)
                cnt = 1;
            V[curr * 2] = V[curr] + 1;
            Q.push(curr * 2);
        }
    }

    cout << V[k] << '\n'
         << cnt;
    return 0;
}