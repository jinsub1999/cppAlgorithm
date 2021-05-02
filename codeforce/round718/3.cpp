#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

int Fmap[500][500];

void mySearch(int y, int x, int v, int rema)
{
    if (rema == 1)
        return;
    if ((x - 1) >= 0 && Fmap[y][x - 1] == 0)
    {
        Fmap[y][x - 1] = v;
        mySearch(y, x - 1, v, rema - 1);
    }
    else
    {
        Fmap[y + 1][x] = v;
        mySearch(y + 1, x, v, rema - 1);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    queue<pair<int, int>> PQ;
    int n;
    cin >> n;
    vector<int> perm(n);
    for (int i = 0; i < n; i++)
    {
        cin >> perm[i];
        PQ.push({perm[i], i});
    }

    while (!PQ.empty())
    {
        pair<int, int> popItem = PQ.front();
        PQ.pop();
        int val = popItem.first;
        int pos = popItem.second;

        Fmap[pos][pos] = val;
        mySearch(pos, pos, val, val);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << Fmap[i][j] << ' ';
        }
        cout << '\n';
    }
}
