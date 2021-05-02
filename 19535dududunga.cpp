#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long LL;

vector<int> graph[300000];
LL vertexDegree[300000];
vector<bool> visited(300000, false);
queue<int> Q;
LL Dtree = 0, Gtree = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;

    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
        vertexDegree[a]++;
        vertexDegree[b]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (vertexDegree[i] >= 3)
            Gtree += (vertexDegree[i] * (vertexDegree[i] - 1) * (vertexDegree[i] - 2)) / 6;
    }
    Q.push(0);
    while (!Q.empty())
    {
        int popItem = Q.front();
        Q.pop();
        for (auto elem : graph[popItem])
        {
            if (!visited[elem])
            {
                Dtree += (vertexDegree[popItem] - 1) * (vertexDegree[elem] - 1);
                Q.push(elem);
            }
        }
        visited[popItem] = true;
    }

    if (Dtree == Gtree * 3)
        cout << "DUDUDUNGA" << '\n';
    else if (Dtree > Gtree * 3)
        cout << "D" << '\n';
    else
        cout << "G" << '\n';
    return 0;
}