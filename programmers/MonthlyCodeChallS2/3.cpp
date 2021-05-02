#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <queue>

using namespace std;

long long solution(vector<int> a, vector<vector<int>> edges)
{
    if (!accumulate(a.begin(), a.end(), 0LL))
    {
        vector<long long> newA(a.begin(), a.end());
        long long answer = 0;
        vector<vector<int>> adj(a.size(), vector<int>());
        vector<int> indegree(a.size(), 0);
        for (auto elem : edges)
        {
            adj[elem[0]].push_back(elem[1]);
            adj[elem[1]].push_back(elem[0]);
            indegree[elem[0]]++;
            indegree[elem[1]]++;
        }
        queue<int> Q;
        for (int i = 0; i < a.size(); i++)
            if (indegree[i] == 1)
                Q.push(i);

        while (!Q.empty())
        {
            int popItem = Q.front();
            Q.pop();

            indegree[popItem] = -1;
            answer += abs(newA[popItem]);
            for (auto elem : adj[popItem])
            {
                if (indegree[elem] >= 1)
                {
                    newA[elem] += newA[popItem];
                    indegree[elem]--;
                    newA[popItem] = 0;
                }
                if (indegree[elem] == 1)
                    Q.push(elem);
            }
        }

        return answer;
    }
    else
    {
        return -1;
    }
}

int main()
{
    cout << solution({-5, 0, 2, 1, 2}, {{0, 1}, {3, 4}, {2, 3}, {0, 3}}) << '\n';
    cout << solution({3, 2, -2, 1, -4}, {{0, 1}, {3, 4}, {2, 3}, {0, 3}}) << '\n';
    cout << solution({0, 1, 0}, {{0, 1}, {1, 2}}) << '\n';
}