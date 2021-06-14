#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N;

int main()
{	
	int answer = 0;
	vector<pair<int, int>> vecCowtime;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int nTemp1, nTemp2;	// 도착시간, 검문시간

		cin >> nTemp1 >> nTemp2;

		vecCowtime.push_back({ nTemp1, nTemp2 });
	}

	sort(vecCowtime.begin(), vecCowtime.end());

	answer = vecCowtime[0].first + vecCowtime[0].second;

	for (int i = 1; i < N; i++)
	{
		if (answer < vecCowtime[i].first)
		{
			answer += vecCowtime[i].first - answer;
		}

		answer += vecCowtime[i].second;
	}

	cout << answer << '\n';

	return 0;
}