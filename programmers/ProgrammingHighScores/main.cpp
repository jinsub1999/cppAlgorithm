#include <iostream>
#include <queue>
#include <stack>
#include <deque>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>

using namespace std;

// copy(V.begin(), V.end(), ostream_iterator<value_type> (cout, " "));
// cout << accumulate(V.begin(), V.end(), 0LL) << '\n';

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  
	vector<int> V = {1, 2, 3, 4, 5};
	vector<char> V2 = {'a', 'b', 'c', 'd', 'e'};
 copy(V.begin(), V.end(), ostream_iterator<int>(cout, " "));
	cout << '\n';
 copy(V2.begin(), V2.end(), ostream_iterator<char>(cout, " ")); 
 cout << '\n' << '\n';
 cout << accumulate(V.begin(), V.end(), 0LL) << '\n';
}