#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;

    vector<double> V(n);

    for (int i = 0; i < n; i++)
        cin >> V[i];
    sort(V.begin(), V.end());

    double J = 0;
    double B = 0;
    for (int i = k; i < n - k; i++)
    {
        J += V[i];
        B += V[i];
    }
    cout.precision(2);
    J /= n - 2 * k;

    B += V[k] * k + V[n - k - 1] * k;
    B /= n;
    printf("%.2lf\n", J + 0.00000001);
    printf("%.2lf\n", B + 0.00000001);
}