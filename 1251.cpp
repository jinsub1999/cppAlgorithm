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
    string S;
    cin >> S;

    int Slen = (int)S.length() - 1;

    string res = "";
    for (int i = 0; i < Slen; i++)
    {
        for (int j = i + 1; j < Slen; j++)
        {
            string I = string(S.begin(), S.begin() + i + 1);
            string J = string(S.begin() + i + 1, S.begin() + j + 1);
            string K = string(S.begin() + j + 1, S.end());
            reverse(I.begin(), I.end());
            reverse(J.begin(), J.end());
            reverse(K.begin(), K.end());
            if (res == "")
                res = I + J + K;
            else
                res = min(res, I + J + K);
        }
    }
    cout << res;
    return 0;
}