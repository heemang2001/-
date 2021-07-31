#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N;
int answer;
vector<int> vecTree;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int nTemp;
		cin >> nTemp;
		vecTree.push_back(nTemp);
	}

	sort(vecTree.begin(), vecTree.end(), greater<int>());

	for (int i = 0; i < N; i++)
	{
		// ���� �ɴµ� +1��
		answer = max(answer, vecTree[i] + 1 + i);
	}

	// ������ ������ �� �ڶ�� ������ ����� �ʴ밡��
	cout << answer + 1 << '\n';

	return 0;
}

// �ð� ���⵵ ����
//int main()
//{
//	cin >> N;
//
//	for (int i = 0; i < N; i++)
//	{
//		int nTemp;
//		cin >> nTemp;
//		vecTree.push_back(nTemp);
//	}
//
//	sort(vecTree.begin(), vecTree.end(), greater<int>());
//
//	while (1)
//	{
//		for (int i = 0; i < N; i++)
//		{
//			if (answer >= i)
//			{
//				vecTree[i]--;
//			}
//		}
//
//		answer++;
//
//		int maxValue = *max_element(vecTree.begin(), vecTree.end());
//		if (maxValue == 0)
//		{
//			break;
//		}
//	}
//
//	cout << answer << '\n';
//
//	return 0;
//}