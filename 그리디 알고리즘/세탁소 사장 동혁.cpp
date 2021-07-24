#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int T;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int nTemp;
		cin >> nTemp;
		vector<int> vecMoney(4);

		int Quarter = nTemp / 25;
		nTemp -= Quarter * 25;

		int Dime = nTemp / 10;
		nTemp -= Dime * 10;

		int Nickel = nTemp / 5;
		nTemp -= Nickel * 5;

		int Penny = nTemp;

		for (int j = 0; j < 4; j++)
		{
			switch (j)
			{
			case 0:
				vecMoney[j] = Quarter;
				break;

			case 1:
				vecMoney[j] = Dime;
				break;

			case 2:
				vecMoney[j] = Nickel;
				break;

			case 3:
				vecMoney[j] = Penny;
				break;
			}
		}

		for (int k = 0; k < 4; k++)
		{
			cout << vecMoney[k] << ' ';
		}

		cout << '\n';
	}

	return 0;
}