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

using namespace std;
int n;
int Favres[5] = {0, 1, 10, 100, 1000};
int OutOfBound(int x, int y)
{
    return (x < 0) || (y < 0) || (x >= n) || (y >= n);
}

int countFav(int d)
{
    return Favres[d];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    vector<vector<int>> school(n, vector<int>(n, -1));
    vector<vector<int>> sharks(n * n, vector<int>(5));
    map<int, set<int>> SharkScore;
    for (auto &elem : sharks)
    {
        for (auto &fav : elem)
            cin >> fav;
    }
    int favTotal = 0;
    vector<pair<int, int>> dydx = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}};
    for (auto &shark : sharks)
    {
        int sharkNum = shark[0];
        set<int> FAV;
        for (int i = 1; i <= 4; i++)
            FAV.insert(shark[i]);
        SharkScore[sharkNum] = FAV;

        pair<int, int> candi = {-1, -1};
        int currBlank = -1;
        int currFav = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (school[i][j] == -1)
                {
                    int fav = 0;

                    int __blank = 0;
                    for (auto elem : dydx)
                    {
                        int dy = elem.first;
                        int dx = elem.second;
                        if (OutOfBound(i + dx, j + dy))
                            continue;
                        if (school[i + dx][j + dy] == -1)
                            __blank++;
                        else if (FAV.count(school[i + dx][j + dy]))
                            fav++;
                    }
                    if (currFav < fav)
                    {
                        currFav = fav;
                        currBlank = __blank;
                        candi = {i, j};
                    }
                    if (currFav == fav && currBlank < __blank)
                    {
                        currBlank = __blank;
                        candi = {i, j};
                    }
                }
            }
        }
        school[candi.first][candi.second] = sharkNum;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int fav = 0;
            for (auto elem : dydx)
            {
                int dy = elem.first;
                int dx = elem.second;
                if (OutOfBound(i + dx, j + dy))
                    continue;
                else if (SharkScore[school[i][j]].count(school[i + dx][j + dy]))
                    fav++;
            }

            favTotal += countFav(fav);
        }
    cout << favTotal;
    return 0;
}