#include <string>
#include <vector>
#include <iostream>

using namespace std;

// A B C D E F G H I J K L M N O P Q R S T U V W X Y Z

int solution(string name)
{
    int answer = 0;

    // ���ڿ� ����
    int nNameLenth = name.length();      

    // ������, ���� ��� �������� ������ ������?
    int nTurn = nNameLenth - 1; // �ִ� �̵�Ƚ��

    // Ŀ�� �̵�
    int nMove = 0;
    
    for (int i = 0; i < nNameLenth; i++)
    {
        int nRightMove = name[i] - 'A';     // ���������� �̵��� 
        int nLeftMove = 'Z' - name[i] + 1;  // �������� �̵���( +1�� �Ʒ�ȭ��ǥ������ 'Z'�� ���°� )

        // (���ĺ�)�������� ��ȯ�� �� ������
        if (nRightMove > nLeftMove)
        {
            answer += nLeftMove;
        }

        // (���ĺ�)���������� ��ȯ�� ��������
        else
        {
            answer += nRightMove;
        }

        // ���� ����
        int nNext = i + 1;

        while (nNext < nNameLenth && name[nNext] == 'A')
        {
            nNext++; // ������ �̵�
        }

        // ���̽�ƽ.jpg
        nTurn = min(nTurn, i + nNameLenth - nNext + min(i, nNameLenth - nNext));
    }

    answer += nTurn;

    return answer;
}

int main()
{
    cout << solution("JEROEN") << '\n';
    cout << solution("JAN") << '\n';
    cout << solution("ABABAAAAAAABA") << '\n';   

    return 0;
}