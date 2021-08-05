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
		//*          ���� ������ �����Ƽ� ����, ���ʿ� ���̴� ���̴�
		//* (�Ǵ� ū ������ �����Ƽ� ����, ���ʿ� ���̴� ���̴�)

	/* �ּ� ���̵��� ���Ϸ���
	 * -> ���ĵ� ���� ���� ������ ������ �ε��� ���̰� �ִ��� �۾ƾ���
	 * -> ������ ���ҵ� ���� �ε����� 1 ���̳����� �迭�� ����� ���� �Ұ���
	 * -> ������ ���ҵ� ���� �ε����� 2 ���̳����� �迭�� ����� ���� ����
	 * -> ������ ���ҵ� ���� �ε����� 3 ���Ϸ� ���̳����� �迭�� ����� ���� ������ �� ������,
	 *    ������ ���ҵ� ���� �ּ� �ε��� ���̰� 2 �̻��̹Ƿ� ���ġ �ʾƵ� ��
	 *    => �̴�, �ε��� 2 ���̳��� ���ҵ��� ���� ���� �ִ밡 �ּ� ���̵����� ������ */

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

// �ð� ���⵵ ����
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