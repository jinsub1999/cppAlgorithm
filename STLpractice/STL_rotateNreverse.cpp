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

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string A = "123456789";
    vector<int> B = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 1; i < A.size(); i++)
    {
        rotate(A.begin(), A.begin() + 2, A.end());
        rotate(B.rbegin(), B.rbegin() + 1, B.rend());
        cout << A << '\n';
        copy(B.begin(), B.end(), ostream_iterator<int>(cout, " "));
        cout << '\n';
    }
    cout << A << '\n';
    reverse(A.begin(), A.end());
    cout << A << '\n';
    return 0;
}