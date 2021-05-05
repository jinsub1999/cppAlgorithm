#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <set>
#include <numeric>
#include <iterator>

using namespace std;

int team1[15] = {1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 5};
int team2[15] = {2, 3, 4, 5, 6, 3, 4, 5, 6, 4, 5, 6, 5, 6, 6};

vector<int> Zeros(6, 0);
vector<int> Wins(6, 0);
vector<int> Draws(6, 0);
vector<int> Loses(6, 0);
vector<int> GWins(6, 0);
vector<int> GDraws(6, 0);
vector<int> GLoses(6, 0);
bool dfs(int gameN = 0)
{

    bool ret = false;
    if (gameN == 15)
    {
        for (int i = 0; i < 6; i++)
        {
            if (Wins[i] != GWins[i])
                return false;
            if (Draws[i] != GDraws[i])
                return false;
            if (Loses[i] != GLoses[i])
                return false;
        }
        return true;
    }
    else
    {
        Wins[team1[gameN] - 1]++;
        Loses[team2[gameN] - 1]++;
        ret = ret || dfs(gameN + 1);
        Wins[team1[gameN] - 1]--;
        Loses[team2[gameN] - 1]--;

        Draws[team1[gameN] - 1]++;
        Draws[team2[gameN] - 1]++;
        ret = ret || dfs(gameN + 1);
        Draws[team1[gameN] - 1]--;
        Draws[team2[gameN] - 1]--;

        Loses[team1[gameN] - 1]++;
        Wins[team2[gameN] - 1]++;
        ret = ret || dfs(gameN + 1);
        Loses[team1[gameN] - 1]--;
        Wins[team2[gameN] - 1]--;
    }
    return ret;
}

int main(void)
{
    for (int tc = 0; tc < 4; tc++)
    {
        Wins.assign(6, 0);
        Draws.assign(6, 0);
        Loses.assign(6, 0);
        // Win
        // Draw
        // Lost
        for (int i = 0; i < 6; i++)
            cin >> GWins[i] >> GDraws[i] >> GLoses[i];

        if (dfs())
            cout << 1 << ' ';
        else
            cout << 0 << ' ';
    }
}