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

#define input(type, K) \
    type K;            \
    cin >> K;

using namespace std;

typedef long long ll;

vector<vector<int>> relations(1000, vector<int>(1000, false));
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
int total = 0;
void FindEulerC(int curr, vector<int> &res, int n)
{
    for (int i = 0; i < n; i++)
    {
        while (relations[curr][i])
        {
            relations[curr][i]--;
            relations[i][curr]--;
            FindEulerC(i, res, n);
        }
    }
    res.push_back(curr);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input(int, n);

    for (int i = 0; i < n; i++)
    {
        int IND = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> relations[i][j];
            IND += relations[i][j];
        }
        if (IND % 2)
        {
            cout << -1;
            return 0;
        }
    }
    total /= 2;
    vector<int> Q;
    FindEulerC(0, Q, n);
    reverse(Q.begin(), Q.end());
    for (auto elem : Q)
        cout << elem + 1 << ' ';
    return 0;
}