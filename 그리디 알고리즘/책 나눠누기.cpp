#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int T;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.second == p2.second)
	{
		return p1.first > p2.first;
	}

	return p1.second < p2.second;
}

int main()
{
	cin >> T;	

	for (int i = 0; i < T; i++)
	{
		int Answer = 0;
		int N;
		int M;

		cin >> N >> M;

		vector<pair<int, int>> vecTemp;
		bool bVisited[1001] = { false, };
		//memset(bVisited, false, sizeof(bVisited));

		for (int i = 0; i < M; i++)
		{
			int nTemp1;
			int nTemp2;

			cin >> nTemp1 >> nTemp2;

			vecTemp.push_back({ nTemp1,nTemp2 });
		}

		sort(vecTemp.begin(), vecTemp.end(), cmp);

		for (int i = 0; i < vecTemp.size(); i++)
		{
			for (int j = vecTemp[i].first; j <= vecTemp[i].second; j++)
			{
				if (bVisited[j] == false)
				{
					bVisited[j] = true;
					Answer++;
					break;
				}
			}
		}

		cout << Answer << '\n';
	}

	return 0;
}