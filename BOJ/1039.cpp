#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int pow10(int t)
{
    int ret = 1;
    while (t--)
        ret *= 10;
    return ret;
}

int dfs(int n, int k, int d, int startIndx)
{
    if (k == 0)
        return n;
    else if (startIndx == 0)
    {
        set<int> Q;
        for (int i = d; i >= 0; i--)
            Q.insert((n / pow10(i)) % 10);
        if (Q.size() != d + 1)
            return n;
        else
        {
            if (k % 2 != 0)
            {
                int newN = n - n % 10 - ((n / 10) % 10) * 10 + (n % 10) * 10 + (n / 10) % 10;
                return newN;
            }
            else
                return n;
        }
    }
    else
    {
        int ret = -1;
        int maxNum = (n / pow10(startIndx)) % 10;
        int maxIndx = startIndx;
        for (int i = startIndx - 1; i >= 0; i--)
        {
            if (((n / pow10(i)) % 10 >= maxNum) && (n / pow10(i)) % 10 != (n / pow10(startIndx)) % 10)
            {
                maxNum = (n / pow10(i)) % 10;
                maxIndx = i;
                int newN = n - (n / pow10(maxIndx)) % 10 * pow10(maxIndx) - (n / pow10(startIndx)) % 10 * pow10(startIndx);
                newN += (n / pow10(maxIndx)) % 10 * pow10(startIndx) + (n / pow10(startIndx)) % 10 * pow10(maxIndx);
                ret = max(ret, dfs(newN, k - 1, d, startIndx - 1));
            }
        }
        if (maxIndx == startIndx)
            return max(ret, dfs(n, k, d, startIndx - 1));
        else
            return ret;
    }
}

int main(void)
{
    int n, k;
    cin >> n >> k;
    set<int> S = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int d = 0;
    while (n >= pow10(d))
        d++;
    d--;

    if (n < 10 || S.count(n))
        cout << -1;
    else
        cout << dfs(n, k, d, d);

    return 0;
}