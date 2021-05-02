#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void)
{
    int N, Q;
    string S;
    cin >> N;
    cin >> S;
    cin >> Q;
    string S1 = string(S.begin(), S.begin() + N);
    string S2 = string(S.begin() + N, S.end());
    bool isS1First = true;

    while (Q--)
    {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1)
        {
            a--, b--;
            if (isS1First)
            {
                if (a >= N)
                {
                    a -= N;
                    b -= N;
                    char temp = S2[a];
                    S2[a] = S2[b];
                    S2[b] = temp;
                }
                else
                {
                    if (b >= N)
                    {
                        b -= N;
                        char temp = S1[a];
                        S1[a] = S2[b];
                        S2[b] = temp;
                    }
                    else
                    {
                        char temp = S1[a];
                        S1[a] = S1[b];
                        S1[b] = temp;
                    }
                }
            }
            else
            {
                if (a >= N)
                {
                    a -= N;
                    b -= N;
                    char temp = S1[a];
                    S1[a] = S1[b];
                    S1[b] = temp;
                }
                else
                {
                    if (b >= N)
                    {
                        b -= N;
                        char temp = S2[a];
                        S2[a] = S1[b];
                        S1[b] = temp;
                    }
                    else
                    {
                        char temp = S2[a];
                        S2[a] = S2[b];
                        S2[b] = temp;
                    }
                }
            }
        }
        else
            isS1First ^= true;
    }
    if (isS1First)
        cout << S1 << S2;
    else
        cout << S2 << S1;
}