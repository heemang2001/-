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
		// 나무 심는데 +1일
		answer = max(answer, vecTree[i] + 1 + i);
	}

	// 마지막 나무가 다 자라고 다음날 이장님 초대가능
	cout << answer + 1 << '\n';

	return 0;
}

// 시간 복잡도 문제
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