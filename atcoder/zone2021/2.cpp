#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <set>
#include <numeric>

using namespace std;

int main(void)
{
    int N;
    double D, H;
    cin >> N >> D >> H;
    double maxHeight = 0.0;

    for (int i = 0; i < N; i++)
    {
        double di, hi;
        cin >> di >> hi;

        double currH = H - D * ((H - hi) / (D - di));
        maxHeight = max(maxHeight, currH);
    }
    cout.precision(10);
    cout << maxHeight;
    return 0;
}