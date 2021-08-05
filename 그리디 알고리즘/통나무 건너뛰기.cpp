#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int T;
int N;
vector<int> vecAnswer;

int main()
{
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> N;

		vector<int> vecTree(N);
		int answer = -1;

		for (int i = 0; i < N; i++)
		{
			int nTemp;
			cin >> nTemp;
			vecTree[i] = nTemp;
		}

		sort(vecTree.begin(), vecTree.end());

		for (int i = 0; i < vecTree.size() - 2; i++)
		{
			answer = max(answer, abs(vecTree[i] - vecTree[i + 2]));
		}

		vecAnswer.push_back(answer);
	}

	for (int i = 0; i < vecAnswer.size(); i++)
	{
		cout << vecAnswer[i] << '\n';
	}

	return 0;
}

// 시간 복잡도 문제
//int main()
//{
//	cin >> T;
//
//	for (int i = 0; i < T; i++)
//	{
//		cin >> N;
//
//		vector<int> vecTree(N);
//		vector<int> vecTemp;
//		int answer = 987654321;
//
//		for (int i = 0; i < N; i++)
//		{
//			int nTemp;
//			cin >> nTemp;
//			vecTree[i] = nTemp;
//		}
//
//		do 
//		{
//			int differ = abs(vecTree[0] - vecTree.back());			
//
//			for (int i = 0; i < N; i++)
//			{
//				int next = i + 1;
//
//				if (next >= vecTree.size())
//				{
//					break;
//				}
//
//				differ = max(differ, abs(vecTree[i] - vecTree[next]));
//			}
//
//			vecTemp.push_back(differ);
//
//		} while (next_permutation(vecTree.begin(), vecTree.end()));
//
//		answer = *min_element(vecTemp.begin(), vecTemp.end());
//
//		vecAnswer.push_back(answer);
//	}
//
//	for (int i = 0; i < vecAnswer.size(); i++)
//	{
//		cout << vecAnswer[i] << '\n';
//	}
//
//	return 0;
//}