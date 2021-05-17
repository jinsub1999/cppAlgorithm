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

typedef long long ll;

// int dy[4] = {0, 0, -1, 1};
// int dx[4] = {-1, 1, 0, 0};

// p가 소수이고 a가 어떤 정수일때.
// 1. a ^ (p - 1) = 1 (mod % p)
// 2. (1 / a) mod p = a ^ (p - 2)

// 위 원리에서 다음이 파생됨. (b 또한 어떤 정수)
// 1. (a * b) % p = (a % p) * (b % p)
// 2. (a / b) % p = (a % p) * ((b ^ (p - 2)) % p)

// final >> nCr % p = (n! / (n - r)! * r!) % p
// = (n! % p) * ((k! * (n - k)!) ^ (p - 2)) % p

// fac[i] = i! % p;
// fac_inv[i] = ((i!)^ (-1)) % p
// i * inverse(i!) = inverse((i - 1)!)

ll n, r, modu;

vector<ll> Fac;
vector<ll> FacInv;

ll fastPow(int a, int b) // a ^ b
{
    if (b == 0)
        return 1;
    ll ret;

    if (b % 2)
        ret = (a * fastPow(a, b - 1)) % modu;
    else
    {
        ret = fastPow(a, b / 2);
        ret = (ret * ret) % modu;
    }
    return ret;
}

void InitFac()
{
    Fac.resize(4000001, 1);
    for (int i = 1; i < 4000001; i++)
        Fac[i] = (Fac[i - 1] * i) % modu;

    FacInv.resize(4000001);
    FacInv[4000000] = fastPow(Fac[4000000], modu - 2);
    for (int i = 4000000; i > 0; i--)
        FacInv[i - 1] = (FacInv[i] * i) % modu;
    /* ret = nCr % P;
    ll ret = (Fac[n] * FacInv[r]) % modu;
    ret = (ret * FacInv[n - r]) % modu;
    cout << ret;
    */
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> r;
    modu = (int)1e9 + 7;
    // modu is prime modulo
    InitFac();

    // final >> nCr % p = (n! / (n - r)! * r!) % p
    // = (n! % p) * ((k! * (n - k)!) ^ (p - 2)) % p

    ll ret = (Fac[n] * FacInv[r]) % modu;
    ret = (ret * FacInv[n - r]) % modu;
    // 0 <= r <= n

    cout << (ret + modu) % modu;

    return 0;
}