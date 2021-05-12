#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int isPalindrome(string &S, int start, int end, bool flag)
{
    int i = start;
    int j = end;

    while (i <= j)
    {
        if (S[i] != S[j])
        {
            if (flag)
                return 2;
            else
                return min(isPalindrome(S, i + 1, j, true), isPalindrome(S, i, j - 1, true));
        }
        else
        {
            i++;
            j--;
        }
    }
    if (flag)
        return 1;
    return 0;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        string S;
        cin >> S;
        int res = isPalindrome(S, 0, S.length() - 1, false);
        cout << res << '\n';
    }
    return 0;
}