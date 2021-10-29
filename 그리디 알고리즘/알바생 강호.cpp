#include <algorithm>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int N;
long long Answer;

int main()
{
	cin >> N;

	vector<long long> vecTemp(N);

	for (int i = 0; i < N; i++)
	{
		long long nTemp;
		cin >> nTemp;
		vecTemp[i] = nTemp;
	}

	sort(vecTemp.begin(), vecTemp.end(), greater<int>());

	for (int i = 0; i < N; i++)
	{
		long long Tip = vecTemp[i] - i;

		if (Tip >= 0)
		{
			Answer += Tip;
		}		
	}

	cout << Answer << '\n';

	return 0;
}