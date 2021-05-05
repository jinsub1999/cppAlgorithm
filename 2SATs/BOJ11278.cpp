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

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> V(M);
    for (int i = 0; i < M; i++)
        cin >> V[i].first >> V[i].second;

    int bitBool = 0;

    while (bitBool < (1 << N))
    {
        bool ret = true;
        for (auto elem : V)
        {
            bool l = (elem.first > 0), r = (elem.second > 0);
            elem.first = abs(elem.first) - 1;
            elem.second = abs(elem.second) - 1;
            bool first = ((1 << elem.first) & bitBool);
            bool second = ((1 << elem.second) & bitBool);
            bool fin1 = l == first;
            bool fin2 = r == second;

            ret &= (fin1 || fin2);
        }
        if (ret)
        {
            cout << 1 << '\n';
            for (int i = 0; i < N; i++)
                cout << (bool)(bitBool & (1 << i)) << ' ';
            return 0;
        }
        bitBool++;
    }
    cout << 0;
    return 0;
}