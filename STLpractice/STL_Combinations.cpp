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

vector<int> Sample = {1, 2, 3, 4, 5, 6, 7};
vector<int> Iter = {};
vector<bool> OneZero;
void dfs(int indx, int size, int cnt, int wantedN) // select cnt in indxs
{
    if (cnt == wantedN)
    {
        copy(Iter.begin(), Iter.end(), ostream_iterator<int>(cout, " "));
        cout << '\n';
        return;
    }
    if (indx + 1 < size)
    {
        dfs(indx + 1, size, cnt, wantedN);
        vector<int> Q;
        Iter.push_back(Sample[indx + 1]);
        dfs(indx + 1, size, cnt + 1, wantedN);
        Iter.pop_back();
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, r;
    cin >> n >> r;
    for (int i = 0; i < r; i++)
        OneZero.push_back(true);
    for (int i = 0; i < n - r; i++)
        OneZero.push_back(false);
    vector<int> Test;
    for (int i = 0; i < n; i++)
        Test.push_back(i);
    do
    {
        for (int i = 0; i < n; i++)
        {
            if (OneZero[i])
                cout << Test[i] << ' ';
        }
        cout << '\n';
    } while (prev_permutation(OneZero.begin(), OneZero.end()));

    sort(Test.begin(), Test.end());
    copy(Test.begin(), Test.end(), ostream_iterator<int>(cout, " "));
    return 0;
}