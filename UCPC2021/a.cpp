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
#include <bitset>
#include <string>

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

int intLength(int n)
{
    int ret = 0;
    while (n != 0)
    {
        n /= 10;
        ret++;
    }

    return ret;
}

int main(void)
{
    fastIO;
    string a;
    cin >> a;
    int n = a.size();
    for (int i = 1; i < 4; i++)
    {
        int candi = atoi(string(a.begin(), a.begin() + i).c_str());
        int nxt = candi + 1;
        bool success = true;
        int it = i;

        while (it != n)
        {
            int nxt_it = intLength(nxt);
            if (nxt != atoi(string(a.begin() + it, a.begin() + it + nxt_it).c_str()))
            {
                success = false;
                break;
            }
            it += nxt_it;
            nxt++;
        }
        if (success)
        {
            cout << candi << ' ' << nxt - 1 << '\n';
            return 0;
        }
    }
    return 0;
}