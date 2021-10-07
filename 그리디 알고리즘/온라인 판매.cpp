#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int N, M;

int main()
{
	cin >> N >> M;

	vector<int> vecPrices;
	vector<int> vecRevenue;

	for (int i = 0; i < M; i++)
	{
		int nTemp;
		cin >> nTemp;
		vecPrices.push_back(nTemp);
	}

	sort(vecPrices.begin(), vecPrices.end());

	int result = 0;
	int max = 0;
	int price = 0;

	for (int i = 0; i < M; i++)
	{
		if (M - i < N)
		{
			result = vecPrices[i] * (M - i);
		}

		else
		{
			result = vecPrices[i] * N;
		}

		if (max < result)
		{
			price = vecPrices[i];
			max = result;
		}
	}

	cout << price << '\n';
	cout << max << '\n';

	return 0;
}