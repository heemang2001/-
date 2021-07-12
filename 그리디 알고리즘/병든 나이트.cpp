#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N, M; // 1 <= N,M <= 2,000,000,000

int main()
{
	cin >> N >> M;

	int answer = 0;

	if (N == 1)
	{
		answer = 1;
	}

	else if (N == 2)
	{
		answer = min(4, (M + 1) / 2);
	}

	else if (N >= 3)
	{
		if (M <= 6)
		{
			answer = min(4, M);
		}

		else
		{
			answer = M - 2;
		}
	}

	cout << answer << '\n';

	return 0;
}