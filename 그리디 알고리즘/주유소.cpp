#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
	// �׽�Ʈ
	int nCityCount;
	vector<long long> nCityInterval;
	vector<long long> nPrice;
	long long nCurPrice = LONG_MAX;
	long long nMinPrice = 0;
	
	cin >> nCityCount;

	// ���û��� �Ÿ�
	for (int i = 0; i < nCityCount - 1; i++)
	{
		int tInterval = 0;

		cin >> tInterval;

		nCityInterval.push_back(tInterval);
	}

	// �⸧��
	for (int i = 0; i < nCityCount; i++)
	{
		int tPrice = 0;

		cin >> tPrice;

		nPrice.push_back(tPrice);
	}	

	// Solution
	for (int i = 0; i < nCityCount; i++)
	{
		if (nCurPrice > nPrice[i])
		{
			nCurPrice = nPrice[i];
		}

		nMinPrice += nCurPrice * nCityInterval[i];
	}

	cout << nMinPrice;

	return 0;
}