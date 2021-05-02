#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <set>
#include <numeric>

using namespace std;

int findMax(vector<int> &V, set<int> &except)
{
    int indx = -1;
    int maxx = 0;

    for (int i = 0; i < V.size(); i++)
        if (maxx < V[i] && except.count(i) == 0)
        {
            maxx = V[i];
            indx = i;
        }
    if (indx != -1)
        except.insert(indx);
    return indx;
}

int team1[15] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2, 3, 3, 4};
int team2[15] = {1, 2, 3, 4, 5, 2, 3, 4, 5, 3, 4, 5, 4, 5, 5};

int check(vector<vector<int>> V, vector<vector<int>> &ori, int game = 0)
{
    if (game == 15)
    {
    }
    int ret = 0;
    check(V, ori, game + 1);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    for (int tc = 0; tc < 4; tc++)
    {
        vector<vector<int>> WDL(6, vector<int>(3, 0));
        for (auto &ELEM : WDL)
            for (auto &elem : ELEM)
                cin >> elem;
        vector<vector<int>> V(6, vector<int>(3, 0));

        check(V, WDL);
    }
}