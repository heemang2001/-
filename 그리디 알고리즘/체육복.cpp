#include <string>
#include <vector>

using namespace std;

// 배열 하나에 정리를 한다. 1로 초기화를 한 후 여분을 가져온 학생들은 + 1, 도난을 당한 학생들은 - 1을 한다.
// 그렇게 하면 총 3가지 경우가 생기는데,
//
// 0 : 도난을 당해서 체육복이 없는 학생
// 1 : 여분을 가지고 오지 않았으나 도난을 당하지 않은 학생, 또는 여분을 가지고 왔으나 도난을 당한 학생
// 2 : 여분도 가져오고 도난도 당하지 않은 학생
//
// 따라서 i = 0 부터 i = n 까지 반복문을 돌면서 i가 0일 때 앞 뒤 중에 2인 학생이 빌려주는 작업을 수행한다.

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