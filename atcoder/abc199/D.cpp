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