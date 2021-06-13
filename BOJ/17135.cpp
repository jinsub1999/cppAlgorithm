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
int N, M, D;

void MatDown(vector<vector<int>> &mat)
{
    for (int i = N - 1; i > 0; i--)
        for (int j = 0; j < M; j++)
            mat[i][j] = mat[i - 1][j];
    for (int j = 0; j < M; j++)
        mat[0][j] = 0;
}

int shootArrowHitArrow(vector<vector<int>> E, vector<int> A)
{
    vector<int> arch;
    int cnt = 0;
    for (int i = 0; i < M; i++)
        if (A[i])
            arch.push_back(i);
    for (int downCnt = 0; downCnt <= N; downCnt++)
    {
        set<pair<int, int>> S;
        for (auto pos : arch)
        {
            pair<int, int> P = {1000, 1000};
            int minD = 1000;
            for (int i = N - 1; i >= 0; i--)
            {
                for (int j = M - 1; j >= 0; j--)
                {
                    int d = (N - i) + abs(pos - j);
                    if (E[i][j] && d <= D && minD >= d)
                    {
                        if (minD == d && P.second < j) // important
                            continue;
                        P = {i, j};
                        minD = d;
                    }
                }
            }
            if (minD < 1000)
                S.insert(P);
        }
        for (auto p : S)
        {
            E[p.first][p.second] = 0;
            cnt++;
        }
        MatDown(E);
    }
    return cnt;
}

int main(void)
{
    fastIO;
    cin >> N >> M >> D;

    vector<vector<int>> enemy(N, vector<int>(M));

    for (auto &elem : enemy)
        for (auto &e : elem)
            cin >> e;

    vector<int> archers(M);
    archers[0] = archers[1] = archers[2] = 1;
    int ans = 0;
    do
    {
        ans = max(ans, shootArrowHitArrow(enemy, archers));
    } while (prev_permutation(archers.begin(), archers.end()));
    cout << ans;
    return 0;
}