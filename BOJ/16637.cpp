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

int num_op(int a, int b, char o)
{
    switch (o)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    default:
        break;
    }
    return -1;
}
int nums;
int N;
vector<int> numbers;
vector<char> ops;

int bruteF(int indx, int curr)
{
    if (indx >= nums - 1)
        return curr;
    int ret = curr;
    ret = bruteF(indx + 1, num_op(curr, numbers[indx + 1], ops[indx]));
    if (indx + 2 < nums)
    {
        int inner = num_op(numbers[indx + 1], numbers[indx + 2], ops[indx + 1]);
        ret = max(ret, bruteF(indx + 2, num_op(curr, inner, ops[indx])));
    }

    return ret;
}
int main(void)
{
    fastIO;
    cin >> N;
    numbers.resize(N / 2 + 1);
    ops.resize(N / 2);
    nums = N / 2 + 1;

    string S;
    cin >> S;
    for (int i = 0; i < S.size(); i++)
    {
        if (i % 2)
            ops[i / 2] = S[i];
        else
            numbers[i / 2] = S[i] - '0';
    }
    cout << bruteF(0, numbers[0]);
    return 0;
}