#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    for (int i = 0; i < n; i++)
        cin >> B[i];

    sort(A.rbegin(), A.rend());
    sort(B.begin(), B.end());

    if (B[0] - A[0] + 1 > 0)
        cout << B[0] - A[0] + 1;
    else
        cout << 0;
    return 0;
}