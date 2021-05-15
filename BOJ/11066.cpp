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

// DP[i][j] : i부터 j까지의 최소 합.
// DP[i][j] = min(DP[i + 1][j] + A[i], DP[i][j - 1] + A[j])

int DP[500][500];
vector<int> V(500);
vector<int> presum;

int SumAtoB(int a, int b)
{
    a++, b++;
    return presum[b] - presum[a - 1];
}

int Dyna(int i, int j)
{
    int &ret = DP[i][j];
    if (ret != -1)
        return ret;
    else if (i == j)
    {
        ret = 0;
        return ret;
    }
    else
    {
        int mini = (int)1e9;
        for (int t = 0; t < j - i; t++)
        {
            mini = min(mini, Dyna(i, i + t) + Dyna(i + t + 1, j) + SumAtoB(i, i + t) + SumAtoB(i + t + 1, j));
        }
        ret = mini;
        return ret;
    }
}

typedef long long ll;

int main(void)
{
    fastIO;
    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;
        V.resize(N);
        presum.resize(N + 1);
        presum[0] = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> V[i];
            presum[i + 1] = V[i] + presum[i];
        }
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                DP[i][j] = -1;

        cout << Dyna(0, N - 1) << '\n';
    }

    return 0;
}