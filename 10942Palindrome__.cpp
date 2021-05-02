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
    cin >> N;
    vector<int> V(N);
    vector<vector<bool>> AtoB(N, vector<bool>(N, false));
    for (auto &elem : V)
        cin >> elem;

    int startPoint = 0;
    while (startPoint < N)
    {
        AtoB[startPoint][startPoint] = true;
        for (int nextP = 1; nextP <= 2; nextP++)
        {
            if (startPoint + nextP < N && V[startPoint] == V[startPoint + nextP])
            {
                AtoB[startPoint][startPoint + nextP] = true;
                int left = startPoint - 1;
                int right = startPoint + nextP + 1;
                while (left >= 0 && right < N)
                {
                    if (V[left] == V[right])
                    {
                        AtoB[left][right] = true;
                        left--;
                        right++;
                    }
                    else
                        break;
                }
            }
        }
        startPoint++;
    }

    int Queries;
    cin >> Queries;
    while (Queries--)
    {
        int s, e;
        cin >> s >> e;
        s--, e--;
        if (AtoB[s][e])
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
}