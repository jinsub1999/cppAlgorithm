#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;

int solution(vector<vector<int>> jobs)
{
    int answer = 0;
    int prev = 0;
    vector<P> newJobs;
    vector<P> query;
    for (auto elem : jobs)
        query.push_back({elem[1], elem[0]});

    sort(query.begin(), query.end());

    vector<bool> visited(jobs.size(), false);
    while (newJobs.size() != query.size())
    {
        int _prev = 0;
        for (int i = 0; i < query.size(); i++)
        {
            int startTime = query[i].second;
            int timeVal = query[i].first;
            if (!visited[i] && _prev <= startTime)
            {
                visited[i] = true;
                newJobs.push_back({timeVal, startTime});
                _prev = startTime + timeVal;
            }
        }
    }

    for (auto elem : newJobs)
    {
        int startTime = elem.second;
        int timeVal = elem.first;
        // (timeVal + max(startTime, prevTime))- startTime
        answer += timeVal + max(prev, startTime) - startTime;
        // prev = max(prev, startTime)
        prev = max(prev, startTime) + timeVal;
    }
    int S = (int)newJobs.size();
    return answer / S;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << solution({{0, 3}, {1, 9}, {2, 6}});
}
