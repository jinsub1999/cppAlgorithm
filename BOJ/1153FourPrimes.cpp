#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

vector<vector<int>> Q(1000001, vector<int>());
vector<bool> eratos(1000001, true);

int main(void)
{
    eratos[0] = false;
    eratos[1] = false;
    for (int i = 2; i * i < 1000001; i++)
    {
        if (eratos[i])
            for (int j = i * i; j < 1000001; j += i)
                eratos[j] = false;
    }
    int cnt = 0;
    for (int i = 2; i < 1000001; i++)
        if (eratos[i])
        {
            cnt++;
        }
    cout << cnt;
    return 0;
}