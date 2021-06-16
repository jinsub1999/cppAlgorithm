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

    int N, S;
    cin >> N >> S;
    vector<int> V(N);
    vector<int> pre(N + 1, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> V[i];
        pre[i + 1] = pre[i] + V[i];
    }

    int ptr1 = 0, ptr2 = 1;

    int mini = (int)1e9;
    while (ptr2 <= N)
    {
        int curr = pre[ptr2] - pre[ptr1];
        if (curr >= S)
        {
            mini = min(mini, ptr2 - ptr1);
            ptr1++;
        }
        else if (curr < S)
            ptr2++;
    }
    if (mini < 100010)
        cout << mini;
    else
        cout << 0;
    return 0;
}