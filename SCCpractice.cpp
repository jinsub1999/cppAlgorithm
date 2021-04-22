#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> Graph[10000];
vector<int> InvertedG[10000]; // 그래프, 역방향 그래프 준비
vector<bool> visited(10000, false);
vector<vector<int>> SCCs;
stack<int> St;
void dfs(int indx)
{
    for (auto elem : Graph[indx])
    {
        if (!visited[elem])
        {
            visited[elem] = true;
            dfs(elem);
        }
    }
    St.push(indx); // dfs가 끝나면 stack에 집어 넣기.
}

void InvertedDFS(int indx, int &SCCnum)
{
    SCCs[SCCnum].push_back(indx);
    for (auto elem : InvertedG[indx])
    {
        if (!visited[elem])
        {
            visited[elem] = true;
            InvertedDFS(elem, SCCnum);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // 코사라주 알고리즘
    // 그래프, 역방향 그래프, DFS, Stack
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++)
    {
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        Graph[A].push_back(B);
        InvertedG[B].push_back(A);
    }
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            visited[i] = true;
            dfs(i);
        }
    }
    visited = vector<bool>(10000, false);
    int sccNum = 0;
    while (!St.empty())
    {
        int reverseStart = St.top();
        if (!visited[reverseStart])
        {
            visited[reverseStart] = true;
            SCCs.push_back(vector<int>());
            InvertedDFS(reverseStart, sccNum);
            sort(SCCs[sccNum].begin(), SCCs[sccNum].end());
            sccNum++;
        }
        St.pop();
    }
    cout << sccNum << '\n';
    sort(SCCs.begin(), SCCs.end());
    for (auto elem : SCCs)
    {
        for (auto K : elem)
        {
            cout << K + 1 << ' ';
        }
        cout << -1 << '\n';
    }
    return 0;
}