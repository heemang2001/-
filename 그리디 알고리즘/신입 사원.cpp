#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T; // 테스트 케이스 수
vector<int> vecAnswer;

// 시간 복잡도 문제
//int solution(vector<pair<int, int>>& vecRank)
//{
//	int answer = vecRank.size();
//
//	for (int i = 0; i < vecRank.size(); i++)
//	{
//		bool bSuccess = false;
//
//		for (int j = 0; j < vecRank.size(); j++)
//		{
//			if (i != j && vecRank[i].first > vecRank[j].first && vecRank[i].second > vecRank[j].second)
//			{
//				bSuccess = true;
//				break;
//			}
//		}
//
//		if (bSuccess)
//		{
//			answer--;
//		}
//	}
//
//	return answer;
//}

int solution(vector<pair<int, int>>& vecRank)
{
	int answer = 1;

	int nTemp = vecRank[0].second;

	for (int i = 1; i < vecRank.size(); i++)
	{
		if (vecRank[i].second < nTemp)
		{
			answer++;
			nTemp = vecRank[i].second;
		}
	}

	return answer;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		vector<pair<int, int>> vecRank;

		int N; // 지원자 수
		cin >> N;

		for (int j = 0; j < N; j++)
		{
			int nTemp1, nTemp2;
			cin >> nTemp1 >> nTemp2;

			vecRank.push_back(make_pair(nTemp1, nTemp2));
		}

		sort(vecRank.begin(), vecRank.end());

		vecAnswer.push_back(solution(vecRank));
	}

	for (int i = 0; i < vecAnswer.size(); i++)
	{
		cout << vecAnswer[i] << '\n';
	}

	return 0;
}