#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> Pasta;
	vector<int> Juice;

	for (int i = 0; i < 3; i++)
	{
		int nTemp = 0;

		cin >> nTemp;

		Pasta.push_back(nTemp);
	}

	for (int i = 0; i < 2; i++)
	{
		int nTemp = 0;

		cin >> nTemp;

		Juice.push_back(nTemp);
	}

	sort(Pasta.begin(), Pasta.end());
	sort(Juice.begin(), Juice.end());

	float Price = Pasta.front() + Juice.front() + ((Pasta.front() + Juice.front()) * 0.1f);
		
	cout << fixed;
	cout.precision(1);
	cout << Price;

	return 0;
}