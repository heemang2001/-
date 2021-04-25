#include <string>
#include <vector>
#include <iostream>

using namespace std;

// A B C D E F G H I J K L M N O P Q R S T U V W X Y Z

int solution(string name)
{
    int answer = 0;

    // 문자열 길이
    int nNameLenth = name.length();      

    // 오른쪽, 왼쪽 어느 방향으로 가야지 빠른가?
    int nTurn = nNameLenth - 1; // 최대 이동횟수

    // 커서 이동
    int nMove = 0;
    
    for (int i = 0; i < nNameLenth; i++)
    {
        int nRightMove = name[i] - 'A';     // 오른쪽으로 이동시 
        int nLeftMove = 'Z' - name[i] + 1;  // 왼쪽으로 이동시( +1은 아래화살표눌러서 'Z'로 가는것 )

        // (알파벳)왼쪽으로 변환시 더 빠르면
        if (nRightMove > nLeftMove)
        {
            answer += nLeftMove;
        }

        // (알파벳)오른쪽으로 변환시 더빠르면
        else
        {
            answer += nRightMove;
        }

        // 다음 문자
        int nNext = i + 1;

        while (nNext < nNameLenth && name[nNext] == 'A')
        {
            nNext++; // 오른쪽 이동
        }

        // 조이스틱.jpg
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