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
#include <cmath>

using namespace std;
#define PI 3.14159265358979323846
#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)

// int dy[4] = {0, 0, -1, 1};
// int dx[4] = {-1, 1, 0, 0};
// bool OOB(int y, int x, int N){return y < 0 || x < 0 || y >= N || x >= N;}

typedef long long ll;

vector<bool> prime(10000001, true);

void primeInit()
{
    prime[0] = false;
    prime[1] = false;
    for (ll i = 2; i < 10000000; i++)
    {
        if (prime[i])
        {
            for (ll j = i * i; j < 10000000; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

int pow10(int i)
{
    int ret = 1;
    while (i--)
        ret *= 10;
    return ret;
}

void doPermutation(set<int> &S, vector<int> V)
{
    do
    {
        int ret = 0;
        for (int i = 0; i < V.size(); i++)
            ret += V[i] * pow10(i);
        S.insert(ret);
    } while (next_permutation(V.begin(), V.end()));
}

int main(void)
{
    fastIO;
    int t;
    cin >> t;
    primeInit();
    while (t--)
    {
        string S;
        cin >> S;
        set<int> candi;
        vector<int> Per;
        for (auto elem : S)
            Per.push_back((int)(elem - '0'));

        int bitBool = 0;
        while (bitBool < (1 << Per.size()))
        {
            vector<int> forFunc;

            for (int i = 0; i < Per.size(); i++)
            {
                if (bitBool & (1 << i))
                    forFunc.push_back(Per[i]);
            }
            sort(forFunc.begin(), forFunc.end());
            doPermutation(candi, forFunc);
            bitBool++;
        }

        int cnt = 0;
        for (auto elem : candi)
            if (prime[elem])
                cnt++;

        cout << cnt << '\n';
    }
    return 0;
}