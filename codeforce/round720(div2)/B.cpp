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

int gcd(int a, int b)
{
    if (a < b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    if (b == 0)
        return a;
    else
        return gcd(b, (a % b));
}
//1000000009
//1000000007
using namespace std;

typedef long long ll;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (auto &elem : arr)
            cin >> elem;
        vector<vector<int>> operations;
        bool flag = false;
        for (int i = 1; i < n; i++)
        {

            if (gcd(arr[i], arr[i - 1]) != 1)
            {
                if (arr[i] < arr[i - 1])
                    swap(arr[i], arr[i - 1]);

                if (!flag)
                {
                    operations.push_back({i, i + 1, 1000000007, arr[i - 1]});
                    arr[i] = arr[i - 1];
                    flag = true;
                }
                else
                {
                    flag = false;
                    operations.push_back({i, i + 1, 1000000009, arr[i - 1]});
                    arr[i] = arr[i - 1];
                }
            }
        }
        cout << operations.size() << '\n';
        for (auto elem : operations)
        {
            for (auto e : elem)
                cout << e << ' ';
            cout << '\n';
        }
    }

    return 0;
}