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

vector<bool> prime(4000001, true);
vector<int> primes;
vector<ll> presumPrime;

void getPrime()
{
    prime[0] = prime[1] = false;
    for (ll i = 2; i < 4000001; i++)
    {
        if (prime[i])
        {
            primes.push_back(i);
            for (ll j = i * i; j < 4000001LL; j += i)
                prime[j] = false;
        }
    }
    presumPrime.resize(primes.size() + 1, 0LL);
    for (int i = 0; i < primes.size(); i++)
        presumPrime[i + 1] = presumPrime[i] + primes[i];
}

int main(void)
{
    fastIO;
    int n;
    cin >> n;
    getPrime();
    int left = 0, right = 1;

    int ans = 0;
    while (right < presumPrime.size())
    {
        int curr = presumPrime[right] - presumPrime[left];
        if (curr > n)
            left++;
        else if (curr < n)
            right++;
        else if (curr == n)
        {
            ans++;
            left++;
        }
    }
    cout << ans << '\n';

    return 0;
}