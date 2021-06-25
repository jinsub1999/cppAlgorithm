#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

const ll DIV = (int)1e9 + 7;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    queue<ll> Q[7];
    vector<ll> A(N);
    for (int i = 0; i < N; i++)
    {
        ll temp;
        cin >> temp;
        A[i] = temp;
        Q[temp % 7].push(i);
    }

    ll total = 0;
    ll checkInt = 0;

    for (int i = 0; i < M; i++)
    {
        ll temp;
        cin >> temp;
        checkInt += temp;
        checkInt %= 7;
        int delNum = 7 - checkInt;
        if (delNum == 7)
            delNum = 0;

        signed s = 0;
        for (int i = 0; i < 7; i++)
            s += Q[i].size();
        if (Q[delNum].size() == s)
            checkInt = (checkInt - temp + 7) % 7;
        else
        {
            while (!Q[delNum].empty())
                Q[delNum].pop();
            total += temp;
            total %= DIV;
        }
    }
    priority_queue<int, vector<int>, greater<>> PQ;

    for (int i = 0; i < 7; i++)
        while (!Q[i].empty())
        {
            PQ.push(Q[i].front());
            Q[i].pop();
        }
    cout << PQ.size() << '\n';
    while (!PQ.empty())
    {
        int i = PQ.top();
        cout << (A[i] + total) % DIV << ' ';
        PQ.pop();
    }

    return 0;
}