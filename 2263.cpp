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

// InOrder -> LEFT _ N _ RIGHT
// postOrder -> LEFT _ RIGHT _ N

// preOrder -> N _ LEFT _ RIGHT

int n;
vector<int> InOrder;
vector<int> PostOrder;
map<int, int> findInorder; // val -> indx
vector<int> PreOrder;
void findRootPostOrder(int s, int e, int InS, int InE)
{
    if (s > e || InS > InE)
        return;
    PreOrder.push_back(PostOrder[e]);
    if (s == e)
        return;
    int root = PostOrder[e];
    int l = findInorder[root] - InS;
    findRootPostOrder(s, s + l - 1, InS, findInorder[root] - 1);
    findRootPostOrder(s + l, e - 1, findInorder[root] + 1, InE);
    return;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    InOrder.resize(n);
    PostOrder.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> InOrder[i];
        findInorder[InOrder[i]] = i;
    }
    for (auto &elem : PostOrder)
        cin >> elem;

    findRootPostOrder(0, n - 1, 0, n - 1);
    copy(PreOrder.begin(), PreOrder.end(), ostream_iterator<int>(cout, " "));
    return 0;
}