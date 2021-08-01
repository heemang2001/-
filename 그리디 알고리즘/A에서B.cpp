#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

long long A, B;
long long answer = 1;

int main()
{
	cin >> A >> B;

	while (1)
	{
		answer++;

		string sTempA = to_string(A);
		string sTempB = to_string(B);

		if (B % 2 == 0)
		{			
			B /= 2;
		}

		else if((sTempB[sTempB.size()-1] == '1') && (sTempB.size() >= 2))
		{
			sTempB.erase(sTempB.size()-1, 1);
			B = stol(sTempB);
		}

		else
		{
			answer = -1;
			break;
		}

		if (B == A)
		{			
			break;
		}

		else if (B < A)
		{
			answer = -1;
			break;
		}
	}
	
	cout << answer << '\n';
	return 0;
}