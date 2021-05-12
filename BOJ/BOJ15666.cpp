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

vector<int> V;
set<int> ValueMap;
vector<int> valueCount;
int n, m;
void f(int indx, int cnt)
{
    if (cnt == 0)
    {
        for (int i = 0; i < V.size(); i++)
        {
            int repeat = valueCount[i];
            while (repeat--)
                cout << V[i] << ' ';
        }
        cout << '\n';
        return;
    }
    if (indx < V.size())
    {
        int t = cnt;
        while (t >= 0)
        {
            valueCount[indx] += t;
            f(indx + 1, cnt - t);
            valueCount[indx] -= t;

            t--;
        }
    }
}

int main(void)
{
    cin >> n >> m;
    ValueMap.clear();
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        ValueMap.insert(a);
    }
    V = vector<int>(ValueMap.begin(), ValueMap.end());
    valueCount.resize(V.size());

    sort(V.begin(), V.end());
    f(0, m);
    return 0;
}