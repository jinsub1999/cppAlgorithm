#include <iostream>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>

using namespace std;

// copy(V.begin(), V.end(), ostream_iterator<value_type> (cout, " "));
// cout << accumulate(V.begin(), V.end(), 0LL) << '\n';

vector<bool> primes(10000000, true);
vector<bool> visited;
set<int> S_num;
void dfs(int num, vector<int>& nums)
{
  S_num.insert(num);
  for (int i = 0; i < nums.size(); i++)
  {
    if (!visited[i])
    {
      visited[i] = true;
      dfs(num * 10 + nums[i], nums);
      visited[i] = false;
    }
  }
}
int solution(string numbers) {
    int answer = 0;
    primes[0] = false;
    primes[1] = false;
    for (int i = 2; i * i < 10000000; i++)
    {
      if (primes[i])
      {
        for (int j = i * i; j < 10000000; j += i)
          primes[j] = false;
      }
    }
    vector<int> N;
    for (auto & elem : numbers)
      N.push_back(elem - '0');
    visited.resize(N.size(), false);
    S_num.clear();
    dfs(0, N);
    for (auto & i : S_num)
      if (primes[i]) answer++;
    
  return answer;
}
int main(void)
{cout << solution("011") << '\n';
  
  cout << solution("17") << '\n';
  return 0;
}