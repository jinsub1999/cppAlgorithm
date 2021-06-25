#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(void)
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<ll> req(N);
    vector<ll> gets(N);
    vector<ll> preSum(N + 1);
    for (int i = 0; i < N; i++)
        cin >> req[i] >> gets[i];
    for (int i = 0; i < N; i++)
        preSum[i + 1] = preSum[i] + gets[i];
    vector<ll> maxs(N);
    maxs[0] = 0;
    for (int i = 1; i < N; i++)
        maxs[i] = max(maxs[i - 1], gets[i - 1]);
    bool flag = false;
    ll temp = 0;
    int tempIndx = 0;
    ll getsTotal = 0;
    for (int i = 0; i < N; i++)
    {
        if (getsTotal > req[i])
        {
            if (flag)
            {
                auto M = max_element(gets.begin(), gets.begin() + tempIndx);
                if (getsTotal + temp - maxs[tempIndx] > req[i])
                {
                    cout << "Zzz";
                    return 0;
                }
                else if (preSum[tempIndx] - maxs[tempIndx] > req[tempIndx])
                {
                    cout << "Zzz";
                    return 0;
                }
                else
                {
                    getsTotal = getsTotal + temp - maxs[tempIndx] + gets[i];
                    temp = maxs[tempIndx];
                    tempIndx = M - gets.begin();
                }
            }
            else
            {
                flag = true;
                temp = gets[i];
                tempIndx = i;
            }
        }
        else
            getsTotal += gets[i];
    }
    cout << "Kkeo-eok";
    return 0;
}