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
typedef pair<int, int> vertex;
typedef pair<int, vertex> PQnode;
int n, m;

vector<int> UF;

void UFinit()
{
    UF.resize(n + 1);
    for (int i = 1; i <= n; i++)
        UF[i] = i;
}

int UFfindParent(int a)
{
    if (UF[a] != a)
        UF[a] = UFfindParent(UF[a]);
    return UF[a];
}

void UFmerge(int a, int b)
{
    a = UFfindParent(a);
    b = UFfindParent(b);
    if (a > b)
        swap(a, b);
    UF[b] = a;
}

int main(void)
{
    fastIO;
    cin >> n >> m;
    UFinit();
    priority_queue<PQnode, vector<PQnode>, greater<>> PQ;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        PQ.push({c, {a, b}});
    }
    int tot = 0;
    while (!PQ.empty())
    {
        PQnode pqn = PQ.top();
        PQ.pop();
        int dist = pqn.first;
        int a = pqn.second.first, b = pqn.second.second;
        if (UFfindParent(a) != UFfindParent(b))
        {
            UFmerge(a, b);
            tot += dist;
        }
    }
    cout << tot;

    return 0;
}