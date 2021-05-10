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
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)

// int dy[4] = {0, 0, -1, 1};
// int dx[4] = {-1, 1, 0, 0};
// bool OOB(int y, int x, int N){return y < 0 || x < 0 || y >= N || x >= N;}

typedef long long ll;

int main(void)
{
    fastIO;

    int T;
    cin >> T;
    while (T--)
    {
        int k;
        cin >> k;
        priority_queue<ll, vector<ll>, less<>> PQ_l;
        priority_queue<ll, vector<ll>, greater<>> PQ_g;
        map<ll, int> invalidL;
        map<ll, int> invalidG;
        while (k--)
        {
            char op;
            int n;

            cin >> op >> n;

            if (op == 'I')
            {
                PQ_l.push(n);
                PQ_g.push(n);
            }
            else
            {
                if (n == 1)
                {
                    while (!PQ_l.empty())
                    {
                        if (invalidL[PQ_l.top()])
                        {
                            invalidL[PQ_l.top()]--;
                            PQ_l.pop();
                        }
                        else
                        {
                            invalidG[PQ_l.top()]++;
                            PQ_l.pop();
                            break;
                        }
                    }
                }
                else
                {
                    while (!PQ_g.empty())
                    {
                        if (invalidG[PQ_g.top()])
                        {
                            invalidG[PQ_g.top()]--;
                            PQ_g.pop();
                        }
                        else
                        {
                            invalidL[PQ_g.top()]++;
                            PQ_g.pop();
                            break;
                        }
                    }
                }
            }
        }
        while (!PQ_g.empty())
        {
            if (invalidG[PQ_g.top()])
            {
                invalidG[PQ_g.top()]--;
                PQ_g.pop();
            }
            else
                break;
        }
        while (!PQ_l.empty())
        {
            if (invalidL[PQ_l.top()])
            {
                invalidL[PQ_l.top()]--;
                PQ_l.pop();
            }
            else
                break;
        }
        if (PQ_g.empty() && PQ_l.empty())
        {
            cout << "EMPTY\n";
        }
        else
        {
            cout << PQ_l.top() << ' ' << PQ_g.top() << '\n';
        }
    }

    return 0;
}