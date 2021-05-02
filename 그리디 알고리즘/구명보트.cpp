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

    int nPeople = people.size(); // ó�� ���ο�
    int answer = 0, idx = 0;
    int nOut = 0; // ���� �����

    while (1)
    { 
        if (people.size() == 1 || idx == people.size() - 1) // ���� ����� ȥ�ڸ� 
        {
            answer++;
            break;
        }

        int back = people.back();   // �ִ밪 
        people.pop_back();          // �ִ밪 pop
        nOut++;      

        if (people[idx] + back <= limit) // �ּҰ� + �ִ밪 <= limit �ΰ�?
        {
            answer++; // �ִ밪 + �ּҰ� 2���� ��Ʈ�� Ž
            nOut++;
            idx++;
        }

        else // �ּҰ� + �ִ밪�� limit���� ũ��
        {
            answer++; // �ִ밪 ȥ�� ��Ʈ�� Ž
        }

        if (nOut >= nPeople)
        {
            break;
        }
    }

    return answer;
}

//int solution(vector<int> people, int limit) {
//    sort(people.begin(), people.end());
//    reverse(people.begin(), people.end());
//    int N = (int)people.size();
//    int res = 0;
//    for (int i = 0, j = N - 1; i <= j; i++) {
//        if (people[i] + people[j] <= limit) {
//            j--;
//        }
//        res++;
//    }
//    return res;
//}

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