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

int gcd(int a, int b)
{
    if (b > a)
        swap(a, b);

    if (b == 0)
        return a;

    return gcd(b, (a % b));
}

// int dy[4] = {0, 0, -1, 1};
// int dx[4] = {-1, 1, 0, 0};
// bool OOB(int y, int x, int N){return y < 0 || x < 0 || y >= N || x >= N;}

typedef long long ll;

int main(void)
{
    fastIO;

    int N;
    cin >> N;
    vector<int> test = {6, 10, 15};
    set<int> S;
    S.insert(6);
    S.insert(10);
    S.insert(15);
    int temp;

    temp = test[0];
    while (temp + test[0] <= 10000)
    {
        if (S.size() == N)
            break;
        temp += test[0];
        S.insert(temp);
    }
    temp = test[1];
    while (temp + test[1] <= 10000)
    {
        if (S.size() == N)
            break;
        temp += test[1];
        S.insert(temp);
    }
    temp = test[2];
    while (temp + test[2] <= 10000)
    {
        if (S.size() == N)
            break;
        temp += test[2];
        S.insert(temp);
    }
    copy(S.begin(), S.end(), ostream_iterator<int>(cout, " "));
    return 0;
}