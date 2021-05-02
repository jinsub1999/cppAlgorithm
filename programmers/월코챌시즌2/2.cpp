#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int solution(string s)
{
    int answer = 0;
    string newS;
    for (int i = 0; i < s.length(); i++)
    {
        newS = string(s.begin() + i, s.end()) + string(s.begin(), s.begin() + i);
        stack<char> St;
        bool flag = true;
        for (auto elem : newS)
        {
            if (elem == ']')
            {
                if (St.empty() || St.top() != '[')
                {
                    flag = false;
                    continue;
                }
                else
                    St.pop();
            }
            else if (elem == ')')
            {
                if (St.empty() || St.top() != '(')
                {
                    flag = false;
                    continue;
                }
                else
                    St.pop();
            }
            else if (elem == '}')
            {
                if (St.empty() || St.top() != '{')
                {
                    flag = false;
                    continue;
                }
                else
                    St.pop();
            }
            else
                St.push(elem);
        }
        if (flag && St.empty())
            answer++;
    }

    return answer;
}

int main(void)
{
    cout << solution("[](){}") << endl;
    cout << solution("}]()[{") << endl;
    cout << solution("[)(]") << endl;
    cout << solution("}}}") << endl;
}