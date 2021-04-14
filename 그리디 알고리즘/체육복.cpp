#include <string>
#include <vector>

using namespace std;

// �迭 �ϳ��� ������ �Ѵ�. 1�� �ʱ�ȭ�� �� �� ������ ������ �л����� + 1, ������ ���� �л����� - 1�� �Ѵ�.
// �׷��� �ϸ� �� 3���� ��찡 ����µ�,
//
// 0 : ������ ���ؼ� ü������ ���� �л�
// 1 : ������ ������ ���� �ʾ����� ������ ������ ���� �л�, �Ǵ� ������ ������ ������ ������ ���� �л�
// 2 : ���е� �������� ������ ������ ���� �л�
//
// ���� i = 0 ���� i = n ���� �ݺ����� ���鼭 i�� 0�� �� �� �� �߿� 2�� �л��� �����ִ� �۾��� �����Ѵ�.

int solution(int n, vector<int> lost, vector<int> reserve)
{
    int answer = 0;
    vector<int> students(n, 1);

    for (int i = 0; i < reserve.size(); i++)
    {
        students[reserve[i] - 1]++;
    }

    for (int i = 0; i < lost.size(); i++)
    {
        students[lost[i] - 1]--;
    }

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && students[i] == 0 && students[i - 1] == 2)
        {
            students[i - 1]--; students[i]++;
        }

        if (i < n - 1 && students[i] == 0 && students[i + 1] == 2)
        {
            students[i + 1]--; students[i]++;
        }
    }

    //for (int s : students)
    //{
    //    if (s > 0) answer++;
    //}

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i] > 0)
        {
            answer++;
        }
    }

    return answer;
}