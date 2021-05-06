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

/*
Atcoder zone2021
https://atcoder.jp/contests/zone2021/tasks/zone2021_d

D. message from aliens

문자열 S를 입력받아 문자열 T를 생성하려고한다.

초기 T = "" 이고
S의 i번째 문자를 S_i라 하면
S_i가 R이라면 T를 뒤집고
아니라면 T의 맨 뒤에 S_i를 추가한다.

위 과정이 끝나면, T에 연속된 두 문자가 존재하면
그 두 문자를 지우고 앞뒤를 합친다.
존재하지 않을 때까지 위 과정을 반복하고,
T를 출력하시오.

풀이법 : 
S를 입력받고 T를 보관하는 장소를 덱(양쪽 끝에 집어넣을 수 있는 자료구조)이라 하자.

R이 나오면 집어넣는 방향을 앞<->뒤로 바꾸고,
아니면 그 방향대로 집어넣는다.
처음엔 뒤부터 집어넣는다.

예제: ozRnonnoe
앞              뒤
앞            o 뒤
앞           oz 뒤
     앞뒤 전환
앞 n         oz 뒤
앞 on        oz 뒤

집어넣는 방향 반대에서부터 읽으면 과정 2 이전의 T이다.
이후 삭제하는 과정은 stack을 이용하면 간단히 구현가능하다.

시간복잡도 : O(N)

review : 덱을 떠올리기 전엔 어떻게 구현할까 막막했는데 빨리떠올라서 다행이다.
*/

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