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
int N;

vector<int> seongeo;
vector<bool> visited;

vector<int> peo;
int ans = (int)1e9 + 7;

int check(int curr, vector<vector<int>> &E)
{
    int ret = peo[curr];
    for (auto nxt : E[curr])
        if (!visited[nxt] && seongeo[curr] == seongeo[nxt])
        {
            visited[nxt] = true;
            ret += check(nxt, E);
        }
    return ret;
}

void toggles(int indx, vector<vector<int>> &E)
{
    if (indx == N)
    {
        fill(visited.begin(), visited.end(), false);

        int r = -1, b = -1, res = 0;
        bool checkR = false, checkB = false;

        for (int i = 0; i < N; i++)
        {
            if (!visited[i])
            {
                if (!checkR && seongeo[i] == 0)
                    checkR = true;
                else if (!checkB && seongeo[i] == 1)
                    checkB = true;
                else if (checkR)
                {
                    res = -1;
                    break;
                }
                else if (checkB)
                {
                    res = -1;
                    break;
                }
                visited[i] = true;
                if (seongeo[i] == 0)
                    r = check(i, E);
                else
                    b = check(i, E);
            }
        }
        if (res == 0)
        {
            res = abs(r - b);
            ans = min(res, ans);
        }
        return;
    }
    else
    {
        seongeo[indx] = 0;
        toggles(indx + 1, E);
        seongeo[indx] = 1;
        toggles(indx + 1, E);
    }
}

int main(void)
{
    fastIO;
    cin >> N;
    peo.resize(N);
    seongeo.resize(N);
    visited.resize(N);
    vector<vector<int>> edges(N);
    for (auto &elem : peo)
        cin >> elem;

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        edges[i].resize(temp);
        for (auto &elem : edges[i])
        {
            cin >> elem;
            elem--;
        }
    }
    toggles(0, edges);
    if (ans < (int)1e9)
        cout << ans;
    else
        cout << -1;
    return 0;
}