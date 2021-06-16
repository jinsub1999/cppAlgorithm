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
typedef pair<int, pair<int, int>> Qnode;

int N, M;

vector<int> UF;

int UFfind(int a)
{
    if (UF[a] != a)
        UF[a] = UFfind(UF[a]);
    return UF[a];
}

void UFmerge(int a, int b)
{
    a = UFfind(a);
    b = UFfind(b);
    if (a > b)
        swap(a, b);
    UF[b] = a;
}

int main(void)
{
    fastIO;
    cin >> N >> M;
    UF.resize(N);
    for (int i = 0; i < N; i++)
        UF[i] = i;

    priority_queue<Qnode, vector<Qnode>, greater<>> PQ;
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        PQ.push({c, {a - 1, b - 1}});
    }
    int ans = 0;
    int lastR = -1;
    while (!PQ.empty())
    {
        auto curr = PQ.top();

        int dist = curr.first;
        int a = curr.second.first;
        int b = curr.second.second;

        if (UFfind(a) != UFfind(b))
        {
            UFmerge(a, b);
            ans += dist;
            lastR = dist;
        }
        PQ.pop();
    }
    cout << ans - lastR;
    return 0;
}