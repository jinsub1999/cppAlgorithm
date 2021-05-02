#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

bool coor[101][101];

vector<int> dydx[4] = {{1, 0}, {0, -1}, {-1, 0}, {0, 1}};

pair<pair<int, int>, int> Dragon(int x, int y, int d, int g)
{
    if (g == 0)
    {
        coor[y][x] = true;
        coor[y + dydx[d][1]][x + dydx[d][0]] = true;
        return {{dydx[d][1], dydx[d][0]}, (d + 1) % 4};
    }
    else
    {
        pair<pair<int, int>, int> newCoor;
        newCoor = Dragon(x, y, d, g - 1);
        newCoor = Dragon(x + newCoor.first.second, y + newCoor.first.first, (d + 1) % 4, g - 1);
        return newCoor;
    }
}

int checkSQ()
{
    int ret = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (coor[i][j] && coor[i + 1][j] && coor[i][j + 1] && coor[i + 1][j + 1])
                ret++;
        }
    }
    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        Dragon(x, y, d, g);
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
                cout << coor[i][j] << ' ';
            cout << '\n';
        }
        cout << "---------------------------------" << '\n';
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            cout << coor[i][j] << ' ';
        cout << '\n';
    }

    cout << checkSQ() << '\n';

    return 0;
}