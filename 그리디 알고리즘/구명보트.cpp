#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 사람들의 몸무게 people
// 구명보트 무게제한 limit
// 모든 사람을 구출하기 위해 필요한 구명보트수 최솟값 return
// 보트는 한번에 최대 2명씩만 이용가능
int solution(vector<int> people, int limit)
{
    sort(people.begin(), people.end());

    int answer = 0, idx = 0;

    while (1)
    {
        int back = people.back();   // 최대값 
        people.pop_back();          // 최대값 pop

        if (idx > people.size() - 1)
        {
            answer++;
            break;               
        }

        if (people.size() == 0)
        {
            answer++;
            break;
        }

        if (people[idx] + back <= limit) // 최소값 + 최대값 <= limit 인가?
        {
            answer++; // 최대값 + 최소값 2명이 보트에 탐
            idx++;
        }

        else // 최소값 + 최대값이 limit보다 크다
        {
            answer++; // 최대값 혼자 보트에 탐
        }

        if (idx >= people.size())
        {
            break;
        }

        
    }

    return answer;
}

int main()
{
    vector<int> vec1 = { 70, 50, 80, 50 };
    cout << solution(vec1, 100) << '\n'; // 3

    vector<int> vec2 = { 70, 80, 50 };
    cout << solution(vec2, 100) << '\n'; // 3

    vector<int> vec3 = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
    cout << solution(vec3, 100) << '\n'; // 5

    vector<int> vec4 = { 40,40,40 };
    cout << solution(vec4, 100) << '\n'; // 2

    return 0;
}