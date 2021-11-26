#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int N, M;
int Answer;
vector<int> vecCrane;
vector<int> vecBox;
bool bVisited[10001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int nTemp;
		cin >> nTemp;
		vecCrane.push_back(nTemp);
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int nTemp;
		cin >> nTemp;
		vecBox.push_back(nTemp);
	}

	sort(vecCrane.begin(), vecCrane.end(), greater<int>());
	sort(vecBox.begin(), vecBox.end(), greater<int>());

	if (vecBox.front() > vecCrane.front())
	{
		cout << -1 << '\n';
		return 0;
	}

	while (!vecBox.empty())
	{
		Answer++;

		for (int i = 0; i < vecCrane.size(); i++)
		{
			for (int j = 0; j < vecBox.size(); j++)
			{
				if (vecCrane[i] >= vecBox[j])
				{
					vecBox.erase(vecBox.begin() + j);
					break;
				}
			}
		}
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
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		int nTemp;
//		cin >> nTemp;
//		vecCrane.push_back(nTemp);
//	}
//
//	cin >> M;
//	for (int i = 0; i < M; i++)
//	{
//		int nTemp;
//		cin >> nTemp;
//		vecBox.push_back(nTemp);
//	}
//	
//	sort(vecCrane.begin(), vecCrane.end(), greater<int>());
//	sort(vecBox.begin(), vecBox.end(), greater<int>());
//
//	int MovedBox = 0;
//
//	while (1)
//	{
//		if (MovedBox == M)
//		{
//			break;
//		}		
//
//		if (vecCrane.front() < vecBox.front())
//		{
//			Answer = -1;
//			break;
//		}
//
//		for (int i = 0; i < N; i++)
//		{
//			for (int j = 0; j < M; j++)
//			{
//				if (vecBox[j] <= vecCrane[i] && !bVisited[j])
//				{
//					bVisited[j] = true;
//					MovedBox++;
//					break;
//				}
//			}
//		}
//
//		Answer++;
//	}
//
//	cout << Answer << '\n';
//
//	return 0;
//}