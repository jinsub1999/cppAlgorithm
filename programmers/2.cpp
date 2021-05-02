#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int N, int number)
{
    queue<pair<int, int>> Q;
    int answer = 100;
    Q.push({0, 0});
    while (!Q.empty())
    {
        auto popItem = Q.front();

        int val = popItem.first;
        int cnt = popItem.second;
        Q.pop();

        if (val == number)
            answer = min(answer, cnt);

        int mycnt = cnt;
        int d = N;
        while (mycnt < 8)
        {
            Q.push({val + d, mycnt + 1});
            Q.push({val - d, mycnt + 1});
            Q.push({val * d, mycnt + 1});
            Q.push({val / d, mycnt + 1});

            d = d * 10 + N;
            mycnt++;
        }
    }
    if (answer == 100)
        return -1;
    return answer;
}
int main()
{
    cout << solution(2, 11) << endl;
    return 0;
}