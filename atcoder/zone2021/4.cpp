#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <set>
#include <deque>
#include <numeric>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<vector<pair<int, int>>> TABLE(5, vector<pair<int, int>>(n));
    for (int i = 0; i < n; i++)
    {
        for (int STAT = 0; STAT < 5; STAT++)
        {
            cin >> TABLE[STAT][i].first;
            TABLE[STAT][i].second = i;
        }
    }
    int MINI = -1;

    for (int STAT = 0; STAT < 5; STAT++)
    {
        sort(TABLE[STAT].rbegin(), TABLE[STAT].rend());
    }
    int CNT = n;
    vector<int> INDX(5, 0);
    // int indxA, indxB, indxC, indxD, indxE = 0;
    set<int> S;
    for (int STAT = 0; STAT < 5; STAT++)
        S.insert(TABLE[STAT][INDX[STAT]].second);

    bool flag = true;
    while (flag)
    {
        int maxIndx = -1;
        int maxStat = -1;

        for (int STAT = 0; STAT < 5; STAT++)
        {
            if (INDX[STAT] != n - 1 && maxStat < TABLE[STAT][INDX[STAT]].first)
            {
                maxIndx = STAT;
                maxStat = TABLE[STAT][INDX[STAT]].first;
            }
        }
        if (maxIndx == -1)
            break;
        S.erase(TABLE[maxIndx][INDX[maxIndx]].second);
        INDX[maxIndx]++;
        S.insert(TABLE[maxIndx][INDX[maxIndx]].second);

        if (S.size() == 3)
        {
            int currmin = (int)1e9 + 1;
            for (int STAT = 0; STAT < 5; STAT++)
                currmin = min(currmin, TABLE[STAT][INDX[STAT]].first);

            MINI = max(MINI, currmin);
        }
    }
    if (MINI == -1)
    {
        int currmin = (int)1e9 + 1;
        for (int STAT = 0; STAT < 5; STAT++)
            currmin = min(currmin, TABLE[STAT][INDX[STAT]].first);

        MINI = max(MINI, currmin);
    }
    vector<int> V;
    cout << MINI;
    return 0;
}