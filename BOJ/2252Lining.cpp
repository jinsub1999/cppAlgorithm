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

queue<int> Qu;
vector<int> inDegree;
vector<vector<int>> Gr;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    Gr.resize(n + 1);
    inDegree.resize(n + 1, 0);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        Gr[a].push_back(b);
        inDegree[b]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
            Qu.push(i);
    }

    while (!Qu.empty())
    {
        int popItem = Qu.front();
        cout << popItem << ' ';
        for (auto elem : Gr[popItem])
        {
            inDegree[elem]--;
            if (inDegree[elem] == 0)
                Qu.push(elem);
        }
        Qu.pop();
    }
    return 0;
}