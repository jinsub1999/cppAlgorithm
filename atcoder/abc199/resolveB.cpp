#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void)
{
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (auto &elem : A)
        cin >> elem;
    for (auto &elem : B)
        cin >> elem;

    int currMin = (int)1e9;
    int currMax = 0;

    for (auto elem : A)
        currMax = max(currMax, elem);
    for (auto elem : B)
        currMin = min(currMin, elem);

    cout << (currMax <= currMin ? currMin - currMax + 1 : 0);
    return 0;
}