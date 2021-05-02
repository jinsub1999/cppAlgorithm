#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights)
{

    int truckN = 0;
    int BridgeW = 0;
    int sec = 0;
    vector<int> BRI(bridge_length, 0);
    while (truckN < truck_weights.size())
    {
        BridgeW -= BRI[bridge_length - 1];
        for (int i = bridge_length - 1; i > 0; i--)
            BRI[i] = BRI[i - 1];
        BRI[0] = 0;
        if (BridgeW + truck_weights[truckN] <= weight)
        {
            BRI[0] = truck_weights[truckN];
            BridgeW += BRI[0];
            truckN++;
        }
        sec++;
    }
    sec += bridge_length;
    return sec;
}
int main()
{
    cout << solution(1, 10, {7, 4, 5, 6}) << endl;
    cout << solution(2, 10, {7, 4, 5, 6}) << endl;
    cout << solution(100, 100, {10}) << endl;
    cout << solution(100, 100, {10, 10, 10, 10, 10, 10, 10, 10, 10, 10}) << endl;
    return 0;
}