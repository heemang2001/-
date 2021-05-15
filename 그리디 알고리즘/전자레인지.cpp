#include <iostream>
#include <vector>
#include <algorithm>

#define TIME_A 300
#define TIME_B 60
#define TIME_C 10

using namespace std;

int T; // 1 <= T <= 10,000

int main()
{
	int A = 0;
	int B = 0;
	int C = 0;

	cin >> T;

	if (T >= TIME_A)
	{
		A = T / TIME_A;
		T = T % TIME_A;
	}

	if (T >= TIME_B)
	{
		B = T / TIME_B;
		T = T % TIME_B;
	}

	if (T >= TIME_C)
	{
		C = T / TIME_C;
		T = T % TIME_C;
	}

	if (T != 0)
	{
		cout << -1 << '\n';
	}

	else
	{
		cout << A << " " << B << " " << C << '\n';
	}

	return 0;
}