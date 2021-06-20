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

vector<int> arr;
vector<int> mem;
int N;
int main(void)
{
    fastIO;

    cin >> N;
    arr.resize(N + 1, (int)1e9);
    mem.resize(N + 1);
    arr[N] = 0;
    for (int i = N; i >= 1; i--)
    {
        if (i % 3 == 0)
            if (arr[i / 3] > arr[i] + 1)
            {
                mem[i / 3] = i;
                arr[i / 3] = arr[i] + 1;
            }
        if (i % 2 == 0)
            if (arr[i / 2] > arr[i] + 1)
            {
                mem[i / 2] = i;
                arr[i / 2] = arr[i] + 1;
            }
        if (arr[i - 1] > arr[i] + 1)
        {
            mem[i - 1] = i;
            arr[i - 1] = arr[i] + 1;
        }
    }
    int it = 1;
    vector<int> path;
    while (it != N)
    {
        path.push_back(it);
        it = mem[it];
    }
    path.push_back(it);
    cout << arr[1] << '\n';
    for (auto it = path.rbegin(); it != path.rend(); it++)
        cout << *it << ' ';

    return 0;
}