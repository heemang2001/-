#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

string sInput;
string Answer;

int main()
{
	cin >> sInput;	

	int cnt_P = 0;

	for (int i = 0; i < sInput.size(); i++)
	{
		// P라면 개수 증가
		if (sInput[i] == 'P')
		{
			cnt_P++;

			continue;
		}

		// 현재 A고 앞에 두개이상의 P고 뒤가 P ==> PPAP
		if (cnt_P >= 2 && sInput[i + 1] == 'P')
		{
			// PPAP를 P로
			cnt_P--;

			// 뒤에 P확인 했으므로 i++
			i++;
		}

		else
		{
			Answer = "NP";
			cout << Answer << '\n';
			return 0;
		}
	}

	// P로 끝나면 PPAP
	if (cnt_P == 1)
	{
		Answer = "PPAP";
	}

	else
	{
		Answer = "NP";
	}

	cout << Answer << '\n';

	return 0;
}

// 시간 초과
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> sInput;
//
//	for (int i = 0; i < sInput.size(); i++)
//	{
//		if (sInput[i] == 'P')
//		{
//			if (sInput.size() > 1)
//			{
//				string sTemp = "P";
//				int cnt = 3;
//				int next_index = i + 1;
//
//				while (cnt > 0)
//				{
//					sTemp += sInput[next_index++];
//
//					if (next_index >= sInput.size())
//					{
//						break;
//					}
//
//					cnt--;
//				}	
//
//				if (sTemp == "PPAP")
//				{
//					sInput.erase(i+1, 3);
//					i = -1;
//				}
//
//				else
//				{
//					Answer = "NP";					
//				}
//			}
//
//			else
//			{		
//				Answer = "PPAP";
//				break;
//			}
//		}
//
//		else
//		{
//			continue;
//		}
//	}
//
//	cout << Answer << '\n';
//
//	return 0;
//}
