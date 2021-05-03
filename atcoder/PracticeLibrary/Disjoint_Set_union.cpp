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

vector<int> UF(300001);
vector<vector<pair<int, int>>> Emap(300001, vector<pair<int, int>>());

int UFfind(int a)
{
    if (UF[a] != a)
    {
        UF[a] = UFfind(UF[a]);
    }
    return UF[a];
}

void UFmerge(int a, int b)
{
    if (a > b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    a = UFfind(a);
    b = UFfind(b);
    UF[b] = a;
}

void UFinit()
{
    for (int i = 0; i < (int)UF.size(); i++)
        UF[i] = i;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, q;
    cin >> n >> q;
    UFinit();
    while (q--)
    {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0)
            UFmerge(u, v);
        else
            cout << (int)(UFfind(u) == UFfind(v)) << '\n';
    }
}