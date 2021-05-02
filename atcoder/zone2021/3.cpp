#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <algorithm>
#include <set>
#include <numeric>
#include <deque>

using namespace std;

int main(void)
{
    string S;
    cin >> S;
    string T = "";
    deque<char> STR;
    deque<char> Reverse;
    bool reversed = false;
    for (auto elem : S)
    {
        if (elem == 'R')
        {
            reversed ^= true;
        }
        else
        {
            if (reversed)
                STR.push_front(elem);
            else
                STR.push_back(elem);
        }
    }
    if (reversed)
        STR = deque<char>(STR.rbegin(), STR.rend());

    stack<char> St;
    for (auto elem : STR)
    {
        if (St.empty())
            St.push(elem);
        else
        {
            if (elem == St.top())
                St.pop();
            else
                St.push(elem);
        }
    }

    string newT = "";
    while (!St.empty())
    {
        newT += St.top();
        St.pop();
    }

    newT = string(newT.rbegin(), newT.rend());
    cout << newT;
    return 0;
}