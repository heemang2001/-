#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N; // N∞≥¿« ¡Ÿ , 1 <= N <= 100,000

int main()
{
	int answer = 0;

	vector<int> vecRope;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int nTemp = 0;
		cin >> nTemp;

		vecRope.push_back(nTemp);
	}

	sort(vecRope.begin(), vecRope.end());
	
	for (int i = N; i > 0; i--)
	{
		int nTemp = vecRope[0] * i;
		vecRope.erase(vecRope.begin());
		answer = max(nTemp, answer);
	}

	cout << answer << '\n';

	return 0;
}