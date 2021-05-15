#include <string>
#include <vector>
#include <cmath>

using namespace std;

bool ifPOW(int n)
{
    int K = (int)sqrt(n);
    return (n == K * K);
}

int solution(int left, int right)
{
    int answer = 0;
    for (int c = left; c <= right; c++)
    {
        if (ifPOW(c))
        {
            answer -= c;
        }
        else
        {
            answer += c;
        }
    }
    return answer;
}

int main(void)
{
}
