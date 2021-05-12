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

vector<vector<int>> parties;
int n, m;

vector<int> UnionFind(51);

void UnionFindInit()
{
    for (int i = 0; i <= n; i++)
        UnionFind[i] = i;
}
int UnionFindParent(int a)
{
    if (UnionFind[a] != a)
        UnionFind[a] = UnionFindParent(UnionFind[a]);
    return UnionFind[a];
}
void UnionFindMerge(int a, int b)
{
    a = UnionFindParent(a);
    b = UnionFindParent(b);

    if (a > b)
        swap(a, b);
    UnionFind[b] = a;
}

int main(void)
{
    cin >> n >> m;
    UnionFindInit();

    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int t;
        cin >> t;
        UnionFind[t] = 0;
    }
    parties.resize(m);
    for (int i = 0; i < m; i++)
    {
        int partyP;
        cin >> partyP;
        vector<int> T(partyP);
        for (int j = 0; j < partyP; j++)
            cin >> T[j];
        for (int j = 1; j < partyP; j++)
            UnionFindMerge(T[j - 1], T[j]);
        parties[i] = T;
    }
    int cnt = 0;

    for (auto elem : parties)
    {
        bool flag = true;
        for (auto e : elem)
        {
            if (UnionFindParent(e) == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cnt++;
    }
    cout << cnt;
    return 0;
}