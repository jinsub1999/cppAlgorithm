#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int Q;
    string S;
    string S1, S2;
    cin >> N;
    cin >> S;
    cin >> Q;
    S1 = string(S.begin(), S.begin() + N);
    S2 = string(S.begin() + N, S.end());
    bool isS1First = true;
    for (int i = 0; i < Q; i++)
    {
        int t, a, b;
        cin >> t >> a >> b;
        a--, b--;
        if (t == 1)
        {
            char temp;
            if (a >= N)
            {
                if (b >= N)
                {
                    a -= N;
                    b -= N;
                    if (isS1First)
                    {
                        temp = S2[a];
                        S2[a] = S2[b];
                        S2[b] = temp;
                    }
                    else
                    {
                        temp = S1[a];
                        S1[a] = S1[b];
                        S1[b] = temp;
                    }
                }
            }
            else
            {
                if (b >= N)
                {
                    b -= N;
                    if (isS1First)
                    {
                        temp = S1[a];
                        S1[a] = S2[b];
                        S2[b] = temp;
                    }
                    else
                    {
                        temp = S2[a];
                        S2[a] = S1[b];
                        S1[b] = temp;
                    }
                }
                else
                {
                    if (isS1First)
                    {
                        temp = S1[a];
                        S1[a] = S1[b];
                        S1[b] = temp;
                    }
                    else
                    {
                        temp = S2[a];
                        S2[a] = S2[b];
                        S2[b] = temp;
                    }
                }
            }
        }
        else
        {
            isS1First = isS1First ^ true;
        }
    }
    if (isS1First)
        cout << S1 << S2;
    else
        cout << S2 << S1;

    return 0;
}