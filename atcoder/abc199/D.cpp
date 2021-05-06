#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> Graph[21];
vector<vector<int>> possicolor(21, {1, 1, 1});
// color 0, 1, 2
vector<int> currColor(21, -1);
vector<bool> visited(21, false);
vector<int> nodeList;
int ans;
bool check()
{
  for (auto i : nodeList)
  {
    for (auto j : Graph[i])
    {
      if (currColor[i] == currColor[j])
        return false;
    }
  }
  return true;
}

void dfsFindNodeList(int indx)
{
  nodeList.push_back(indx);
  visited[indx] = true;
  for (int i : Graph[indx])
  {
    if (!visited[i])
    {
      dfsFindNodeList(i);
    }
  }
}

int dfsColoring(int indx)
{
  if (indx == nodeList.size())
  {
    if (check())
      return 1;
  }
  else
  {
    int ret = 0;
    vector<int> Q(3, true);
    for (auto elem : Graph[nodeList[indx]])
    {
      if (currColor[elem] != -1)
        Q[currColor[elem]] = false;
    }
    for (int c = 0; c < 3; c++)
    {
      if (Q[c])
      {
        currColor[nodeList[indx]] = c;
        ret += dfsColoring(indx + 1);
        currColor[nodeList[indx]] = -1;
      }
    }
    return ret;
  }
}

/*
AtCoder Beginner Contest 199
D. RGB Coloring 2

https://atcoder.jp/contests/abc199/tasks/abc199_d

정점이 N개이고 M개의 간선으로 이루어진
단순 무방향 그래프가 있다.
각각의 정점에 R, G, B를 칠하여
간선으로 연결된 정점끼리 구별되게 하려한다.
이때 칠할 수 있는 가짓수를 출력하시오.

풀이법 : 
그냥 3^N의 완전탐색으로 하면 N <= 20이라서
시간초과가 발생한다.

이때 미방문한 정점을 3가지로 칠하고
DFS로 방문하지 않은 정점을 최대 2가지로 칠하게 되면
3 * 2^(N - 1)의 시간복잡도를 가지게 된다.

먼저 DFS로 연결되어 있는 컴포넌트들을 정리하고(nodeList)
그 컴포넌트의 임의의 점에서 dfs(R), dfs(G), dfs(B)를 호출한다.

DFS를 하면서 연결된 정점들의 색을 확인하여
색을 칠하고 컴포넌트의 모든 색을 칠하고 (nodeList.size() == indx)
가능하다면(check() 함수) 1을,
불가능하다고 판단되면 0을 반환한다.

이를 dfs()로 다 더한값을 반환하여 더하면 한 컴포넌트의 가짓수가 나온다.
(dfs()를 세번 호출하지 않아도 3 * dfs()하면 세번 칠한게 된다.)

모든 컴포넌트의 가짓수를 다 곱하면 답이 나온다.

시간복잡도 : O(3 * 2^N)

review : 완전탐색 문제였는데 생각이 떠오르지 않았다.
*/

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++)
  {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    if (a > b)
    {
      int temp = a;
      a = b;
      b = temp;
    }
    Graph[a].push_back(b);
    Graph[b].push_back(a);
  }

  long long answer = 1;
  for (int i = 0; i < n; i++)
  {
    if (!visited[i])
    {
      visited[i] = true;
      nodeList.clear();
      dfsFindNodeList(i);
      if (nodeList.size() == 1)
        answer *= 3;
      else
        answer *= dfsColoring(0);
    }
  }
  cout << answer;
  return 0;
}