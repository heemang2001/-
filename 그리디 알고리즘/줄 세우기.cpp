#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
int Answer;
int DP[1000001];

int main()
{
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int nTemp;
		cin >> nTemp;

		DP[nTemp] = DP[nTemp - 1] + 1;

		Answer = max(Answer, DP[nTemp]);
	}

	cout << N - Answer << '\n';

	return 0;
}