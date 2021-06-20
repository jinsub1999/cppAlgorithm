#include <iostream>

using namespace std;

typedef long long ll;

ll fastExp(ll d, ll n)
{
    if (n == 0)
        return 1LL;
    else if (n == 1)
        return d;
    if (n % 2)
        return d * fastExp(d, n - 1);
    else
    {
        ll ret = fastExp(d, n / 2);
        return ret * ret;
    }
}

int main(void)
{
    int T;
    cin >> T;
    while (T--)
    {
        ll n;
        cin >> n;

        ll ret = 0;
        for (int indx = 0; indx < 64; indx++)
        {
            if (n & (1LL << indx))
                ret += fastExp(3, indx);
        }
        cout << ret << '\n';
    }
    return 0;
}