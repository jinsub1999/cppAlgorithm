#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

string NUMtoSTR(int n)
{
    string ret = "";
    while (n != 0)
    {
        ret += (char)('0' + n % 10);
        n /= 10;
    }

    return string(ret.rbegin(), ret.rend());
}

void dfs(vector<pair<int, int>> &V, int cnt, string result)
{
    if (cnt == 0)
    {
        cout << result << '\n';
        return;
    }
    else
    {
        for (int i = 0; i < V.size(); i++)
        {
            if (V[i].second > 0)
            {
                V[i].second -= 1;
                dfs(V, cnt - 1, result + NUMtoSTR(V[i].first) + ' ');
                V[i].second += 1;
            }
        }
    }

    return;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> arr;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        bool flag = true;
        for (auto &elem : arr)
        {
            if (elem.first == temp)
            {
                elem.second += 1;
                flag = false;
                break;
            }
        }
        if (flag)
            arr.push_back({temp, 1});
    }

    sort(arr.begin(), arr.end());
    dfs(arr, m, "");
}