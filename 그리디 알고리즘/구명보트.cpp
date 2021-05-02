#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// ������� ������ people
// ����Ʈ �������� limit
// ��� ����� �����ϱ� ���� �ʿ��� ����Ʈ�� �ּڰ� return
// ��Ʈ�� �ѹ��� �ִ� 2���� �̿밡��
int solution(vector<int> people, int limit)
{
    sort(people.begin(), people.end());

    int answer = 0, idx = 0;

    while (1)
    {
        int back = people.back();   // �ִ밪 
        people.pop_back();          // �ִ밪 pop

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

        if (people[idx] + back <= limit) // �ּҰ� + �ִ밪 <= limit �ΰ�?
        {
            answer++; // �ִ밪 + �ּҰ� 2���� ��Ʈ�� Ž
            idx++;
        }

        else // �ּҰ� + �ִ밪�� limit���� ũ��
        {
            answer++; // �ִ밪 ȥ�� ��Ʈ�� Ž
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