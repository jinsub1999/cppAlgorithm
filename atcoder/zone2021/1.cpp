#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <set>
#include <numeric>

using namespace std;

int main(void)
{
    string S;
    int t = 0;
    cin >> S;
    for (int i = 0; i <= S.length() - 4; i++)
    {
        string test = string(S.begin() + i, S.begin() + i + 4);
        if (test == "ZONe")
            t++;
    }

    cout << t;
    return 0;
}