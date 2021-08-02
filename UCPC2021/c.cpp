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
#include <bitset>
#include <string>

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
double a, d, k;

double fastExpK(int d)
{
    if (d == 0)
        return 1;
    if (d == 1)
        return k;
    if (d % 2)
        return k * fastExpK(d - 1);
    else
    {
        double mid = fastExpK(d / 2);
        return mid * mid;
    }
}

bool calc_error(double t, double c)
{
    if (fabs(t - c) < 1e-7)
        return true;
    else
        return false;
}
stack<double> preCalc;
int main(void)
{
    fastIO;
    cin >> a >> d >> k;
    d /= 100.0;
    k /= 100.0;
    k += 1;

    int t = ceil((-log(d)) / log(k));
    // cout << t;

    if (d == 1)
    {
        cout << a / d;
        return 0;
    }
    double ans = d;
    int i = 2;

    preCalc.push(1 - d);
    while (d * k < 1)
    {
        ans += i * (d * k) * preCalc.top();
        d *= k;
        preCalc.push(preCalc.top() * (1 - d));
        i++;
    }
    ans += i * preCalc.top();
    cout.precision(9);
    cout << fixed << a * ans;
    return 0;
}