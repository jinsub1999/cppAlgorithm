#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

vector<int> Stu1 = {1, 2, 3, 4, 5};
vector<int> Stu2 = {2, 1, 2, 3, 2, 4, 2, 5};
vector<int> Stu3 = {3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    int s1 = 0;
    int s2 = 0;
    int s3 = 0;
    
    for (int i = 0; i < answers.size(); i++)
    {
      if (Stu1[i % 5] == answers[i]) s1++;
      if (Stu2[i % 8] == answers[i]) s2++;
      if (Stu3[i % 10] == answers[i]) s3++;
    }
    int M = max(s1, max(s2, s3));
    vector<int> answer;
    if (s1 == M) answer.push_back(1);
    if (s2 == M) answer.push_back(2);
    if (s3 == M) answer.push_back(3);
    
    return answer;
}
int main(void)
{
  vector<int> V = solution({1,2,3,4,5});
  copy(V.begin(), V.end(), ostream_iterator<int>(cout, " "));
  cout << '\n';
  V = solution({1,3,2,4,2});
  copy(V.begin(), V.end(), ostream_iterator<int>(cout, " "));
}