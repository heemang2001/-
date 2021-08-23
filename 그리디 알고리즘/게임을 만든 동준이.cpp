#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>

using namespace std;

int N;
int answer;
vector<int> vecScore;

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int nTemp;
		cin >> nTemp;
		vecScore.push_back(nTemp);
	}

	reverse(vecScore.begin(), vecScore.end());

	int num = vecScore.front();

	if (N >= 2)
	{
		for (int i = 1; i < vecScore.size(); i++)
		{
			if (num > vecScore[i])
			{
				num = vecScore[i];
				continue;
			}

			else
			{
				int nTemp2 = (vecScore[i] - num) + 1;				
				vecScore[i] -= nTemp2;
				num = vecScore[i];
				answer += nTemp2;
			}
		}
	}

	cout << answer << '\n';

	return 0;
}