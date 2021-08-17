#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int N;
int answer;
vector<pair<int, int>> vecAssign;

int main()
{
	cin >> N;	

	for (int i = 0; i < N; i++)
	{
		int nTemp1;
		int nTemp2;

		cin >> nTemp1 >> nTemp2;

		vecAssign.push_back({ nTemp1,nTemp2 });
	}

	sort(vecAssign.begin(), vecAssign.end(), greater<pair<int, int>>());
	int maxDay = vecAssign.front().first;

	while (1)
	{
		int maxValue = 0;
		int index = -1;
		bool bErase = false;

		for (int i = 0; i < vecAssign.size(); i++)
		{
			if (vecAssign[i].first >= maxDay && vecAssign[i].second >= maxValue)
			{				
				maxValue = vecAssign[i].second;
				index = i;
				bErase = true;
			}
		}

		maxDay--;

		answer += maxValue;

		if (bErase)
		{
			vecAssign.erase(vecAssign.begin() + index);
		}		

		if (maxDay == 0)
		{
			break;
		}
	}

	cout << answer << '\n';

	return 0;
}