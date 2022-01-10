#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M;
int Answer;

int main()
{
	cin >> N >> M;

	vector<pair<int, float>> vecPrice_Pack;
	vector<int> vecPrice_Each;

	for (int i = 0; i < M; i++)
	{
		int price_Pack;
		int price_Each;
		float price_Pack_Average;

		cin >> price_Pack >> price_Each;

		price_Pack_Average = price_Pack / 6.0f;

		vecPrice_Pack.push_back({price_Pack, price_Pack_Average});
		vecPrice_Each.push_back(price_Each);
	}

	sort(vecPrice_Pack.begin(), vecPrice_Pack.end());
	sort(vecPrice_Each.begin(), vecPrice_Each.end());

	int minPrice_Each = vecPrice_Each.front();
	pair<int, float> minPrice_Pack = vecPrice_Pack.front();

	while (1)
	{
		if (N <= 0)
		{
			break;
		}

		if (N >= 6)
		{
			if (minPrice_Pack.second < minPrice_Each)
			{
				Answer += minPrice_Pack.first;
				N -= 6;				
			}

			else
			{
				Answer = N * minPrice_Each;
				break;
			}
		}

		else
		{
			int nTemp1 = minPrice_Pack.first;
			int nTemp2 = minPrice_Each * N;

			if (nTemp1 > nTemp2)
			{
				Answer += nTemp2;
				break;
			}

			else
			{
				Answer += nTemp1;
				break;
			}
		}
	}

	cout << Answer << '\n';

	return 0;
}