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

int R, C, T;
int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};
bool OOB(int y, int x) { return y < 0 || x < 0 || y >= R || x >= C; }

typedef long long ll;

vector<vector<int>> hwakSan(vector<vector<int>> room)
{
    vector<vector<int>> ret(R, vector<int>(C));
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            if (room[i][j] > 0)
            {
                int dust = room[i][j];
                int cnt = 0;
                for (int d = 0; d < 4; d++)
                {
                    int ny = i + dy[d], nx = j + dx[d];
                    if (!OOB(ny, nx) && room[ny][nx] != -1)
                    {
                        ret[ny][nx] += dust / 5;
                        cnt++;
                    }
                }
                ret[i][j] += dust - cnt * (dust / 5);
            }
            else if (room[i][j] == -1)
                ret[i][j] = room[i][j];
        }

    return ret;
}

vector<vector<int>> aired(vector<vector<int>> room, int airCir)
{
    int acTop = airCir, acBot = airCir + 1;
    for (int i = acTop - 1; i > 0; i--)
        room[i][0] = room[i - 1][0];
    for (int j = 0; j < C - 1; j++)
        room[0][j] = room[0][j + 1];
    for (int i = 0; i < acTop; i++)
        room[i][C - 1] = room[i + 1][C - 1];
    for (int j = C - 1; j > 0; j--)
        room[acTop][j] = room[acTop][j - 1];

    room[acTop][1] = 0;

    for (int i = acBot + 1; i < R - 1; i++)
        room[i][0] = room[i + 1][0];
    for (int j = 0; j < C - 1; j++)
        room[R - 1][j] = room[R - 1][j + 1];
    for (int i = R - 1; i > acBot; i--)
        room[i][C - 1] = room[i - 1][C - 1];
    for (int j = C - 1; j > 0; j--)
        room[acBot][j] = room[acBot][j - 1];

    room[acBot][1] = 0;

    return room;
}

int main(void)
{
    fastIO;
    cin >> R >> C >> T;

    vector<vector<int>> room(R, vector<int>(C, 0));

    for (auto &elem : room)
        for (auto &e : elem)
            cin >> e;

    int airCir;
    for (int i = 0; i < R; i++)
    {
        if (room[i][0] == -1)
        {
            airCir = i;
            break;
        }
    }
    auto ans = room;

    while (T--)
    {
        ans = hwakSan(ans);
        ans = aired(ans, airCir);
    }
    int cnt = 0;
    for (auto &elem : ans)
        for (auto &e : elem)
            if (e > 0)
                cnt += e;
    cout << cnt;
    return 0;
}