#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string number, int k)
{
    string answer = "";
    int numSize = number.size() - k;
    int start = 0;

    for (int i = 0; i < numSize; i++)
    {
        char maxNum = number[start];
        int maxIdx = start;

        for (int j = start; j <= k + i; j++)
        {
            if (maxNum < number[j])
            {
                maxNum = number[j];
                maxIdx = j;
            }
        }
        start = maxIdx + 1;
        answer += maxNum;
    }

    return answer;
}


int main()
{
    cout << solution("1924", 2) << '\n';        // 94
    cout << solution("1231234", 3) << '\n';     // 3234
    cout << solution("4177252841", 4) << '\n';  // 775841
}