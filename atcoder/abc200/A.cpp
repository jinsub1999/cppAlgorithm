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

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

#define fastIO                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL)

int main(void)
{
    fastIO;

    int n;
    cin >> n;

    cout << ((n - 1) / 100) + 1;

    return 0;
}