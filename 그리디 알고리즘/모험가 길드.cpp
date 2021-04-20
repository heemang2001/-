#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

bool test(int n1, int n2)
{
	return n1 < n2;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	vector<int> Fear;
	int nValue = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int nTemp = 0;

		cin >> nTemp;

		Fear.push_back(nTemp);
	}

	// 오름차순
	sort(Fear.begin(), Fear.end());

	for (int i = 0; i < Fear.size(); i++)
	{
		if (Fear.back() > Fear.size())
		{
			Fear.erase(Fear.end() - 1);
		}
	}

	while (1)
	{
		if (Fear.back() >= Fear.size())
		{
			nValue++;
			break;
		}

		Fear.erase(Fear.begin(), Fear.begin() + (Fear.back() - 1));
		Fear.erase(Fear.end() - 1);
		nValue++;

		if (Fear.size() == 0)
		{
			break;
		}
	}

	cout << nValue << '\n';

	return 0;
}