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

vector<vector<int>> sudoku(9, vector<int>(9));
vector<int> rows(9, 0);
vector<int> cols(9, 0);
vector<int> sections(9, 0);
void makeSudoku(int indx)
{
    if (indx == 81)
    {
        for (auto elem : sudoku)
        {
            for (auto e : elem)
                cout << e;
            cout << '\n';
        }
        exit(0);
    }
    int y = indx / 9;
    int x = indx % 9;
    if (sudoku[y][x] != 0)
        makeSudoku(indx + 1);
    else
    {
        for (int i = 1; i <= 9; i++)
        {
            bool flag = true;
            flag = flag && !(rows[y] & (1 << i));
            flag = flag && !(cols[x] & (1 << i));
            flag = flag && !(sections[(y / 3) * 3 + x / 3] & (1 << i));
            if (flag)
            {
                sudoku[y][x] = i;
                rows[y] |= (1 << i);
                cols[x] |= (1 << i);
                sections[(y / 3) * 3 + x / 3] |= (1 << i);

                makeSudoku(indx + 1);

                sudoku[y][x] = 0;

                rows[y] &= ~(1 << i);
                cols[x] &= ~(1 << i);
                sections[(y / 3) * 3 + x / 3] &= ~(1 << i);
            }
        }
    }
}

int main(void)
{
    fastIO;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            char t;
            cin >> t;
            if (t != '0')
                sudoku[i][j] = t - '0';
        }
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if (sudoku[i][j])
            {
                rows[i] |= (1 << sudoku[i][j]);
                cols[j] |= (1 << sudoku[i][j]);
                sections[(i / 3) * 3 + j / 3] |= (1 << sudoku[i][j]);
            }
    makeSudoku(0);

    return 0;
}