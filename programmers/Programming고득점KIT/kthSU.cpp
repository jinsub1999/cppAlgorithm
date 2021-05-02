#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands)
{
    vector<int> answer;

    for (auto elem : commands)
    {
        int s = elem[0], e = elem[1], n_th = elem[2];
        vector<int> newArr(array.begin() + s - 1, array.begin() + e);
        sort(newArr.begin(), newArr.end());
        answer.push_back(newArr[n_th - 1]);
    }
    return answer;
}

int main(void)
{
    vector<int> res = solution({1, 5, 2, 6, 3, 7, 4}, {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}});
    copy(res.begin(), res.end(), ostream_iterator<int, char>(cout, " "));
}