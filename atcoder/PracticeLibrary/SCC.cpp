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

stack<int> St;
vector<bool> visited(500000, false);
vector<vector<int>> normalG(500000, vector<int>());  // normal Graph
vector<vector<int>> reverseG(500000, vector<int>()); // reverse Graph
vector<vector<int>> SCCs(0);

// find SCC : Kosaraju's Algorithm
// DFS -> push last elem ~ first elem into Stack
// 1 -> 2 -> 3 -> 1
// begin 1 -> St Top(1, 2, 3)Bottom
// St.top -> ReverseDFS -> one SCC
// 1 <- 2 <- 3 <- 1
// SCC(1, 3, 2)...

void normalDFS(int indx)
{
    for (int i : normalG[indx])
    {
        if (!visited[i])
        {
            visited[i] = true;
            normalDFS(i);
        }
    }
    St.push(indx); // Top(First_Node ... End_Node)Bottom
}

void reverseDFS(int indx, int SCC_num)
{
    SCCs[SCC_num].push_back(indx);

    for (int i : reverseG[indx])
        if (!visited[i])
        {
            visited[i] = true;
            reverseDFS(i, SCC_num);
        }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    int n, m;

    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;

        normalG[a].push_back(b);
        reverseG[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            normalDFS(i);
        }
    }
    int SCCn = 0;
    fill(visited.begin(), visited.end(), false);
    while (!St.empty())
    {
        int popItem = St.top();
        St.pop();

        if (!visited[popItem])
        {
            visited[popItem] = true;
            SCCs.push_back(vector<int>());
            reverseDFS(popItem, SCCn);
            SCCn++;
        }
    }
    cout << SCCs.size() << '\n';
    for (auto SCC : SCCs)
    {
        cout << SCC.size() << ' ';
        copy(SCC.begin(), SCC.end(), ostream_iterator<int>(cout, " "));
        cout << '\n';
    }
    return 0;
}