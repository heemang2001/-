#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;

vector<int> vecWeight;

int main()
{
	int answer = 1;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int nTemp;
		cin >> nTemp;
		vecWeight.push_back(nTemp);
	}

	sort(vecWeight.begin(), vecWeight.end());

	for (int i = 0; i < N; i++)
	{
		if (answer < vecWeight[i])
		{
			break;
		}

		answer += vecWeight[i];
	}

	cout << answer << '\n';
	
	return 0;
}