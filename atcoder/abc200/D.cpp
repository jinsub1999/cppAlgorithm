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
#include <cassert>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)

int main(void)
{
    fastIO;

    ll N;
    cin >> N;
    vector<ll> A(N);

    for (int i = 0; i < N; i++)
    {
        ll &elem = A[i];
        cin >> elem;
        elem %= 200;
    }

    // up-solving __ point : 비둘기집 원리.

    // 문제 : 특정 두 수열의 합 (mod 200)가 같은가.

    // 201개의 수열을 준비하면 mod 200이 같은 수열이 두개 이상 항상 존재한다.
    // N개의 원소중에 중복하지 않고 수열을 고르면 2 ^ N - 1개.
    // 이론적으로 8개의 원소만 있어도 2 ^ 8 - 1 = 255개의 수열을 뽑을 수 있고
    // 이중에 무조건 mod 200이 같은 수열이 존재한다.
    // 비트마스킹으로 수열을 뽑을 수 있다.

    // review : 난 부분합이라고 생각해서 풀었는데 다른 풀이법이었다.
    // 비둘기집 원리는 알고는 있었는데 실제 적용해볼려니까 안되네...
    vector<vector<vector<int>>> DivCounts(200, vector<vector<int>>(0));
    if (N < 8)
    {
        ll bitBool = 1;

        while (bitBool < (1 << N))
        {
            ll S = 0;
            vector<int> elems;
            for (int i = 0; i < N; i++)
            {
                if (bitBool & (1 << i))
                {
                    elems.push_back(i + 1);
                    S += A[i];
                    S %= 200;
                }
            }
            DivCounts[S].push_back(elems);
            if (DivCounts[S].size() == 2)
            {
                cout << "Yes" << '\n';
                cout << DivCounts[S][0].size() << ' ';
                copy(DivCounts[S][0].begin(), DivCounts[S][0].end(), ostream_iterator<int>(cout, " "));
                cout << '\n';
                cout << DivCounts[S][1].size() << ' ';
                copy(DivCounts[S][1].begin(), DivCounts[S][1].end(), ostream_iterator<int>(cout, " "));
                cout << '\n';
                exit(0);
            }
            bitBool++;
        }
        cout << "No";
    }
    else
    {
        ll bitBool = 1;

        while (true)
        {
            ll S = 0;
            vector<int> elems;
            for (int i = 0; i < N; i++)
            {
                if (bitBool & (1 << i))
                {
                    elems.push_back(i + 1);
                    S += A[i];
                    S %= 200;
                }
            }
            DivCounts[S].push_back(elems);
            if (DivCounts[S].size() == 2)
            {
                cout << "Yes" << '\n';
                cout << DivCounts[S][0].size() << ' ';
                copy(DivCounts[S][0].begin(), DivCounts[S][0].end(), ostream_iterator<int>(cout, " "));
                cout << '\n';
                cout << DivCounts[S][1].size() << ' ';
                copy(DivCounts[S][1].begin(), DivCounts[S][1].end(), ostream_iterator<int>(cout, " "));
                cout << '\n';
                exit(0);
            }
            bitBool++;
        }
    }

    return 0;
}