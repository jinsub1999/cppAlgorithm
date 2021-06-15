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

int N, M;

int calcDist(int house, int chicken)
{
    int hy = house / N, hx = house % N;
    int cy = chicken / N, cx = chicken % N;

    return abs(hy - cy) + abs(hx - cx);
}

int main(void)
{
    fastIO;
    cin >> N >> M;

    vector<vector<int>> Vill(N, vector<int>(N));

    for (auto &elem : Vill)
        for (auto &e : elem)
            cin >> e;

    vector<int> houses;
    vector<int> chickens;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (Vill[i][j] == 1)
                houses.push_back(i * N + j);
            else if (Vill[i][j] == 2)
                chickens.push_back(i * N + j);

    vector<vector<int>> distC(houses.size(), vector<int>(chickens.size()));
    for (int i = 0; i < (const int)houses.size(); i++)
        for (int j = 0; j < (const int)chickens.size(); j++)
            distC[i][j] = calcDist(houses[i], chickens[j]);

    vector<bool> chooseC(chickens.size(), false);

    for (int i = 0; i < M; i++)
        chooseC[i] = true;
    int ans = (int)1e9;
    do
    {
        int ret = 0;

        for (int i = 0; i < houses.size(); i++)
        {
            vector<int> temp;
            for (int j = 0; j < chickens.size(); j++)
                if (chooseC[j])
                    temp.push_back(distC[i][j]);

            ret += *min_element(temp.begin(), temp.end());
        }
        ans = min(ans, ret);
    } while (prev_permutation(chooseC.begin(), chooseC.end()));
    cout << ans;
    return 0;
}