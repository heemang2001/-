#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
int Answer;

int main()
{
	cin >> N;

	vector<int> vecTemp(N);

	for (int i = 0; i < N; i++)
	{
		int nTemp;
		cin >> nTemp;
		vecTemp[i] = nTemp;
	}

	for (int i = 0; i < N; i++)
	{
		int nTemp = 0;

		for (int j = i + 1; j < N; j++)
		{
			if (vecTemp[i] > vecTemp[j])
			{
				nTemp++;
			}

			else if(vecTemp[i] < vecTemp[j])
			{
				break;
			}
		}

		Answer = max(Answer, nTemp);
	}

	cout << Answer << '\n';

	return 0;
}