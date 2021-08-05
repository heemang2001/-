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

		//* 1 0
		//* 1 0 2
		//* 3 1 0 2
		//* 3 1 0 2 4
		//* 5 3 1 0 2 4
		//* 5 3 1 0 2 4 6
		//*          ...
		//*          작은 값부터 번갈아서 앞쪽, 뒤쪽에 붙이는 것이다
		//* (또는 큰 값부터 번갈아서 앞쪽, 뒤쪽에 붙이는 것이다)

	/* 최소 난이도를 구하려면
	 * -> 정렬된 순서 기준 인접한 원소의 인덱스 차이가 최대한 작아야함
	 * -> 인접한 원소들 간의 인덱스가 1 차이나도록 배열을 만드는 것은 불가능
	 * -> 인접한 원소들 간의 인덱스가 2 차이나도록 배열을 만드는 것은 가능
	 * -> 인접하 원소들 간의 인덱스가 3 이하로 차이나도록 배열을 만드는 것은 가능할 것 같으나,
	 *    인접한 원소들 간의 최소 인덱스 차이가 2 이상이므로 고려치 않아도 됨
	 *    => 이는, 인덱스 2 차이나는 원소들의 높이 차의 최대가 최소 난이도임을 보장함 */

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