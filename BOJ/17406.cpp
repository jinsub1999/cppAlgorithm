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
typedef pair<int, pair<int, int>> rotOp;

int N, M, K;

int calcMat(vector<vector<int>> A)
{
    int ret = (int)1e9;
    for (auto &elem : A)
        ret = min(accumulate(elem.begin(), elem.end(), 0), ret);
    return ret;
}

vector<vector<int>> rotMat(vector<vector<int>> A, int r, int c, int _d)
{
    for (int d = 1; d <= _d; d++)
    {
        int temp = A[r - d][c];
        for (int toLeft = 0; toLeft < d; toLeft++)
            A[r - d][c - toLeft] = A[r - d][c - toLeft - 1];
        for (int toDown = 0; toDown < 2 * d; toDown++)
            A[r - d + toDown][c - d] = A[r - d + toDown + 1][c - d];
        for (int toRight = 0; toRight < 2 * d; toRight++)
            A[r + d][c - d + toRight] = A[r + d][c - d + toRight + 1];
        for (int toUp = 0; toUp < 2 * d; toUp++)
            A[r + d - toUp][c + d] = A[r + d - toUp - 1][c + d];
        for (int toLeft = 0; toLeft < d - 1; toLeft++)
            A[r - d][c + d - toLeft] = A[r - d][c + d - toLeft - 1];
        A[r - d][c + 1] = temp;
    }
    return A;
}
int main(void)
{
    fastIO;
    cin >> N >> M >> K;
    vector<vector<int>> V(N, vector<int>(M));

    for (auto &elem : V)
        for (auto &e : elem)
            cin >> e;

    vector<rotOp> rotOps;

    while (K--)
    {
        int r, c, s;
        cin >> r >> c >> s;
        rotOps.push_back({s, {r - 1, c - 1}});
    }

    vector<int> orders(rotOps.size());
    for (int i = 0; i < orders.size(); i++)
        orders[i] = i;
    int ans = (int)1e9;
    do
    {
        auto temp = V;
        for (auto Indx : orders)
        {
            rotOp O = rotOps[Indx];
            temp = rotMat(temp, O.second.first, O.second.second, O.first);
        }

        ans = min(ans, calcMat(temp));
    } while (next_permutation(orders.begin(), orders.end()));

    cout << ans;
    return 0;
}