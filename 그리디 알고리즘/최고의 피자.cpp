#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

// 최고의 피자 == 1달러당 열량이 최대가 되는 피자

int main()
{
	int answer = 0;
	int N; // 토핑 종류
	int A; // 도우가격
	int B; // 토핑가격
	int C; // 도우 칼로리

	cin >> N;
	cin >> A >> B;
	cin >> C;

	vector<int> vecToppingCal(N); // 토핑 칼로리

	for (int i = 0; i < N; i++)
	{
		int nTemp;
		cin >> nTemp;
		vecToppingCal[i] = nTemp;
	}

	sort(vecToppingCal.begin(), vecToppingCal.end(), greater<int>());

	int fTemp = C / A; // 칼로리 / 가격
	answer = fTemp;

	for (int i = 0; i < vecToppingCal.size(); i++)
	{
		int nTemp = 0;

		if (i == 0)
		{
			nTemp = vecToppingCal[i];
		}

		else if(i >= 1)
		{
			for (int j = 0; j <= i; j++)
			{
				nTemp += vecToppingCal[j];
			}
		}

		fTemp = (C + nTemp) / (A + (B * (i + 1)));
		answer = max(answer, fTemp);
	}

	cout << answer << '\n';

	return 0;
}