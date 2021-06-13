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

vector<vector<ll>> MatMul(vector<vector<ll>> mat1, vector<vector<ll>> mat2)
{

    vector<vector<ll>> ret(2);
    ret[0] = {(mat1[0][0] * mat2[0][0] + mat1[0][1] * mat2[1][0]) % 1000000, (mat1[0][0] * mat2[0][1] + mat1[0][1] * mat2[1][1]) % 1000000};
    ret[1] = {(mat1[1][0] * mat2[0][0] + mat1[1][1] * mat2[1][0]) % 1000000, (mat1[1][0] * mat2[0][1] + mat1[1][1] * mat2[1][1]) % 1000000};
    return ret;
}
vector<vector<ll>> fastExpMat(vector<vector<ll>> &mat, ll d)
{
    if (d == 0)
        return {{1LL, 0LL}, {0LL, 1LL}};
    else if (d % 2)
        return MatMul(mat, fastExpMat(mat, d - 1));
    else
    {
        vector<vector<ll>> ret = fastExpMat(mat, d / 2);
        return MatMul(ret, ret);
    }
}

int main(void)
{
    fastIO;
    ll n;
    cin >> n;

    vector<vector<ll>> Mat(2);

    Mat[0] = {0, 1};
    Mat[1] = {1, 1};
    auto temp = fastExpMat(Mat, n);
    cout << temp[0][1];
    return 0;
}