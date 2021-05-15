#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <cmath>
using namespace std;

vector<long long> solution(vector<long long> numbers)
{
    vector<long long> answer;

    for (auto elem : numbers)
    {
        if (elem % 2 == 0)
        {
            answer.push_back(elem + 1);
        }
        else
        {
            for (int i = 0; i < 62; i++)
            {
                if ((elem & (1LL << i)) && !(elem & (1LL << (i + 1))))
                {
                    elem &= ~(1LL << i);
                    elem |= (1LL << (i + 1));
                    answer.push_back(elem);
                    break;
                }
            }
        }
    }

    return answer;
}

long long pOw2(int b)
{
    long long ret = 1;
    while (b--)
    {
        ret *= 2LL;
    }
    return ret;
}

int main(void)
{
    vector<long long> T = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    for (long long i = 0; i < 62; i++)
    {
        T.push_back(pOw2(i) - 1);
    }
    auto K = solution(T);
    for (int i = 0; i < T.size(); i++)
    {
        cout << T[i] << ' ' << K[i] << '\n';
    }
}