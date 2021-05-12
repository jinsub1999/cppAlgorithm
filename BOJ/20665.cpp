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

vector<vector<bool>> desk(101, vector<bool>(721, false));
vector<pair<int, int>> persons;
// 0900 ~ 2100 -> 0 - 720
// desk[i][t] : t 분에 i번째가 있는가.
int main(void)
{
    fastIO;

    ll N, T, P;
    cin >> N >> T >> P;
    for (int i = 0; i < T; i++)
    {
        string IN;
        cin >> IN;

        int H, M;
        H = 10 * (IN[0] - '0') + IN[1] - '0';
        M = 10 * (IN[2] - '0') + IN[3] - '0';
        int stime = (H - 9) * 60 + M;

        cin >> IN;

        H = 10 * (IN[0] - '0') + IN[1] - '0';
        M = 10 * (IN[2] - '0') + IN[3] - '0';
        int etime = (H - 9) * 60 + M;

        persons.push_back({stime, etime});
    }
    sort(persons.begin(), persons.end());
    for (int i = 0; i < persons.size(); i++)
    {
        auto currP = persons[i];
        int S = currP.first;
        int wantedDesk = 1;
        int miniDist = -1;
        vector<int> Q;
        for (int d = 1; d <= N; d++)
        {
            if (desk[d][S])
                continue;
            bool left, right = left = true;
            int currDist = -1;
            for (int dist = 1; dist < N; dist++)
            {
                if (d + dist > N)
                    right = false;
                if (d - dist < 1)
                    left = false;
                if (right && desk[d + dist][S])
                {
                    currDist = dist;
                    break;
                }
                else if (left && desk[d - dist][S])
                {
                    currDist = dist;
                    break;
                }
            }
            if (currDist == -1)
                wantedDesk = 1;
            else if (miniDist < currDist)
            {
                miniDist = currDist;
                wantedDesk = d;
            }
        }
        for (int t = currP.first; t < currP.second; t++)
            desk[wantedDesk][t] = true;
    }
    int cnt = 0;
    for (int t = 0; t < 720; t++)
        if (!desk[P][t])
            cnt++;
    cout << cnt;
    return 0;
}