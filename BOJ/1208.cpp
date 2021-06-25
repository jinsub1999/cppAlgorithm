#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

int main(void)
{
    int N, S;
    cin >> N >> S;
    vector<int> V(N);
    for (auto &elem : V)
        cin >> elem;
    sort(V.begin(), V.end());
    map<int, ll> M;
    int left = N / 2;
    int right = N - left;
    int bitBool = 0;

    while (bitBool < (1 << left))
    {
        int tot = 0;
        for (int i = 0; i < left; i++)
            if (bitBool & (1 << i))
                tot += V[i];
        if (M.find(tot) == M.end())
            M[tot] = 1;
        else
            M[tot] += 1;
        bitBool++;
    }
    ll ans = 0;
    bitBool = 0;
    while (bitBool < (1 << right))
    {
        int tot = 0;
        for (int i = 0; i < right; i++)
            if (bitBool & (1 << i))
                tot += V[left + i];
        if (M.find(S - tot) != M.end())
            ans += M[S - tot];
        bitBool++;
    }
    if (S == 0)
        ans--;
    cout << ans;
    return 0;
}