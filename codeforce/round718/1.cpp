#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

int main(void)
{
    int T;
    cin >> T;
    vector<unsigned long long> V;
    unsigned long long v = 2050;

    unsigned long long pow1018 = 10;
    for (int i = 0; i < 18; i++)
        pow1018 *= 10;

    while (v <= pow1018)
    {
        V.push_back(v);
        v *= 10;
    }
    for (int i = 0; i < T; i++)
    {
        unsigned long long cnt = 0;
        unsigned long long inputI;
        cin >> inputI;
        for (auto it = V.rbegin(); it != V.rend(); it++)
        {
            unsigned long long now = *it;
            while (inputI >= now)
            {
                inputI -= now;
                cnt++;
            }
        }
        if (cnt > 0 && inputI == 0)
            cout << cnt << '\n';
        else
            cout << -1 << '\n';
    }
    return 0;
}