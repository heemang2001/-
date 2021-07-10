#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

long long S; // (1 ¡Â S ¡Â 4,294,967,295)

int main()
{
	cin >> S;
	
	long long sum = 0;
	int answer = 0;

	for (int i = 1; sum <= S; i++)
	{
		if (sum + i <= S)
		{
			sum += i;
			answer++;
		}

		else if (sum + i > S)
		{
			break;
		}
	}

	cout << answer << '\n';

	return 0;
}